#include <stdio.h>

int main() {
int frames[10], pages[30];
int n, f, i, j, k, pos, pageFaults = 0, flag;

printf("Enter number of pages: ");  
scanf("%d", &n);  

printf("Enter the page reference string: ");  
for (i = 0; i < n; i++)  
    scanf("%d", &pages[i]);  

printf("Enter number of frames: ");  
scanf("%d", &f);  

// initialize frames with -1 (empty)  
for (i = 0; i < f; i++)  
    frames[i] = -1;  

printf("\nPage Reference String\tFrames\n");  

for (i = 0; i < n; i++) {  
    flag = 0;  

    // check if page already exists in frame  
    for (j = 0; j < f; j++) {  
        if (frames[j] == pages[i]) {  
            flag = 1;  
            break;  
        }  
    }  

    // if not present -> page fault  
    if (flag == 0) {  
        // if empty slot available  
        for (j = 0; j < f; j++) {  
            if (frames[j] == -1) {  
                frames[j] = pages[i];  
                pageFaults++;  
                flag = 1;  
                break;  
            }  
        }  
    }  

    // if no empty slot -> replace Optimal page  
    if (flag == 0) {  
        int farthest = i + 1, replaceIndex = -1;  

        for (j = 0; j < f; j++) {  
            int nextUse = -1;  
            for (k = i + 1; k < n; k++) {  
                if (frames[j] == pages[k]) {  
                    nextUse = k;  
                    break;  
                }  
            }  

            if (nextUse == -1) { // not used again  
                replaceIndex = j;  
                break;  
            }  

            if (nextUse > farthest) {  
                farthest = nextUse;  
                replaceIndex = j;  
            }  
        }  

        frames[replaceIndex] = pages[i];  
        pageFaults++;  
    }  

    // print current frame status  
    printf("%d\t\t\t", pages[i]);  
    for (j = 0; j < f; j++) {  
        if (frames[j] != -1)  
            printf("%d ", frames[j]);  
        else  
            printf("- ");  
    }  
    printf("\n");  
}  

printf("\nTotal Page Faults = %d\n", pageFaults);  

return 0;

}

Explain where the execution control of the program  goes on every break control statement
