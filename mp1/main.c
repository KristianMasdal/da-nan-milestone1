#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORT 8080
#define BACKLOG 10 // Request que size

int main () {
    int server_socket_fd;
    int client_socket_fd;
    int bindstatus;
    int sockoptstatus;
    int enable = 1;
    char *file_path;
    struct sockaddr_in  server_address;
    char http_response[1024];
    char *http_bad_request = "HTTP/1.1 400 Bad Request\n\nFile not found!\n";
    char asis_file_line[BUFSIZ];
    FILE *asisFp;


    /* Create socket */
    server_socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (server_socket_fd < 0) {
        perror("Error creating socket");
       exit(0) ;
    }

    /* Allow port re-use */
    sockoptstatus = setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

    if (sockoptstatus < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
    }

    // Initialize server address
    server_address.sin_family      = AF_INET;
    server_address.sin_port        = htons((u_short)PORT);
    server_address.sin_addr.s_addr = htonl(         INADDR_ANY);

    // Bind socket with server address
    bindstatus = bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    if (bindstatus < 0) {
        perror("Bind failed");
        exit(2);
    }

    printf("Prosess %d er knyttet til port %d.\n", getpid(), PORT);

    // Listen to server socket
    listen(server_socket_fd, BACKLOG);
    while(1) {

        // Accept connection
        client_socket_fd = accept(server_socket_fd, NULL, NULL);
        //read(client_socket_fd, http_response, sizeof(http_response));
        recv(client_socket_fd, http_response, sizeof(http_response), 0);

        if(0 == fork()) {

            dup2(client_socket_fd, 1); // Client socket is now STDOUT

            //printf("%s", http_response);
            strtok(http_response, " ");
            file_path = strtok(NULL, " ");
            asisFp = fopen(file_path, "r");
            if (asisFp == NULL | strlen(file_path) <= 1) {
                send(client_socket_fd, http_bad_request, strlen(http_bad_request), 0);
            }
            else {
                while (fgets(asis_file_line, BUFSIZ, asisFp) != NULL) {
                    send(client_socket_fd, asis_file_line, strlen(asis_file_line), 0);
                }
            }

            fclose(asisFp);
            fflush(stdout);
            // Close client socket for read / write
            shutdown(client_socket_fd, SHUT_RDWR);
            exit(0);
        }

        else {
            close(client_socket_fd);
        }
    }
    return 0;
}