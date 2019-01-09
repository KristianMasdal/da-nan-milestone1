#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define PORT 8080
#define BACKLOG 10 // Request que size


int main () {
    int server_socket_fd;
    int client_socket_fd;
    int bindstatus;
    int sockoptstatus;
    int enable = 1;
    struct sockaddr_in  server_address;
    char *file_path;
    char http_response[1024];
    char asis_file_line[BUFSIZ];
    FILE *asisFp;
    int error_log_fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    error_log_fd = (open("error.log", O_RDWR | O_CREAT, mode));

    if (error_log_fd < 0) {
        perror("Log file not found");
    } else {
        dup2(error_log_fd, 2);
    }

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
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind socket with server address
    bindstatus = bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    if (bindstatus < 0) {
        perror("Bind failed");
        exit(1);
    }

    printf("Process %d is connected to port %d.\n", getpid(), PORT);

    // Listen to server socket
    listen(server_socket_fd, BACKLOG);
    while(1) {

        // Accept connection
        client_socket_fd = accept(server_socket_fd, NULL, NULL);
        read(client_socket_fd, http_response, sizeof(http_response));

        if(0 == fork()) {

            dup2(client_socket_fd, 1); // Client socket is now STDOUT

            strtok(http_response, " ");
            file_path = strtok(NULL, " ");
            asisFp = fopen(file_path, "r");

            if (asisFp == NULL) {
                printf("HTTP/1.1 400 Bad Request\n");
                printf("\n");
                printf("File not found!\n");
            } else {
                while (fgets(asis_file_line, BUFSIZ, asisFp) != NULL) {
                    printf("%s", asis_file_line);
                }
            }

            fclose(asisFp);
            close(error_log_fd);
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