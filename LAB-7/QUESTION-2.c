//BANKERS PROBLEM
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i, j, k, n, m, x = 0;
    int alloc[10][10], max[10][10], avail[10], need[10][10], f[10], ans[10], ind = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        f[i] = 0;
    }
    printf("Enter the number of resources:");
    scanf("%d", &m);
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the max matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available matrix:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    do
    {
        x = 0;
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                    x = 1;
                }
            }
        }
    } 
    while (x == 1);
    printf("SAFE Sequence:");
    for (i = 0; i < n - 1; i++)
    {
        printf("P%d -> ", ans[i]);
    }
    printf("P%d", ans[n - 1]);
    return (0);
}