### Application Delivery Controllers (ADC)
 - network based load balancing is the foundation upon which ADCs operate
 - Provide key network and application functions such as:
   - load balancing
   - encryption
   - acceleration
   - security
 - 2 types of load balancers:
   - Physical or virtual appliances functioning as proxies for physical servers
   - Virtual: software-delivered intended to run on hypervisors

#### Physical: load balancing hardware
 - application-neutral
 - resided outside of the application servers themselves
 - used straightforward network techniques
 - would present a virtual IP address to the outside world, and when users attempt to connect, they would forward the connection to the most appropriate real server by doing bi-directional network address translation (NAT)

#### Virtual: software-delivered intended to run on hypervisors
 - node, server:
   - the idea of the physical or virtual server itself that will receive traffic from the ADC
   - This is synonymous with the IP address of the physical server, and in the absence of a load balancer would be the IP address that the server name (for example, www.example.com) would resolve to
 - host, member, service:
   - the TCP port of the actual application that will be receiving traffic
   - the member includes the definition of the application port as well as the IP address of the physical/virtual server

#### Virtual server
 - A virtual server is a proxy of the actual server (physical, virtual, or container)
 - Combined with a virtual IP address, this is the application endpoint that is presented to the outside world
 - Each virtual server points to a cluster of services that reside on one or more physical hosts

### The basic application delivery transaction is as follows:
 - The client attempts to connect with the service
 - The ADC accepts the connection, and after deciding which host should receive the connection, changes the destination IP (and possibly port) to match the service of the selected host (note that the source IP of the client is not touched)
 - The host accepts the connection and responds back to the original source, the client, via its default route, the ADC
 - The ADC intercepts the return packet from the host and now changes the source IP (and possible port) to match the virtual server IP and port, and forwards the packet back to the client
 - The client receives the return packet, believing that it came from the virtual server, and continues the process

### Health monitoring:
 - ping the host
 - to make sure host is working, devices do service pings, ranging from simple TCP connections all the way to interacting with the application via a scripted or intelligent interaction

### How does the load balancing ADC decide which host to send the connection
 - Once the connection is established, the ADC must keep track of whether the following traffic from that user should be load balanced
 - There are generally two specific issues with handling follow-on traffic once it has been load balanced:
   - Connection maintenance
   - Persistence

### Load balancing ADC if selected host is not working
 - health monitoring to detect if the host is up before sending it traffic
 - least connections, dynamic ratio, simple round robin, current-connection counts, host utilization, repsonse times

#### Connection maintenance
 - 

#### Persistence
 - 
 SSL session IDs and cookies

