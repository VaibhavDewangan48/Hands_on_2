/*
============================================================================
Name : 6.c
Author : Vaibhav Dewangan
Description : Write a simple program to create three threads
Date: 14th Sep, 2024.
============================================================================
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread\n");
}

void main()
{
    pthread_t threadID1, threadID2, threadID3;
    int pstatus;
    pstatus = pthread_create(&threadID1, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pthread_exit(NULL);
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/6$ ./6 
Printing from thread
Printing from thread
Printing from thread

============================================================================
*/
