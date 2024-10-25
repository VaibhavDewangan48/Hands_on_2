/*
============================================================================
Name : 10b.c
Author : Vaibhav Dewangan
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 14th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function for SIGINT
void handle_sigint(int signum) {
    printf("Caught SIGINT (Ctrl+C). Exiting gracefully.\n");
    exit(0);  // Exit the program after catching the signal
}

int main() {
    // Create a sigaction structure
    struct sigaction sa;

    // Specify the signal handler
    sa.sa_handler = handle_sigint;

    // Block all signals while the handler is running
    sigemptyset(&sa.sa_mask);

    // Use the default flags (set to 0 for basic handling)
    sa.sa_flags = 0;

    // Set up the sigaction for SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Infinite loop to keep the program running
    printf("Press Ctrl+C to trigger SIGINT and exit...\n");
    while (1) {
        printf("Running...\n");
        sleep(1);  // Sleep for 1 second
    }

    return 0;
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/10$ ./10b
Press Ctrl+C to trigger SIGINT and exit...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
^CCaught SIGINT (Ctrl+C). Exiting gracefully.

============================================================================
*/
