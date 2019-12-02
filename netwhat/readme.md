# Netwhat notes
*This is the notes I made for the **Netwhat** project. If you find any mistakes please be free to correct me.


## TCP/IP Networking

The most common network stack today is the *Transmission Control Protocol Internet Protocol (TCP/IP)* stack, and it's components are:  

- network hardware
- data packets
- protocols for data exchange

### Network Hardware

**Types**  
The most common is Ethernet. Most servers use *twisted-pair cabling*, if is identified by a *T* suffix to the Ethernet variety name, as in 10BaseT or 100BaseT (the numbers denote the speed of the protocol in megabits per second --- Mbps).  
Other types of network hardware include: Token Ring, LocakTalk, Fiber Distributed Data Interface (FDDI), High-Performance Parallel Interface (HIPPI), and Fiber Channel.  
Wireless networking (aka Wi-Fi) os am exception to Ethernet's dominance. Common wireless protocol include 802.11a (54Mbps), 802.11b (11Mbps), 802.11g (54Mbps) and 802.11n (300Mbps). With the exception of the rarely used 802.11a, Wi-Fi protocols are compatible with on another, albeit at the speed of the slowest protocol in use.  
Many network types require the use of a central device known as a **hub** or **switch**.  You plug every computer on a local network into this central device, and it then passes data between the computers. As a general rule, switches are superior to hubs. Hubs mirror all traffic to all computers, whereas switches are smart enough to send packets only to the intended destination. Switches also allow *full-duplex transmission*, in which both parties can send data ant the same time. Hubs permit only *half-duplex transmission*, in which the two computers must take turns.  
Computers with Wi-Fi adapters can be configured to communicate directly with one another, but it's more common to employ a wireless access point, which licks together both wireless and Ethernet devices.

![Network devices](./Network_devices.jpg)

**Network Packets**  
Modern networks operate on discrete chunks of data known as *packets*. There are several types of packets and they can be stored within each other. For instance, Ethernet includes its own packet type -- known as a *frame*.  
A data transfer can involve several layers of wrapping and unwrapping data. With each layer, packets from the adjacent layer may be merged or split up.

## IP address



## Netmask

A **netmask** is a 32-bit "mask" used to divide an IP address into subnets and specify the networks available hosts.   

## subnet of an IP with Netmask

## broadcast address of a subnet

## different way to represent an IP address with the Netmask

## difference between public and private IPs

## class of IP address

**TABLE** IPv4 network classes and private net work ranges  

| Class | Address range                 | Reserved private addresses       |
|-------|:-----------------------------:|:--------------------------------:|
| A     | 1.0.0.0    -  127.255.255.255 | 10.0.0.0      -  10.255.255.255  |
| B     | 128.0.0.0  -  191.255.255.255 | 172.16.0.0    -  172.31.255.255  |
| C     | 192.0.0.0  -  233.255.255.255 | 192.168.0.0   -  192.168.255.255 |
| D     | 224.0.0.0  -  239.255.255.255 | none                             |
| E     | 240.0.0.0  -  255.255.255.255 | none                             |

## TCP && UDP

## network layers

## OSI model

## DHCP server and the DHCP protocol

## DNS server and the DNS protocol

## rules to make 2 devices communicate using IP addresses

## how routing is working with IP

## default gateway for routing

## what is a port from an IP point of view and what is it used for when connecting to an other device
