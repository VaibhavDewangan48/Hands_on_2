/*
============================================================================
Name : 3.c
Author : Vaibhav Dewangan
Description : Write a program to set (any one) system resource limit. Use setrlimit system call
Date: 14th Sep, 2024.
============================================================================
*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", hard, unit);
}

void main()
{
    int status;                   // Determines the success of the `getrlimit` call
    struct rlimit resourceLimits; // Holds the hard & soft limits for a resource
    printf("before updatimg limits");
    // RLIMIT_STACK -> Maximum  size of the process stack
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    printf("Choosing new resource limits\n");
    struct rlimit newresourceLimits; // Holds the hard & soft limits for a resource
    newresourceLimits.rlim_cur=10000;
    newresourceLimits.rlim_max=20000;
    status = setrlimit(RLIMIT_SIGPENDING, &newresourceLimits);

    printf("after updatimg limits");
    // RLIMIT_STACK -> Maximum  size of the process stack
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/3$ ./3 
before updatimg limitsMaximum  size of the process stack - 
	Soft Limit: 31017 bytes
	Hard Limit: 31017 bytes
Choosing new resource limits
after updatimg limitsMaximum  size of the process stack - 
	Soft Limit: 10000 bytes
	Hard Limit: 20000 bytes

============================================================================
*/
