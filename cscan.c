#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, i, j, temp, head, size;
    int tot_seek = 0;
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
  
    
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
  
    int size_limit = size - 1;
    if (current_head != size_limit) { 
        seek[c] = abs(current_head - size_limit);
        serviced[c] = size_limit;
        tot_seek += seek[c];
        current_head = size_limit;
        c++;
    }
    
  
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
    // n-1 is the original number of requests
    printf("\nAverage seek time: %.2f\n", (float)tot_seek / (n - 1)); 
}
