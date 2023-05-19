//SHORTEST JOB FIRST
#include<stdio.h>
void main() 
{  
  int processes, i, j, min_index, temp, time = 0, btt = 0;
  float avg_wt = 0, avg_tat = 0;   
  printf("Enter the number of processes:");
  scanf("%d", &processes);
  int bt[processes], wt[processes], tat[processes], at[processes], completed[processes];
  for(i = 0; i < processes; i++) 
  {
    printf("Enter the arrival time and burst time for process P%d:", i);
    scanf("%d %d", &at[i], &bt[i]);
    completed[i] = 0; 
    btt += bt[i]; 
  }
  while(time < btt)
  {
    min_index = -1; 
    for(i = 0; i < processes; i++) 
    {
      if(at[i] <= time && completed[i] == 0) 
      {
        if(min_index == -1 || bt[i] < bt[min_index]) 
        {
          min_index = i; 
        }
      }
    }
    if(min_index == -1) 
    {
      time++; 
      continue;
    }
    wt[min_index] = time - at[min_index]; 
    tat[min_index] = wt[min_index] + bt[min_index]; 
    time += bt[min_index]; 
    completed[min_index] = 1; 
  }
  printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i = 0; i < processes; i++) 
  {
    printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i, at[i], bt[i], wt[i], tat[i]);
    avg_wt += wt[i];
    avg_tat += tat[i];
  }
  avg_wt /= processes;
  avg_tat /= processes;
  printf("Average Waiting Time:%.2f\n", avg_wt);
  printf("Average Turnaround Time:%.2f", avg_tat);
}