输入/输出系统组织
===========

##输入/输出控制方式
|输入/输出控制方式|输入/输出过程控制|数据传输通道|CPU效率|适用场合
|:----:|:---:|:---:|---:|---:|
|程序控制方式|软件实现|经CPU|低|单用户单道程序环境
|中断控制方式|软、硬件结合实现|经CPU|一般|多用户多道程序环境下慢速或速度不确定的设备
|DMA控制方式|硬件实现|不经CPU|高|成组、高速设备
|通道控制方式|软、硬实现|不经CPU|高|大型计算机系统