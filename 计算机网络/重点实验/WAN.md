广域网综合实验
===========
##拓扑图
![](../images/WAN-DHCP.gif)
>我的路由器叫做A、B。两个路由器的FastEthernet端口的ip，我设做了192.168.8.1和192.168.9.1

##配置命令
###基本配置
```
A〉en
A#conf  t
A(config)int s2/0
A(config-if)ip address 10.1.1.1  255.255.255.0
A(config-if)no shutdown
A(config-if)int f0/0 
A(config-if)ip address 192.168.1.1  255.255.255.0
A(config-if)no shutdown
A(config-if)end

B〉en
B#conf  t
B(config)int s2/0
B(config-if)ip address 10.1.1.2  255.255.255.0
B(config-if)no shutdown
B(config-if)int f0/0
B(config-if)ip address 192.168.2.1  255.255.255.0
B(config-if)no shutdown
B(config-if)end
（以上配置三个实验相同）
```
###RIP协议配置过程
```
A#conf  t
A(config)router rip
A(config-router)version 2
A(config-router)network 10.1.1.0
A(config-router)network 192.168.8.0
A(config-router)end

B#conf  t
B(config)router rip
B(config-router)version 2
B(config-router)network 10.1.1.0
B(config-router)network 192.168.9.0
```
###OSPF协议配置过程
```
A#conf  t
A(config)router ospf 100
A(config-router)network 10.1.1.0  255.255.255.0 area 0
A(config-router)network 192.168.8.0  255.255.255.0 area 0
A(config-router)end


B#conf  t
B(config)router ospf 100
B(config-router)network 10.1.1.0  255.255.255.0  area 0
B(config-router)network 192.168.9.0  255.255.255.0  area 0
```
###EIGRP协议配置过程
```
A#conf  t
A(config)router eigrp  200
A(config-router)network 10.1.1.0
A(config-router)network 192.168.8.0
A(config-router)end

B#conf  t
B(config)router eigrp 200
B(config-router)network 10.1.1.0
B(config-router)network 192.168.9.0
```
