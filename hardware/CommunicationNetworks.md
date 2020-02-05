Communication Networks
======================

Internet / Protocol
    Network edge - hosts, access net
    Network core - packet/circuit switching, internet structure
    Performance - loss, delay, throughput
    Protocol layers
    service models

Protocols: control sending / receiving of messages
- TCP, IP, Http, Skype, 802.11

Network edges: hosts (clients, and servers), access net

Network core:
- interconnected routers
- network of routers

Other
    Http
    DNS
    Sockets / Ports
    Congestion Control / Flow Control / TCP
    Routing / Basic Graphs / Dijakstra's algo / IP
    CSMA / TDMA / token

Wireless networks
    wifi / ad hoc / mesh
    cellular networks / mobile networks / Satellite networks

Security
    RSA

Sensor networks

 -----------------------------------------------------------------------------------------------------------------------
| TCP/IP         | OSI Model    |                   |                                                                   |
|-------------------------------|-------------------|-------------------------------------------------------------------|
| Application    | Application  | Data              | High level APIs, remote file access                               |
|                | Presentation | Data              | Encrypt/Decrypt, data compression                                 |
|                | Session      | Data              | Continuous exchange of info                                       |
|                |              |                   |                                                                   |
| Host to host   | Transport    | Segment, Datagram | Acks, TCP, UDP                                                    |
|                |              |                   |                                                                   |
| Internet       | Network      | Packet            | Routing, Traffic control                                          |
|                |              |                   |                                                                   |
| Network Access | Data Link    | Frame             | Reliable transmission between 2 nodes connected by physical layer |
|                | Physical     | Hardware          | Transmission of raw bit streams over a physical medium            |
|-------------------------------|-------------------|-------------------------------------------------------------------|

# DNS
                                               |------------------|
                |----------------------------> | Root Name Server | --------------------------------------------|
                |                              |------------------|                                             |
                |                               Return ip address to RNS                                        |
                |                               If unknown, ask TLD name server and cache it                    |
                |                                                                                               V
         |-------------| check if cache and return value                                        |------------------------------|
         | Resolving   | Also known as work horse of DNS lookup                                 | Top level domain name server |
         | Name Server | The only thing RNS should know is                                      | com name server              |
         |-------------| where to find the root                                                 |------------------------------|
              ^     ^    Once Root returns val, cache it and return to browser                          | TLD knows about ANS by the domain's registrar,
              |     |----------------------------------------------|                                    | which tells TLD where to find ANS
              |                                                    |                                    V
    |-------------------|   OS caches it, & gives it to browser    | tell RNS to go to 1.2.3.4  |----------------------------|
    | Personal computer | <---------------------|                  |--------------------------- | Authoritative name server  |
    |-------------------|                       |---------------------------------------------- | example.com name server    |
 Browser and OS try to determine IP address from configuration, and cache                       |----------------------------|
 OS is configured to ask a `Resolving Name Server` if domain/IP is unknown

 ===
