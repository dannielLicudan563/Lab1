#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
    time_t start;
    time_t stop;

    fork();





    time(&start);
    printf("START: %ld\n", start);












    time(&stop);
    stop = stop - start;
    printf("STOP: %ld\n", stop);
    return 0;
}
