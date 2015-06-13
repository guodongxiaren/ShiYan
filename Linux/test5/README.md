串口实验
========
我是在Windows上模拟的。在virtualbox虚拟机中使用到了两个Linux系统。  
- 首先用VSPD软件新建两个虚拟串口：com1和com2
- 虚拟机Linux系统设置串口，一个设置COM1，一个设置COM2。文件位置就写对应的com1/com2
- 在两个Linux系统中，分别编译运行两个程序：com_host和com_target。

