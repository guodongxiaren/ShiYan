#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include "uart_api.h"

/*打开串口函数*/
int open_port(int com_port)
{
	int fd;

#if (COM_TYPE == GNR_COM)
	char *dev[] = {"/dev/ttyS0", "/dev/ttyS1", "/dev/ttyS2"};
#else
	char *dev[] = {"/dev/ttyUSB0", "/dev/ttyUSB1", "/dev/ttyUSB2"};
#endif
	
	if ((com_port < 0) || (com_port > MAX_COM_NUM))
	{
		return -1;
	}

	fd = open(dev[com_port - 1], O_RDWR|O_NOCTTY|O_NDELAY);
		
	if (fd < 0)
	{
			perror("open serial port");
			return(-1);
	}
	
	/*恢复串口为阻塞状态*/
	if (fcntl(fd, F_SETFL, 0) < 0)
	{
		perror("fcntl F_SETFL\n");
	}
	
	/*测试是否为终端设备*/
	if (isatty(STDIN_FILENO) == 0)
	{
		perror("standard input is not a terminal device");
	}
	
	return fd;
}

int set_com_config(int fd,int baud_rate, int data_bits, char parity, int stop_bits)
{
	struct termios new_cfg,old_cfg;
	int speed;

	/*保存测试现有串口参数设置，在这里如果串口号等出错，会有相关的出错信息*/
	if  (tcgetattr(fd, &old_cfg)  !=  0) 
	{
		perror("tcgetattr");
		return -1;
	}
	
	/*步骤一，设置字符大小*/
	new_cfg = old_cfg;
	cfmakeraw(&new_cfg);
	new_cfg.c_cflag &= ~CSIZE; 

	
  	/*设置波特率*/
  	switch (baud_rate)
  	{
  		case 2400:
		{
			speed = B2400;
		}
		break;

  		case 4800:
		{
			speed = B4800;
		}
		break;

  		case 9600:
		{
			speed = B9600;
		}
		break;
  		
		case 19200:
		{
			speed = B19200;
		}
		break;

  		case 38400:
		{
			speed = B38400;
		}
		break;
		
		default:
		case 115200:
		{
			speed = B115200;
		}
		break;
  	}
	cfsetispeed(&new_cfg, speed);
	cfsetospeed(&new_cfg, speed);

	/*设置停止位*/
	switch (data_bits)
	{
		case 7:
		{
			new_cfg.c_cflag |= CS7;
		}
		break;
		
		default:
		case 8:
		{
			new_cfg.c_cflag |= CS8;
		}
		break;
  	}
  	
  	/*设置奇偶校验位*/
  	switch (parity)
  	{
		default:
		case 'n':
		case 'N':
		{
			new_cfg.c_cflag &= ~PARENB;   
			new_cfg.c_iflag &= ~INPCK;    
		}
		break;

		case 'o':
		case 'O':
		{
			new_cfg.c_cflag |= (PARODD | PARENB); 
			new_cfg.c_iflag |= INPCK;            
		}
		break;

		case 'e':
		case 'E':
		{
			new_cfg.c_cflag |= PARENB;     
			new_cfg.c_cflag &= ~PARODD;   
			new_cfg.c_iflag |= INPCK;     
		}
		break;
		
		case 's':  /*as no parity*/
		case 'S':
		{
			new_cfg.c_cflag &= ~PARENB;
			new_cfg.c_cflag &= ~CSTOPB;
		}
		break;
	}
		
	/*设置停止位*/
	switch (stop_bits)
	{
		default:
		case 1:
		{
			new_cfg.c_cflag &=  ~CSTOPB;
		}
		break;

		case 2:
		{
			new_cfg.c_cflag |= CSTOPB;
		}
	}
	
	/*设置等待时间和最小接收字符*/
	new_cfg.c_cc[VTIME]  = 0;
	new_cfg.c_cc[VMIN] = 1;
	
	/*处理未接收字符*/
	tcflush(fd, TCIFLUSH);
	
	/*激活新配置*/
	if((tcsetattr(fd, TCSANOW, &new_cfg)) != 0)
	{
		perror("tcsetattr");
		return -1;
	}
	
	return 0;
}
