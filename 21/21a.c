/*
============================================================================
Name : 21.c
Author : Vaibhav Dewangan
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 17th Sep, 2024.
============================================================================
*/
#include <sys/types.h> // Import for `mkfifo` & `open`
#include <sys/stat.h>  // Import for `mkfifo` & `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `write`
#include <stdio.h>     // Import for `perror`

void main()
{
    char *s; // Data to be sent through the buffer
    int fd;  // File descriptor of the FIFO file
    long int size = 100;
    char *file = "./21a-fifo";
    mkfifo(file, S_IRWXU);
    while (1)
    {
        fd = open(file, O_WRONLY);
        if (fd == -1)
            perror("Error");
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }

        fd = open(file, O_RDONLY); // File descriptor of the FIFO file

        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
            close(fd);
        }
    }
}
/*
======================================================================
vaibhav@vaibhav-IdeaPad-Slim-5-14IMH9:~/Downloads/MT2024165/21$ ./21a 
enter message:
hello
hii

enter message:
^C

vaibhav@vaibhav-IdeaPad-Slim-5-14IMH9:~/Downloads/MT2024165/21$ ./21b
hello

enter message:
hii




======================================================================
*/