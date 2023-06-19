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
    std::vector<Address> exploreNetwork();
}
```