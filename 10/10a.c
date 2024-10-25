/*
============================================================================
Name : 10a.c
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

// Signal handler function for SIGSEGV
void segfault_handler(int signum) {
    printf("Caught SIGSEGV: Segmentation Fault occurred.\n");
    exit(1);  // Exit the program after catching the signal
}

int main() {
    // Create a sigaction structure
    struct sigaction sa;

    // Specify the signal handler
    sa.sa_handler = segfault_handler;

    // Block all signals while the handler is running
    sigemptyset(&sa.sa_mask);

    // Use the default flags (set to 0 for basic handling)
    sa.sa_flags = 0;

    // Set up the sigaction for SIGSEGV
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Raising SIGSEGV by dereferencing a NULL pointer...\n");

    // Dereferencing a NULL pointer to intentionally cause a segmentation fault
    int *p = NULL;
    *p = 42;  // This will trigger SIGSEGV

    // This will never be reached due to the segmentation fault
    printf("This line will not be printed.\n");

    return 0;
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/10$ ./10a
Raising SIGSEGV by dereferencing a NULL pointer...
Caught SIGSEGV: Segmentation Fault occurred.

============================================================================
*/
