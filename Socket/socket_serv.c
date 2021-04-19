#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>

//gcc socket_serv.c -o socket_serv -lws2_32;

static void init(void)
{
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if(err < 0)
    {
        puts("WSAStartup failed !");
        exit(EXIT_FAILURE);
    }
#endif
}

static void end(void)
{
#ifdef WIN32
    WSACleanup();
#endif
}

int main(){
  init();
  int sinsize;
  char message_cli[256];
  int mc = 256;
  int quitter = 0;
  int nb = 0;

//création du socket(serveur)
  SOCKET  sock_serv = socket(AF_INET, SOCK_STREAM, 0);
  if(sock_serv == INVALID_SOCKET){
    perror("socket()");
    exit(errno);
  }

//création du serveur
  SOCKADDR_IN serveur;
  serveur.sin_addr.s_addr = htonl(INADDR_ANY);
  serveur.sin_family = AF_INET;
  serveur.sin_port = htons(20000);

//création socket(client)
  SOCKET sock_cli;

//création interface(client)
  SOCKADDR_IN client;

//liaison socket et serveur
  bind(sock_serv, (SOCKADDR *)&serveur, sizeof(serveur));

//port à écouter + nb connexions dispo
  listen(sock_serv, 4);
  printf("\nEn attente de connexion...\n");

  sinsize  = sizeof(client);
  sock_cli = accept(sock_serv, (SOCKADDR *)&client, &sinsize);

  // affiche les infos du client
  printf("Connection from %s:%d accepted\n",inet_ntoa(client.sin_addr), ntohs(client.sin_port));

  //envoie d'un message de bienvenue au client
  if(send(sock_cli, "Hello world!\0", 12, 0) <0){
    printf("[serveur] Erreur envoie mess bienvenue\n");
    exit(errno);
  }
  printf("[serveur] Message envoye\n");


// attente de la suite de la discussion
  while(!quitter){

    //reception message client :

    if(  (nb=recv(sock_cli, message_cli, 256-1, 0) ) < 0){
      printf("[serveur] Erreur de réception d'un message du client \n");
      exit(errno);

    }else{
      if(nb>0)
      {
        message_cli[nb]='\0';
        printf("[serveur] Message recu :\n %s \nfin message reçu\n", message_cli);


        if(strcmp(message_cli,"QUITTER\0")==0 ){
          printf("Au revoir billy\n");
          closesocket(sock_cli);
          quitter = 1;
        }
      }
    }
  }

  closesocket(sock_serv);
  closesocket(sock_cli);
  end();
  return 0;
}
