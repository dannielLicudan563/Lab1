#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

struct tms
{
    clock_t tms_utime;  /* user time */
    clock_t tms_stime;  /* system time */
    clock_t tms_cutime; /* user time of children */
    clock_t tms_cstime; /* system time of children */

};

int main()
{
    time_t start;
    time_t end;
    pid_t processID;
    pid_t pProcessID;
    pid_t PID;
    int status;
    int child;
    struct tms before;
    struct tms after;

    times(&before);
    time(&start);

    printf("Start: %ld\n", start);
    PID = fork();
    if(PID == 0)
    {
        //Child
        pProcessID = getppid();
        processID = getpid();
        printf("PPID: %d ", pProcessID);
        printf("PID: %d\n", processID);
        exit(0);
    }
    else if(PID >= 1)
    {
        //Parent
        child = waitpid(0, &status, WUNTRACED);
        pProcessID = getppid();
        processID = getpid();
        printf("PPID: %d ", pProcessID);
        printf("PID: %d ", processID);
        printf("CPID: %d ", child);
        printf("RETVAL: %d\n", status);
    }
    else
    {
        printf("Error");
    }
    times(&after);

    int elapsedutime = (int)(after.tms_utime-before.tms_utime);
    int elapsedstime = (int)(after.tms_stime-before.tms_stime);
    int elapsedcutime = (int)(after.tms_cutime-before.tms_cutime);
    int elapsedcstime = (int)(after.tms_cstime-before.tms_cstime);

    printf("USER: %d,\t",elapsedutime);
    printf("SYS: %d\n",elapsedstime);
    printf("CSUSER: %d,\t",elapsedcutime);
    printf("CSYS: %d\n",elapsedcstime);

    time(&end);
    printf("STOP: %ld\n", end);
    return 0;
}

