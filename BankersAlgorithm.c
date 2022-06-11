#include <stdio.h>

int main()
{
    int n=4, m=4, i, j, k;
    int alloc[4][4] = { { 6, 3, 4, 7},{ 6, 4, 6, 6},{ 9, 0, 2, 5 },{ 4, 12, 1, 0 }};
    int max[4][4] = { { 3, 5, 3, 2 },{ 6, 2, 2, 2 },{ 8, 3, 2, 1 },{ 2, 2, 2, 4 }};
    int avail[3] = { 3, 3, 2 };
    int f[4], ans[4], ind = 0;

    for (k = 0; k < n; k++) f[k] = 0;
    int need[4][4];
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    }
    int y = 0;
    for (k = 0; k < 4; k++) 
    {
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
                for (y = 0; y < m; y++)
                    avail[y] += alloc[i][y];
                f[i] = 1;
            }
            }
        }
    }
    int flag = 1;
    for(int i=0;i<n;i++)
    {
        if(f[i]==0)
        {
            flag=0;
            printf("System is not safe");
            break;
        }
    }
    if(flag==1)
    {
        printf("System is Safe\n");
        for (i = 0; i < n - 1; i++)
        {
            printf(" P%d ->", ans[i]);
            printf(" P%d", ans[n - 1]);
        }
        
    }
    return (0);
}