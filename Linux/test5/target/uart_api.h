#ifndef		UART_API_H
#define		UART_API_H

#define		GNR_COM			0
#define		USB_COM			1
#define 	COM_TYPE		GNR_COM
#define 	MAX_COM_NUM		3
#define		HOST_COM_PORT		1
#define		TARGET_COM_PORT		2
#define 	BUFFER_SIZE		1024
#define		TIME_DELAY		180
#define		SEL_FILE_NUM		2
#define     	RECV_FILE_NAME      	"recv.dat"

int open_port(int com_port);
int set_com_config(int fd,int baud_rate, int data_bits, char parity, int stop_bits);

#endif /* UART_API_H */

