#include <stdio.h>
#include <stdlib.h>

void main() {
    int req[100], serviced[100], seek_time[100];
    int n, i, j, total_seek = 0, head, c = 0, min_index, d;
    int min;
    int current_head;
    int rep[100];

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        rep[i] = req[i];
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    current_head = head;
    i = 0;

    while (c != n) {
        min = 1000;
        for (j = 0; j < n; j++) {
            if (rep[j] != 1000) {
                d = abs(rep[j] - current_head);
                if (d < min) {
                    min = d;
                    min_index = j;
                }
            }
        }
        
        seek_time[i] = min;
        total_seek += min;
        current_head = rep[min_index];
        serviced[i] = rep[min_index];
        rep[min_index] = 1000;
        c++;
        i++;
    }

    printf("\nRequests \t Seek time\n");
    printf("%d \t %d\n", head, 0); 
    
    for (i = 0; i < n; i++) {
        printf("%d \t\t %d\n", serviced[i], seek_time[i]);
    }

    printf("\nTotal seek time: %d\n", total_seek);
    printf("Average seek time: %.2f\n", (float)total_seek / n);
}
