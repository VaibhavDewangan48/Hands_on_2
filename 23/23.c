/*
============================================================================
Name : 23a.c
Author : Vaibhav Dewangan
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 18th Sep, 2024.
============================================================================
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

void main()
{
    long maxFiles;   // Maximum number of files that can be opened within process
    long sizeOfPipe; // The maximim size of a FIFO file

    char *s = "23_fifo";
    mkfifo(s, S_IRWXU);

    maxFiles = sysconf(_SC_OPEN_MAX);

    printf("Maximum number of files that can be opened is: %ld\n", maxFiles);

    // sizeOfPipe = pathconf(s, _PC_PIPE_BUF); //for size of fifo file 's' buffer

    printf("Maximum size of pipe: %d\n", PIPE_BUF);
    
}
/*
==================================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/23$ ./23 
Maximum number of files that can be opened is: 1024
Maximum size of pipe: 4096

=================================================================================
*/
