//FIRST COME FIRST SERVE
#include<stdio.h>
int main() 
{
    int n, i;
    float avgwt = 0, avgtat = 0;
    float twt=0, ttat=0;
    int at[100], bt[100], wt[100], tat[100];
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d:", i);
        scanf("%d %d", &at[i], &bt[i]);
    }
    wt[0] = 0;
    tat[0] = bt[0];
    for(i = 1; i < n; i++) 
    {
        wt[i] = wt[i-1] + bt[i-1] - at[i] + at[i-1];
        tat[i] = wt[i] + bt[i];
    }
    for(i = 0; i < n; i++) 
    {
        twt += wt[i];
        ttat += tat[i];
    }
    avgwt = twt/n;
    avgtat = ttat/n;
    printf("\nProcess\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) 
    printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i, at[i], bt[i], wt[i], tat[i]);
    printf("Average waiting time:%f\n", avgwt);
    printf("Average turnaround time:%f", avgtat);
    return 0;
}