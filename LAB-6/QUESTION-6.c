//PRIORITY BASED
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    printf("Enter number of processes:");
    scanf("%d", &n);
    int bt[n], priority[n], index[n];
    for (int i = 0; i < n; i++) 
    {
        printf("Enter burst time and priority value for process %d:", i);
        scanf("%d %d", &bt[i], &priority[i]);
        index[i] = i;
    }
    for (int i = 0; i < n; i++) 
    {
        int temp = priority[i], m = i;
        for (int j = i; j < n; j++) 
        {
            if (priority[j] > temp) 
            {
                temp = priority[j];
                m = j;
            }
        }
        swap(&priority[i], &priority[m]);
        swap(&bt[i], &bt[m]);
        swap(&index[i], &index[m]);
    }
    int t = 0;
    printf("\nOrder of process execution is:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Process %d is executed from %d to %d\n", index[i], t, t+bt[i]);
        t += bt[i];
    }
    printf("\nProcess ID\tBurst Time\tWait Time\n");
    int wt = 0;
    int total_wt = 0;
    for (int i = 0; i < n; i++) 
    {
        printf("Process %d\t%d\t\t%d\n", index[i], bt[i], wt);
        total_wt += wt;
        wt += bt[i];
    }
    float avg_wt = (float) total_wt / n;
    printf("Average waiting time is %f\n", avg_wt);
    int total_tat = 0;
    for(int i=0; i < n; i++)
    {
        total_tat += bt[i];
    }
    float avg_tat = (float) total_tat / n;
    printf("Average TurnAround Time is %f",avg_tat);
    return 0;
}
