FCFS
#include <stdio.h>

struct process {
    int pid, at, bt, ct, wt, tat;
} p[50], t;

int main() {
    int n, i, j, tot_tat = 0, tot_wt = 0;
    float avg_tat, avg_wt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
    }

  
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j + 1].at) {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = p[0].tat - p[0].bt;
    tot_tat = p[0].tat;
    tot_wt = p[0].wt;

  
    for(i = 1; i < n; i++)
    {
        if(p[i].at > p[i - 1].ct)
            p[i].ct = p[i].at + p[i].bt;
        else
            p[i].ct = p[i - 1].ct + p[i].bt;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            tot_tat += p[i].tat;
            tot_wt += p[i].wt;
    }

    avg_tat = (float) tot_tat / n;
    avg_wt = (float) tot_wt / n;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nTotal TAT = %d", tot_tat);
    printf("\nTotal WT = %d", tot_wt);
    printf("\nAverage TAT = %.2f", avg_tat);
    printf("\nAverage WT = %.2f\n", avg_wt);

    return 0;
}
