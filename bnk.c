#include <stdio.h>
#define MAX 100

int max[MAX][MAX];
int alloc[MAX][MAX];
int need[MAX][MAX];
int avail[MAX];
int n, r;

void input();
void calculate();

int main() {
    input();
    calculate();
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &r);

    printf("\nEnter the MAX matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter the ALLOCATION matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter the AVAILABLE resources:\n");
    for (j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nNEED matrix calculated:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
}

void calculate() {
    int i, j, k;
    int finish[MAX] = {0}, safeseq[MAX], count = 0;
    int found;

    printf("\nProcess\t\tMax\t\tAlloc\t\tNeed\t\tAvailable\n");

    while (count < n) {
        found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canRun = 1;

                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if (canRun == 1) {
                    for (k = 0; k < r; k++)
                        avail[k] += alloc[i][k];

                    safeseq[count++] = i;
                    finish[i] = 1;
                    found = 1;

                    printf("P%d\t\t", i);
                    for (j = 0; j < r; j++)
                        printf("%d ", max[i][j]);
                    printf("\t\t");
                    for (j = 0; j < r; j++)
                        printf("%d ", alloc[i][j]);
                    printf("\t\t");
                    for (j = 0; j < r; j++)
                        printf("%d ", need[i][j]);
                    printf("\t\t");
                    for (j = 0; j < r; j++)
                        printf("%d ", avail[j]);
                    printf("\n");
                }
            }
        }

        if (!found) {
            printf("\nSystem is NOT in a SAFE STATE.\n");
            return;
        }
    }

    printf("\nSystem is in a SAFE STATE.\nSafe Sequence: ");
    for (i = 0; i < n; i++) {
        printf("P%d", safeseq[i]);
        if (i != n - 1)
            printf(" -> ");
    }
    printf("\n");
}
