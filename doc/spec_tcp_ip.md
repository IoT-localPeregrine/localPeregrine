# Спецификация сетевого протокола приложения **(TCP/IP)**

*Тут представлена выжимка из спецификация для понимания предметной области разработчику высокоуровневого модуля

## Терминология

- Сервент - хост в локальной сети, имплементирующей протокол, который служит и сервером и клиентом.
- Дескриптор - Название сообщений, которыми обмениваются сервенты

...

## Descriptor header

![](/doc/images/Descriptor_Header.jpeg)

| Поле               | Значение                                                                                  |
|--------------------|-------------------------------------------------------------------------------------------|
| Descriptor ID      | 16-байтовая строка уникально идентифицирующая дескриптор                                  |
| Payload Descriptor |  0x00 - Ping; 0x01 - Pong; 0x40 - Push; 0x80 - Query; 0x81 - QueryHit                     |
| TTL                | Кол-во хопов, которые допустимы в текущей конфигурации протокола. Декремент на каждый хоп |
| Hops               | Кол-во совершенных хопов. Инкремент на каждый хоп                                         |
| Payload Length     | Длина тела дескриптора                                                                    |

## Descriptor payload

### Ping **(0x00)**

Операция Ping используется для исследования сети сервентом. 

Тела дескриптора нет

*Рекомендуется минимизировать траффик Ping дескрипторов*

### Pong **(0x01)**

Когда сервент получает Ping дескриптор он может ответить Pong дескриптором

Он содержит:
- Адрес хоста в локальной сети
- Кол-во данных которые шарит сервент по сети

**Это валидно отправлять несколько Pong дескрипторов в ответ на один Ping дескриптор, это происходит в случае кэша конфигураций других сервентов**

![](/doc/images/Pong.jpeg)

| Поле                       | Значение                                                  |
|----------------------------|-----------------------------------------------------------|
| Port                       | Порт на котором сервент может принимать подключения       |
| IP Address                 | IP адрес отправителя                                      |
| Number of Files Shared     | Кол-во файлов, которые шарит сервент отправитель          |
| Number of Kilobytes Shared | Кол-во килобайт данных, которые шарит сервент отправитель |

### Query **(0x80)**

Дескриптор с запросом файлов по заданному критерию по сети

![](/doc/images/Query.jpeg)

| Поле            | Значение                                                                                        |
|-----------------|-------------------------------------------------------------------------------------------------|
| Minimum Speed   | Минимальная скорость, которую должен поддерживать сервент для общения с запрашивающим сервентом |
| Search Criteria | NULL-терминированная строка                                                                     |

### QueryHit **(0x81)**

QueryHit отправляется только в случае ответа на Query запрос. Сервент направляет ответ в случае если Query Criteria попал.

**Descriptor ID должен совпадать с ID Query, на который отвечает сервент. Это нужно для идентификации ответа**

![](/doc/images/QueryHit.jpeg)

| Поле               | Значение                                         |
|--------------------|--------------------------------------------------|
| Number of Hits     | Кол-во найденных записей по запросу              |
| Port               | Порт на котором отправитель слушает обращения    |
| IP Address         | IP адрес отправителя                             |
| Speed              | Скорость, которую может поддерживать отправитель |
| Result Set         |  ![](/doc/images/QueryHit_ResultSet.jpeg)                  |
| Servent Identifier | Уникальный идентификатор сервента в сети         |

### Push **(0x40)**

Сервент может отправить Push дескриптор если он получает QueryHit дескриптор от сервента, **который не поддерживает входящих подключений**. Это может происходить из-за firewall

Когда сервент получает Push дескриптор он может действовать, если идентификатор в теле Push соответствует идентификатору сервента

![](/doc/images/Push.jpeg)

| Поле               | Значение                                                                                  |
|--------------------|-------------------------------------------------------------------------------------------|
| Servent Identifier | Уникальный идентификатор сервента в сети. Получается посредством передачи в теле QueryHit |
| File Index         | Идентификатор файла, который должен быть получен. Получается в ResultSet в теле QueryHit  |
| IP Address         | IP Address на который должен быть отправлен запрашиваемый файл                            |
| Port               | Port на который должен быть отправлен запрашиваемый файл                                  |

## Правила маршрутизации

1. Pong дескриптор должен **пройти по пути** Ping дескриптора. Если мы видим Pong дескриптор с ID = n, но не видели Ping дескриптор с ID = n. То следует **немедленно удалить дескриптор**
   
2. QueryHit дескриптор должен **пройти по пути** Query дескриптора. Если мы видим QueryHit дескриптор с ID = n, но не видели Query дескриптор с ID = n. То следует **немедленно удалить дескриптор**
   
3. Push дескриптор должен **пройти по пути** QueryHit дескриптора. ~~Если мы видим Push дескриптор с ID = n, но не видели QueryHit дескриптор с ID = n. То следует **немедленно удалить дескриптор**~~. Если мы видим Push дескриптор с Servent_Identifier = n, но не видели QueryHit дескриптор с Servent_Identifier = n. То следует **немедленно удалить дескриптор**

4. Сервент обязан переправлять входящие Ping и Query дескрипторы во все подключенные сервенты, за исключением отправителя

5. Для каждого пришедшего декрипторы мы должны уменьшить на 1 TTL и увеличить на 1 Hops. Если TTL равен 0, то больше не отправляем никуда

6. Если встречаем Descriptor ID и Descriptor Payload идентичные второй раз, то не отправляем их, чтобы не допустить дупликации. **Есть идея обмазать уровень кэшами, на какое-то кол-во времени**

## Загрузка файла

Когда сервент получил QueryHit, то он может инициализировать скачивание одного из файлов из ResultSet

**Для передачи устанавливается прямое соединение между источником и получателем через HTTP/1.0**

![](/doc/images/Download_Workflow.jpg)












