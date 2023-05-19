//SHORTEST REMAINING TIME FIRST
#include <stdio.h>
#define MAX_PROCESS 10
typedef struct 
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;
void srtf(Process processes[], int n) 
{
    int i, j, time = 0, remaining_processes = n;
    int waiting_time = 0, turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while (remaining_processes > 0) 
    {
        int shortest_job_index = -1;
        int shortest_job_time = MAX_PROCESS;
        for (i = 0; i < n; i++) 
        {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) 
            {
                if (processes[i].remaining_time < shortest_job_time) 
                {
                    shortest_job_index = i;
                    shortest_job_time = processes[i].remaining_time;
                }
            }
        }
        if (shortest_job_index == -1) 
        {
            time++;
            continue;
        }
        processes[shortest_job_index].remaining_time--;
        if (processes[shortest_job_index].remaining_time == 0) 
        {
            remaining_processes--;
            waiting_time += time - processes[shortest_job_index].arrival_time - processes[shortest_job_index].burst_time + 1;
            turnaround_time += time - processes[shortest_job_index].arrival_time + 1;
            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[shortest_job_index].pid,
            processes[shortest_job_index].arrival_time, processes[shortest_job_index].burst_time,
            time - processes[shortest_job_index].arrival_time - processes[shortest_job_index].burst_time + 1,
            time - processes[shortest_job_index].arrival_time + 1);
        }
        time++;
    }
    avg_waiting_time = (float) waiting_time / n;
    avg_turnaround_time = (float) turnaround_time / n;
    printf("Average waiting time:%.2f\n", avg_waiting_time);
    printf("Average turnaround time:%.2f\n", avg_turnaround_time);
}
int main() 
{
    int i, n;
    Process processes[MAX_PROCESS];
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) 
    {
        processes[i].pid = i + 1;
        printf("P%d:", processes[i].pid);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    srtf(processes, n);
    return 0;
}