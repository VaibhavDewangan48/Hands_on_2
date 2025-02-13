/*
============================================================================
Name : 11.c
Author : Vaibhav Dewangan
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call
Date: 15th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    int status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    struct sigaction act;

    act.sa_handler = SIG_IGN; // Ignoring SIGINT
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5);
    }

    printf("reseting the default action of the SIGINT signal\n");
    struct sigaction actdefault;

    actdefault.sa_handler = SIG_DFL; // setting default SIGINT
    actdefault.sa_flags = 0;
    status = sigaction(SIGINT, &actdefault,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5);
    }
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/11$ ./11 
ignoring the SIGINT signal for 5 seconds
reseting the default action of the SIGINT signal
============================================================================
*/
