#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, i, j, temp, head, size;
    int tot_seek = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int req[n + 10];
    printf("Enter the disk request sequence: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (req[j] > req[j + 1]) {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int head_index = 0;
    for (i = 0; i < n; i++) {
        if (req[i] >= head) {
            head_index = i;
            break;
        }
    }

    int serviced[n + 10], seek[n + 10], c = 0, current_head = head;

    for (i = head_index; i < n; i++) {
        seek[c] = abs(current_head - req[i]);
        serviced[c] = req[i];
        tot_seek += seek[c];
        current_head = req[i];
        c++;
    }

    if (current_head != size - 1) {
        seek[c] = abs(current_head - (size - 1));
        serviced[c] = size - 1;
        tot_seek += seek[c];
        current_head = size - 1;
        c++;
    }

    seek[c] = abs(current_head - 0);
    serviced[c] = 0;
    tot_seek += seek[c];
    current_head = 0;
    c++;

    for (i = 0; i < head_index; i++) {
        seek[c] = abs(current_head - req[i]);
        serviced[c] = req[i];
        tot_seek += seek[c];
        current_head = req[i];
        c++;
    }

    printf("\nRequest\tSeek time\n");
    for (i = 0; i < c; i++) {
        printf("%d\t%d\n", serviced[i], seek[i]);
    }

    printf("\nTotal Seek time: %d\n", tot_seek);
    printf("Average Seek time: %.2f\n", (float)tot_seek / n);
}
