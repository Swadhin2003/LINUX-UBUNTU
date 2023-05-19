//ROUND ROBIN
#include <stdio.h>
#define MAX_PROCESS 10
#define TIME_QUANTUM 2
struct process 
{
    int pid, at, bt, rt, tt, wt;
};
void rr(struct process p[], int n) 
{
    int t = 0, i, r = n, c[MAX_PROCESS] = {0}, q[MAX_PROCESS] = {0};
    while (r > 0) 
    {
        for (i = 0; i < n; i++) 
        {
            if (!c[i] && p[i].at <= t) 
            {
                if (p[i].rt <= TIME_QUANTUM) 
                {
                    t += p[i].rt;
                    q[i] = 0;
                    p[i].wt = t - p[i].at - p[i].bt;
                    p[i].rt = 0;
                    p[i].tt = t - p[i].at;
                    c[i] = 1;
                    r--;
                }
                else 
                {
                    t += TIME_QUANTUM;
                    p[i].rt -= TIME_QUANTUM;
                    q[i] = TIME_QUANTUM;
                }
            }
            else 
            {
                q[i] = 0;
            }
        }
    }
}
int main() 
{
    int n, i;
    struct process p[MAX_PROCESS];
    printf("Enter number of processes:");
    scanf("%d", &n);
    printf("Enter arrival time and burst time for processes:\n");
    for (i = 0; i < n; i++) 
    {
        printf("Process %d:", i);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].pid = i;
    }
    rr(p, n);
    float avg_wt = 0, avg_tt = 0;
    for (i = 0; i < n; i++) 
    {
        avg_wt += p[i].wt;
        avg_tt += p[i].tt;
    }
    avg_wt /= n;
    avg_tt /= n;
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tt);
    }
    printf("Avg WT:%.2f\n", avg_wt);
    printf("Avg TAT:%.2f\n", avg_tt);
    return 0;
}