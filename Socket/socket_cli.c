#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//gcc socket_cli.c -o socket_cli -lws2_32;

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
int main(int argc, char **argv){
  init();
  char message[256];
  char serveur_rep[256];
  char choix;
  int taille;
  struct hostent * server=NULL;

  if(argc < 2){
    printf("usage %s hostname \n", argv[0]);
    exit(errno);
  }
//creation socket(client)
  SOCKET sock_cli = socket(AF_INET, SOCK_STREAM, 0);
  if(sock_cli == INVALID_SOCKET){
    perror("socket()");
    exit(errno);
  }

//creation socket(serveur)
  SOCKET sock_serv;

//récupération de l'adresse du serveur distant
  server = gethostbyname(argv[1]);
  if(server == NULL){
    printf("le serveur n'existe pas\n");
    exit(errno);
  }

//création de l'interface(serveur)
  SOCKADDR_IN server_addr = { 0 };
  server_addr.sin_addr = *(IN_ADDR *) server->h_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(20000); //numéro de port

  // connexion au serveur
  if (connect(sock_cli, (struct sockaddr*) &server_addr, sizeof(SOCKADDR)) < 0) {
      perror("Connection ERREUR\n");
      exit(errno);
  }

  puts("Connecte");

  //reception message
  if ((taille = recv(sock_cli, serveur_rep, 256-1, 0) )< 0){
    puts("[client] ERREUR reception");
    exit(errno);
  }

  serveur_rep[taille]='\0'; // on ajoute le char de fin de string
  printf("ptit test : %c char num 3 reçu sur %d char reçus \n",serveur_rep[2], taille);

  puts("[client] message recu \n");
  printf("le serveur nous envoie un sublime : \n%s \nFIN DU MESSAGE REÇU\n", serveur_rep);

  strcpy(message,"BONJOUR\0");

  if((taille = send(sock_cli, message, strlen(message), 0)) <0 ){
  	puts("[client] ERREUR envoie");
    exit(errno);
  }


  do{
    printf("\nRentrez votre choix : (m pour nouveau message ou q pour quitter)");
    scanf("%c", &choix);
    switch (choix) {
      case 'm':
      printf("\n Entrez votre message: ");
      scanf("%s", message);
      if( send(sock_cli, message, strlen(message), 0) <0 ){
  		printf("[client] ERREUR envoie du message %s \n",message);
    	exit(errno);
  		}
      break;

      case 'q':
      if( send(sock_cli, "QUITTER\0", 7, 0) <0 ){
  		puts("[client] ERREUR envoie décision > QUITTER");
    	exit(errno);
 		 }
      break;
      default :
      	puts("Décision non reconnue entrez m ou q !");
    }
  }while(choix != 'q');
  // demande a l'utilisateur d'ecrire un message qui sera affiche chez le serveur

  //envoie message






  closesocket(sock_cli);

  end();
  return 0;
}
