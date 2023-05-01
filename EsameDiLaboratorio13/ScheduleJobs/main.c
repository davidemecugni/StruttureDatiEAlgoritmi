#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int profit;
    int duration;
    int deadline;
}job;
extern int ScheduleJobs(const job* jobs, size_t j_size);
int main(void) {
    job* jobs = calloc(3, sizeof(jobs));
    jobs[0].duration = 2;
    jobs[0].profit = 50;
    jobs[0].deadline = 4;
    jobs[1].duration = 4;
    jobs[1].profit = 100;
    jobs[1].deadline = 7;
    jobs[2].duration = 1;
    jobs[2].profit = 30;
    jobs[2].deadline = 3;
    printf("Totale : %d", ScheduleJobs(jobs, 3));
}