#include <stdio.h>

struct process {
    int id, at, bt, wt, tat, ct, pt, rt; // rt is remaining time
};

void main() {
    int n, i, time = 0, remain, tq;
    float avg_wt = 0, avg_tat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct process p[n];
    
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time & Burst Time for process P%d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }
    
    printf("Enter time Quantum: ");
    scanf("%d", &tq);
    
    int completed = 0, flag = 0;
    remain = n;
    
    while (completed != n) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                flag = 1;
                
                if (p[i].rt > tq) {
                    time += tq;
                    p[i].rt -= tq;
                } else {
                    time += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    avg_wt += p[i].wt;
                    avg_tat += p[i].tat;
                    completed++;
                }
            }
        }
        
        if (flag == 0) {
            time++;
        }
    }
    
    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}
