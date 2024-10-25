#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

// Define the structure for message queue
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Generate a unique key for the message queue
    key = ftok("progfile", 65);

    // Create the message queue and return the identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Receive a message from the queue
    printf("Waiting to receive a message...\n");
    msgrcv(msgid, &message, sizeof(message.msg_text), 0, 0);  // flag = 0

    // Display the received message
    printf("Received message: %s\n", message.msg_text);

    return 0;
}
