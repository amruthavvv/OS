#include <stdio.h>
#include <stdlib.h>

// Function to sort the request array
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int requests[100], n, head, direction;
    int total_seek = 0, i, pos, curr;
    
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    printf("Enter request sequence: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    // 0 for left/down, 1 for right/up
    printf("Enter direction (0 for left, 1 for right): "); 
    scanf("%d", &direction);
    
    requests[n] = head;
    n++; 

    sort(requests, n);

    pos = -1;
    for (i = 0; i < n; i++) {
        if (requests[i] == head) {
            pos = i;
            break;
        }
    }
    
    curr = head;
    
    printf("\nC-LOOK Disk Scheduling\n");
    printf("Request\tSeek Time\n");
    
    if (direction == 1) { // Moving Right (Up)
        
        // FIRST PASS: Moving Right and servicing requests
        for (i = pos + 1; i < n; i++) {
            int seek_val = abs(requests[i] - curr);
            printf("%d\t%d\n", requests[i], seek_val);
            total_seek += seek_val;
            curr = requests[i];
        }
        
        // SECOND PASS: Jump to requests[0] and service remaining
        for (i = 0; i < pos; i++) { 
            int seek_val = abs(requests[i] - curr);
            printf("%d\t%d\n", requests[i], seek_val);
            total_seek += seek_val;
            curr = requests[i];
        }
        
    } else { // direction == 0 (Moving Left/Down)
    
        // FIRST PASS: Moving Left and servicing requests
        for (i = pos - 1; i >= 0; i--) { 
            int seek_val = abs(requests[i] - curr);
            printf("%d\t%d\n", requests[i], seek_val);
            total_seek += seek_val;
            curr = requests[i];
        }
        
        // SECOND PASS: Jump to requests[n-1] and service remaining
        for (i = n - 1; i > pos; i--) { 
            int seek_val = abs(requests[i] - curr);
            printf("%d\t%d\n", requests[i], seek_val);
            total_seek += seek_val;
            curr = requests[i];
        }
    }
    
    printf("\nTotal seek time: %d\n", total_seek);
    printf("Average seek time: %.2f\n", (float)total_seek / (n - 1));
    
    return 0;
}
