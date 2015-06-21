#include <netinet/in.h>      
#include <sys/types.h>      
#include <sys/socket.h>      
#include <stdio.h>          
#include <stdlib.h>         
#include <string.h>         
  
#define HELLO_WORLD_SERVER_PORT    12345  
#define LENGTH_OF_LISTEN_QUEUE 20  
#define BUFFER_SIZE 1024  
  
int main(int argc, char **argv)  
{  
    struct sockaddr_in server_addr;  
    int server_socket;  
    int opt = 1;  
     
    bzero(&server_addr,sizeof(server_addr));   
      
    server_addr.sin_family = AF_INET;  
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);  
    server_addr.sin_port = htons(HELLO_WORLD_SERVER_PORT);  
  
    /* create a socket */  
    server_socket = socket(PF_INET,SOCK_STREAM,0);  
    if( server_socket < 0)  
    {  
        printf("Create Socket Failed!");  
        exit(1);  
    }  
   
    /* bind socket to a specified address*/  
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));  
    if( bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr)))  
    {  
        printf("Server Bind Port : %d Failed!", HELLO_WORLD_SERVER_PORT);   
        exit(1);  
    }  
  
    /* listen a socket */  
    if(listen(server_socket, LENGTH_OF_LISTEN_QUEUE))  
    {  
        printf("Server Listen Failed!");   
        exit(1);  
    }  
      
    /* run server */  
    while (1)   
    {  
        struct sockaddr_in client_addr;  
        int client_socket;
        int ret=0;        
        socklen_t length;  
        char buffer[BUFFER_SIZE]; 
        char sendbuffer[BUFFER_SIZE]; 
  
        /* accept socket from client */  
        length = sizeof(client_addr);  
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &length);  
        if( client_socket < 0)  
        {  
            printf("Server Accept Failed!\n");  
            break;  
        }  
        else
        {
            printf("client port:%d\n",client_addr.sin_port);
            printf("client ip:%s\n",inet_ntoa(client_addr.sin_addr));
        }
        /* receive data from client */  
        while(1)  
        {  
            bzero(buffer, BUFFER_SIZE);
            bzero(sendbuffer, BUFFER_SIZE);  
            length = recv(client_socket, buffer, BUFFER_SIZE, 0);  
            if (length < 0)  
            {  
                printf("Server Recieve Data Failed!\n");  
                break;  
            }  
            
            if('q' == buffer[0])  
            {  
                printf("Quit from client!\n");  
                break;  
            }  
              
            printf("%s\n", buffer); 

            scanf("%s",sendbuffer);
            ret=send(client_socket,sendbuffer,(int)strlen(sendbuffer),0);
            if(ret==-1)//if(ret==SOCKET_ERROR)
            {
            printf("Send Info Error");
            break;
            }

        }     
          
        close(client_socket);  
    }  
      
    close(server_socket);  
    return 0;  
}  

