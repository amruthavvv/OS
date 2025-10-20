#include <stdio.h>

struct process {
    int id, at, bt, tat, wt, ct;
};

void main() {
    int n, i, j, total_wt = 0, total_tat = 0, smallburst;
    float avg_wt, avg_tat;
    
    printf("Enter no of processes: ");
    scanf("%d", &n);
    
    struct process p[n];
    
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time & burst time of Process %d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
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
    
    // Calculate Completion Time, Turnaround Time, and Waiting Time
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = p[0].tat - p[0].bt;
    total_wt += p[0].wt;
    total_tat += p[0].tat;
    
    i = 1;
    while (i < n) {
        smallburst = 1000;
        
        // Find the shortest job that has arrived by the current time (p[i-1].ct)
        for (j = i; j < n; j++) {
            if (p[j].bt < smallburst && p[j].at <= p[i - 1].ct) {
                smallburst = p[j].bt;
                
                // Swap the process to bring it to the 'i' position
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
        
        p[i].ct = p[i - 1].ct + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        i++;
    }
    
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}
