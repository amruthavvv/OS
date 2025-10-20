#include <stdio.h>

struct process {
    int id, at, bt, wt, tat, ct, pt;
};

void main() {
    int n, i, j, tot_wt = 0, tot_tat = 0, highest_priority;
    float avg_wt, avg_tat;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct process p[n];
    
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time, Burst Time and Priority of process %d: ", i + 1);
        scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].pt);
    }
    
    struct process t;
    
    // Sort by Arrival Time (FCFS)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (p[j].at > p[j + 1].at) {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
    
    // Sort processes with same Arrival Time by Burst Time (SJF Tie-breaker, as per notes)
    for (i = 0; i < n - 1; i++) {
        if (p[i].at == p[i + 1].at && p[i].bt > p[i + 1].bt) {
            t = p[i];
            p[i] = p[i + 1];
            p[i + 1] = t;
        }
    }
    
    // Calculate for the first process
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = p[0].tat - p[0].bt;
    tot_wt += p[0].wt;
    tot_tat += p[0].tat;
    
    i = 1;
    while (i < n) {
        highest_priority = 10000;
        
        // Find the highest priority job that has arrived by the current time (p[i-1].ct)
        for (j = i; j < n; j++) {
            if (p[j].pt < highest_priority && p[j].at <= p[i - 1].ct) {
                highest_priority = p[j].pt;
                
                // Swap the process to bring it to the 'i' position
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }

        p[i].ct = p[i - 1].ct + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt += p[i].wt;
        tot_tat += p[i].tat;
        i++;
    }
    
    avg_wt = (float)tot_wt / n;
    avg_tat = (float)tot_tat / n;

    printf("\nProcess Details:\n");
    printf("P.ID\tAT\tBT\tPT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].pt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}
