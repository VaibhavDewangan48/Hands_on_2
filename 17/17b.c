/*
============================================================================
Name : 17b.c
Author : Vaibhav Dewangan
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 16th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    int pipefd[2];
    pid_t cid;

    if (pipe(pipefd )== -1)
    {
        printf("ERROR");
    }
    else
    {
        cid = fork();
        if (cid == 0)
        {
            // closing standard output
            close(0);
            // reassigning stdin to pipe reading end;
            // dup2 will reassign pipefd[0] to 0 as it avalible.so now pipefd[0] will act as STDIN
            dup2(pipefd[0], 0);
            close(pipefd[1]); // closing unused pipe writing end
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            close(1);           // closing stdout
            dup2(pipefd[1], 1); // reassigning stdout to pipe writing end
            // dup2 will reassign pipefd[1] to 1(STDOUT) as it is avalible fd. so now pipefd[1] will act as STDOUT
            close(pipefd[0]); // closing unused reading end

            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/17$ ./17b
      5      38     229

============================================================================
*/
