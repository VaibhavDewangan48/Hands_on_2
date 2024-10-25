/*
============================================================================
Name : 29.c
Author : Vaibhav Dewangan
Description : Write a program to remove the message queue.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Define the key for the message queue
    key_t key;
    int msgid;
    const char *filepath = "progfile";

    // Check if the file exists, if not create it
    int fd = open(filepath, O_CREAT | O_RDONLY, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    close(fd);  // Close the file as we just need to ensure its existence

    // Generate a unique key for the message queue
    key = ftok(filepath, 65);  // Using the created file
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Locate the message queue with the generated key
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Remove the message queue using msgctl and IPC_RMID flag
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message queue with ID %d has been removed successfully.\n", msgid);

    return 0;
}
/*
vaibhav@vaibhav-IdeaPad-Slim-5-14IMH9:~/Downloads/MT2024165/29$ ./29 
msgget: No such file or directory

*/
