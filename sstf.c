#include <stdio.h>
#include <stdlib.h>

void main() {
    int req[100], serviced[100], seek_time[100];
    int i, n, total_seek = 0, head, c = 0, min, index, d;
    int current_head;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the requests sequence: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    current_head = head;

    while (c < n) {
        min = 1000;
        for (i = 0; i < n; i++) {
            if (req[i] != -1) { // Check if request is not already serviced
                d = abs(req[i] - current_head);
                if (d < min) {
                    min = d;
                    index = i;
                }
            }
        }
        
        seek_time[c] = min;
        total_seek += min;
        serviced[c] = req[index];
        current_head = req[index];
        req[index] = -1; // Mark the request as serviced
        c++;
    }

    printf("\nRequests\tSeek time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", serviced[i], seek_time[i]);
    }

    printf("\nTotal Seek time: %d\n", total_seek);
    printf("Average Seek time: %.2f\n", (float)total_seek / n);
}
