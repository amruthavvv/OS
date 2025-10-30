#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, i, head, total_movement = 0;

    printf("Enter number of disk request: ");
    scanf("%d", &n);

    int request[n];

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of service: %d", head);

    for (i = 0; i < n; i++) {
        total_movement += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }
    printf("\n");

    printf("\nTotal head movement: %d\n", total_movement);

    float average_movement = (float)total_movement / n;
    printf("Average head movement: %.2f\n", average_movement);
}
