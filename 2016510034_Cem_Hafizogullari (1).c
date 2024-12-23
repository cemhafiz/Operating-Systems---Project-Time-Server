#include<stdio.h>
#include<string.h>    // for strlen
#include<sys/socket.h>
#include<arpa/inet.h> // for inet_addr
#include<unistd.h>    // for write

/*

Running instructions:
gcc 2016510034_Cem_Hafizogullari.c -o 2016510034_Cem_Hafizogullari.o
./2016510034_Cem_Hafizogullari.o
(open another terminal)
telnet localhost 8889

*/

int main(int argc, char *argv[])
{
    int socket_desc , new_socket , c;
    struct sockaddr_in server , client;
    char *message;
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        puts("Could not create socket");
        return 1;
}
     
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8889);
     
    // Bind
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Bind failed");
        return 1;
    }
    puts("Socket is binded");
     
    // Listen
    listen(socket_desc, 3);
     
    // Accept and incoming connection
    puts("Waiting for incoming connections...");

    char str[50];
    scanf(str);
    puts(str);
    
    c = sizeof(struct sockaddr_in);
    while( new_socket = 
           accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c) )
    {
        puts("Connection accepted\n");
        puts("Date : ");     // Printing Date
        puts(__DATE__);
        message = "Hello client, I received your connection.\n\n";
        write(new_socket, message, strlen(message));
    }    

    return 0;
}

