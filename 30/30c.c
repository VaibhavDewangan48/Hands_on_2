/*
============================================================================
Name : 30c.c
Author : Vaibhav Dewangan
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
int main()
{
    key_t key = ftok(".", 2);
    // shared memory created
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    // attach shared memory to process adress space
    char *data_pointer;
    data_pointer = shmat(shmid, (void *)0, 0);
    if (data_pointer == (void *)-1)
    {
        perror("Shared memory not attach");
        return 1;
    }
    printf("Shared memory attached press any key to detach it\n");
    getchar();
    printf("Detaching pointer to shared memory\n");
    shmdt(data_pointer); // Dettach pointer to Shared Memory (data_pointer)
    return 1;
}
/*
===================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/30$ ./30c
Shared memory attached press any key to detach it
vaibhav
Detaching pointer to shared memory
===================================================================
*/
