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
![Network devices](./image/Network_devices.jpg)

**Network Packets**  
Modern networks operate on discrete chunks of data known as *packets*. There are several types of packets and they can be stored within each other. For instance, Ethernet includes its own packet type -- known as a *frame*.  
A data transfer can involve several layers of wrapping and unwrapping data. With each layer, packets from the adjacent layer may be merged or split up.

**Network Protocol Stacks**  
A *protocol stack* is a set of software that converts and encapsulates data between layers of abstraction.There are several layers to any protocol stack, and they interact in highly specified ways. It's often possible to swap out one component for another at any given layer.
![information travels though protocol stacks](./image/protocol_stacks.png)

## Network Addressing

**Types:**  

- network hardware addresses
- numeric IP addresses
- test-based hostnames

### Addressing Hardware

Dedicated network hardware have unique hardware addresses, also known as *Media Access Control (MAC) addresses* programmed into them. In the case of Ethernet, these addresses are 6 bytes in length, and they're generally expressed as hexadecimal (base 16) numbers separated by colons.  
To find the hardware address, type **ifconfig eth***n*, where *n* is the number of the interface (0 for the first card, 1 for the second, and so on). *Note:* wireless devices have names of the form **wlan***n*.

### IP address

**IP**  
The *Internet Protocol(IP)* is an Internet-layer (aka a network-layer ot layer 2) protocol.

**IPv4**  
IPv4 uses 32-bit addresses, but IPv6 uses 128-bit addresses.   

**IPv6**  
IPv6 (IP version 6) is the update to the original IP stack. It includes a new feature known as *stateless address auto-configuration(SLAAC)*.
The 4-byte IPv4 address and 6-byte Ethernet address are mathematically unrelated. 


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

### ICMP

The *Internet Control Message Protocol (ICMP)* is a simple protocol for communicating data. ICMP is most often used to send error messages between computers. This is often done by modifying an IP packet and returning it to its sender, which means that ICMP is technically an Internet-layer protocol, although it relies upon IP.

### UCP

The *User DAtagram Protocol (UDP)* is the simplest of the common transport-layer (aka layer 3) TCP/IP protocols. It doesn't provide sophisticated procedures to correct for out-of-order packets, guarantee delivery, or otherwise improve the limitations of IP. It also means that UDP can be faster than more sophisticated tools that provide such improvements to IP. Common application-layer protocols that are built atop UDP include the Domain Name System (DSN), the Network File System (NFS), and many streaming-media protocols.

### TCP
The *Transmission Control Protocol (TCP)* creates full connections with error checking and correction as well as other features. These features simplify the creations of network protocols that must exchange large amounts of data. However TCP imposes a samall performance penalty. Most application-layer protocols are built atop TCP, for example: Simple Mail Transfer Protocol (SMAP), the Hypertext Transfer PRotocol (HTTP), and the File Transfer Protocol (FTP).

## network layers

## OSI model

## DHCP server and the DHCP protocol

The *Dynamic Host Configuration Protocol (DHCP)* is a means of automating the configuration of specific computers. It has an option that uses the hardware address to assign the same IP address consistently to a given computer.

## DNS server and the DNS protocol

## rules to make 2 devices communicate using IP addresses

## how routing is working with IP

## default gateway for routing

## what is a port from an IP point of view and what is it used for when connecting to an other device
