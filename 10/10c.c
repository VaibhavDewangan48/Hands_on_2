/*
============================================================================
Name : 10c.c
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

// Signal handler function for SIGFPE
void handle_sigfpe(int signum) {
    printf("Caught SIGFPE: Floating-point exception occurred.\n");
    exit(1);  // Exit the program after catching the signal
}

int main() {
    // Create a sigaction structure
    struct sigaction sa;

    // Specify the signal handler
    sa.sa_handler = handle_sigfpe;

    // Block all signals while the handler is running
    sigemptyset(&sa.sa_mask);

    // Use the default flags (set to 0 for basic handling)
    sa.sa_flags = 0;

    // Set up the sigaction for SIGFPE
    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Trigger a floating-point exception: division by zero
    printf("Triggering division by zero to raise SIGFPE...\n");

    int a = 10;
    int b = 0;
    int c = a / b;  // This will raise SIGFPE (division by zero)

    // This line will never be reached due to the floating-point exception
    printf("This line will not be printed, result: %d\n", c);

    return 0;
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/10$ ./10c
Triggering division by zero to raise SIGFPE...
Caught SIGFPE: Floating-point exception occurred.

============================================================================
*/
