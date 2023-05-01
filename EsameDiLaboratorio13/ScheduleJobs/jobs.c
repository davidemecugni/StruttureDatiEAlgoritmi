//Time 35min
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

typedef struct {
    int profit;
    int duration;
    int deadline;
    int index;
}job_index;
//Function to compare j1 and j2
int comp(const void* j1, const void* j2)
{
    const job_index* j1_c = j1;
    const job_index* j2_c = j2;
    //Calculates the desirability of a job
    double f = (double)j1_c->profit / (double)j1_c->duration;
    double s = (double)j2_c->profit / (double)j2_c->duration;
    //Inverts every comparation so it is sorted highest desirability -> lowest
    if (f > s) return  -1;
    if (f < s) return 1;
    if (j1_c->duration < j2_c->duration) {
        return -1;
    }
    else {
        return 1;
    }
    return 0;
}
/*
int FindIndex(const job* j, const job* jobs, size_t j_size) {
    for (int i = 0; i < j_size; i++) {
        if (j->deadline == j[i].deadline && j->duration == j[i].duration && j->profit == j[i].profit) {
            return i;
        }
    }
    return -1;
}
*/
int ScheduleJobs(const job* jobs, size_t j_size) {
    //Creates a copy with an index to every job so it can be sorted
    job_index* copy = calloc(j_size, sizeof(job_index));
    for (int i = 0; i < (int)j_size; i++) {
        copy[i].deadline = jobs[i].deadline;
        copy[i].duration = jobs[i].duration;
        copy[i].profit = jobs[i].profit;
        copy[i].index = i;
    }
    qsort(copy, j_size, sizeof(job_index), comp);
    int time = 0;
    int total_profit=0;
    for (int i = 0; i < (int)j_size; i++) {
        //If the project can be completed in the timeline
        if (time + copy[i].duration <= copy[i].deadline) {
            //Project time is added to the time from the beginning
            time += copy[i].duration;
            //The project's profit is added to the total profit
            total_profit += copy[i].profit;
            printf("%d ", copy[i].index);
        }
    }
    free(copy);
    return total_profit;
}