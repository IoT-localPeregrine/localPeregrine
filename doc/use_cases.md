# Топик планирования use-cases для оформления требований к сетевому протоколу

## Вхождение в сеть

- Сервент отправляет Connect на один из серверов в сети localPeregrine
- Участник сети отправляет Ok дескриптор

Добавления в интерфейс библиотеки:
```C++
struct INet {
    bool ConnectToNetwork(std::string network_name);
}
```

## Исследование сети

- Сервент отправляет Ping дескриптор
- Сервенты соседи отправляют Pong 
- Сервенты переправляют Ping на сервенты-соседи

Добавить иерархию Address:
```C++
struct Address {
    virtual std::string serialize() = 0;
}

struct TCPAddress: public Address {
    uint8_t[4] address_;

    virtual std::string serialize() { /*impl*/ }
}

struct BAddress: public Address {
    uint16_t[6] address_;

    virtual std::string serialize() { /*impl*/ }
}
```

Добавить абстракцию для информации по peer:
```C++
struct Peer {
    Address address;
    uint32_t number_of_files_shd;
    uint32_t number_of_kb_shd;
}
```

Добавления в интерфейс библиотеки:
```C++
struct INet {
    bool ConnectToNetwork(std::string network_name);
    void Ping(std::list<Address> peers);
    void SubscribePong(function<Peer> peer_consumer_func);
}
```

Расширить интерфейс модуля:
```C++
struct Network {
    bool ConnectToNetwork(std::string network_name);
private:
    list<string> ExploreNetworks();
    list<Peer> GetPeers();
}
```

## Нахождение файла

Добавить иерархию информации о файле:
```C++
using Query = string;

struct File {
    uint32_t index;
    uint32_t size;
    string name;
}

struct QueryHit {
    Address address;
    list<File> file;
}
```

Добавления в интерфейс библиотеки:
```C++
struct INet {
    bool ConnectToNetwork(std::string network_name);
    void Ping(Address peers);
    void SubscribePing(function<void> ping_consumer_func);
    void Pong(Peer cur_peer);
    void SubscribePong(function<void(Peer)> peer_consumer_func);
    void Query(string criteria);
    void SubscribeQuery(function<void(string)> query_consumer_func);
    void QueryHit(QueryHit query_hit);
    void SubscribeQueryHit(function<void(QueryHit)> peer_consumer_func);
}
```

Расширить интерфейс модуля:
```C++
struct Network {
    Peer peer_;

public:
    bool ConnectToNetwork(std::string network_name);

private:
    list<string> ExploreNetworks();
    list<Peer> GetPeers();
}
```


