#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, i, j, temp, head, size;
    int tot_seek = 0;
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    // Size n+1 to accommodate the initial head position
    int req[n + 1];
    
    printf("Enter the disk request sequence: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    printf("Enter total disk size: ");
    scanf("%d", &size);
    
    // Add head to the request array
    req[n] = head;
    n++; // Increment n to include the head position
    
    // Sort the requests array (including the head) - using Bubble Sort
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
    // Find the position of the initial head in the sorted array
    for (i = 0; i < n; i++) {
        if (req[i] == head) {
            head_index = i;
            break;
        }
    }

    int serviced[n + 10], seek[n + 10], c = 0, current_head = head;
    
    // --- FIRST PASS: Moving Up (towards size-1) and servicing requests ---
    // Start from the request after the head position
    for (i = head_index + 1; i < n; i++) {
        seek[c] = abs(current_head - req[i]);
        serviced[c] = req[i];
        tot_seek += seek[c];
        current_head = req[i];
        c++;
    }
    
    // --- JUMP: Move to the end of the disk (size-1) ---
    // This is not in the original handwritten C-SCAN but is implied by the next jump.
    // However, the handwritten SCAN code had an explicit move to size-1, so we include 
    // it here for better C-SCAN simulation, but the handwritten C-SCAN code did NOT 
    // have this, it directly jumps to 0. 
    // Following the C-SCAN logic: Head moves to size-1.
    // The handwritten code only services up to the max request, then moves to size-1.
    
    // Move to the maximum cylinder (size-1)
    int size_limit = size - 1;
    if (current_head != size_limit) { 
        seek[c] = abs(current_head - size_limit);
        serviced[c] = size_limit;
        tot_seek += seek[c];
        current_head = size_limit;
        c++;
    }
    
    // --- JUMP: Circular jump from size-1 to 0 (no requests serviced) ---
    seek[c] = abs(current_head - 0); // Jump from size-1 to 0
    serviced[c] = 0;
    tot_seek += seek[c];
    current_head = 0;
    c++;
    
    // --- SECOND PASS: Moving Up (from 0) and servicing the remaining requests ---
    // Servicing requests from index 0 up to head_index - 1
    for (i = 0; i < head_index; i++) { 
        seek[c] = abs(current_head - req[i]);
        serviced[c] = req[i];
        tot_seek += seek[c];
        current_head = req[i];
        c++;
    }
    
    // Print the results
    printf("\nRequest\tSeek time\n");
    for (i = 0; i < c; i++) {
        printf("%d\t%d\n", serviced[i], seek[i]);
    }

    printf("\nTotal Seek time: %d\n", tot_seek);
    // n-1 is the original number of requests
    printf("\nAverage seek time: %.2f\n", (float)tot_seek / (n - 1)); 
}
