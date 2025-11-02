#include <stdio.h>

void fifo_page_replacement() {
    int m, n;
    int i, j, flag, k = 0;
    int reference_string[50];
    int frames[10];
    int page_faults = 0;

    printf("enter the number of frames: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        frames[i] = -1;
    }

    printf("enter the length of reference string: ");
    scanf("%d", &n);

    printf("enter the reference string: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &reference_string[i]);
    }

    for (i = 0; i < n; i++) {
        flag = 0;
        printf("In Referencing page: %d\t", reference_string[i]);

        for (j = 0; j < m; j++) {
            if (frames[j] == reference_string[i]) {
                flag = 1;
                printf("Hit\n");
                break;
            }
        }

        if (flag == 0) {
            printf("Fault\t");
            frames[k] = reference_string[i];
            k = (k + 1) % m;
            page_faults++;
        }

        printf("Frames: ");
        for (j = 0; j < m; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);
}

int main() {
    fifo_page_replacement();
    return 0;
}
