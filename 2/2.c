/*
============================================================================
Name : 2.c
Author : Vaibhav Dewangan
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;

    // Get the resource limit
    if (getrlimit(resource, &limit) == 0) {
        printf("%s:\n", name);
        printf("\tSoft limit: ");
        if (limit.rlim_cur == RLIM_INFINITY) {
            printf("Unlimited\n");
        } else {
            printf("%ld\n", (long)limit.rlim_cur);
        }

        printf("\tHard limit: ");
        if (limit.rlim_max == RLIM_INFINITY) {
            printf("Unlimited\n");
        } else {
            printf("%ld\n", (long)limit.rlim_max);
        }
    } else {
        perror("getrlimit failed");
    }
}

int main() {
    // Print system resource limits for various resources
    print_limit(RLIMIT_CPU, "CPU Time");
    print_limit(RLIMIT_FSIZE, "File Size");
    print_limit(RLIMIT_DATA, "Data Segment Size");
    print_limit(RLIMIT_STACK, "Stack Size");
    print_limit(RLIMIT_CORE, "Core File Size");
    print_limit(RLIMIT_RSS, "Resident Set Size (Memory)");
    print_limit(RLIMIT_NOFILE, "Number of Open Files");
    print_limit(RLIMIT_MEMLOCK, "Locked Memory");
    print_limit(RLIMIT_NPROC, "Number of Processes");
    print_limit(RLIMIT_AS, "Virtual Memory Size");

    return 0;
}
/*
============================================================================
vaibhavd@vaibhav-X509UA:~/Desktop/SS_Handson_2/2$ ./2 
CPU Time:
	Soft limit: Unlimited
	Hard limit: Unlimited
File Size:
	Soft limit: Unlimited
	Hard limit: Unlimited
Data Segment Size:
	Soft limit: Unlimited
	Hard limit: Unlimited
Stack Size:
	Soft limit: 8388608
	Hard limit: Unlimited
Core File Size:
	Soft limit: 0
	Hard limit: Unlimited
Resident Set Size (Memory):
	Soft limit: Unlimited
	Hard limit: Unlimited
Number of Open Files:
	Soft limit: 1024
	Hard limit: 1048576
Locked Memory:
	Soft limit: 1025474560
	Hard limit: 1025474560
Number of Processes:
	Soft limit: 31017
	Hard limit: 31017
Virtual Memory Size:
	Soft limit: Unlimited
	Hard limit: Unlimited

============================================================================
*/
