//HIGHEST RESPONSE RATIO NEXT
#include<stdio.h>
struct process 
{
    int pid; 
    int at; 
    int bt; 
    int wt; 
    int tat; 
    float rr; 
};
void hrrn(struct process p[], int n) 
{
    int i, j, total_wt = 0, total_tat = 0;
    float total_rr = 0;
    for(i = 0; i < n; i++) 
    {
        p[i].wt = total_wt - p[i].at;
        total_wt += p[i].bt;
        p[i].tat = p[i].wt + p[i].bt;
        p[i].rr = (float)(p[i].tat) / p[i].bt;
        total_rr += p[i].rr;
    }
    for(i = 0; i < n; i++) 
    {
        for(j = i + 1; j < n; j++) 
        {
            if(p[j].rr > p[i].rr) 
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Ratio\n");
    for(i = 0; i < n; i++) 
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%f\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat, p[i].rr);
        total_tat += p[i].tat;
    }
    printf("\nAverage Waiting Time = %f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %f", (float)total_tat / n);
    printf("\nAverage Response Ratio = %f\n", total_rr / n);
}
int main() 
{
    int n, i;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time for process:\n");
    struct process p[n];
    for(i = 0; i < n; i++) 
    {
        printf("Process %d:", i);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i;
    }
    hrrn(p, n);
    return 0;
}