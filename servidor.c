#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <winsock.h>
#include <conio.h>

int player = 0;
int ip = 0;

DWORD WINAPI receive_cmds(LPVOID);  

int main()
{
 
 DWORD thread;
  
 WSADATA data;
 SOCKET winsock;
 SOCKADDR_IN sock;

 printf("servidor multi-threaded connectado\n\n"); 
 
 if((WSAStartup(0x101, &data)) == SOCKET_ERROR)
 {
  printf("\nerro ao iniciar socket");
  getch();
  exit(1);
 }
 
 
 sock.sin_family = AF_INET; 
 sock.sin_addr.s_addr = INADDR_ANY; 
 sock.sin_port=htons(4000);
  
 if((winsock = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
 {
     printf("\nerro ao criar socket");
     getch();
     exit(1);
 }
  
 if(bind(winsock,(SOCKADDR*)&sock,sizeof(sock)) == SOCKET_ERROR)
 {
     printf("\nerro ao acessar rede");
     getch();
     exit(1);
 }
  
 if(listen(winsock, 5) != 0)
 {
    printf("\nerro ao criar lista de socket");
    getch();
	exit(1);
 }
 
 SOCKET client;
 
 SOCKADDR_IN from;
 int fromlen = sizeof(from); 
  
 while(true)
 { 
  client = accept(winsock,(struct sockaddr*)&from, &fromlen);
  
  ip = (int)inet_ntoa(from.sin_addr);
  printf("ip: %s\n", ip);
  
  CreateThread(NULL, 0, receive_cmds, (LPVOID)client, 0, &thread);  
 }
 
 closesocket(winsock); 
 WSACleanup(); 

 return 0;
}

DWORD WINAPI receive_cmds(LPVOID lpParam) 
{
  SOCKET current_client = (SOCKET)lpParam; 
 
  char recebe[1024];
  char enviar[1024];
  
  int byte;
  
  player++;
  printf("client connectado\r\n");
  printf("%d player online\n\n", player);
  
  while(true)
  {
   memset(recebe, 0, 1024);
   byte = recv(current_client, recebe, 1024, 0);
   
   if(byte == -1)
   {
    player--;
    printf("player %s desconectado\n", ip);
    printf("%d player online\n\n", player);
    break;
   }
  } 
   
  closesocket(current_client);
} 
