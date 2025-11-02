#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n, i, j, temp, pos, rq[50], head, dir, size, total = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d. ", i + 1);
        scanf("%d", &rq[i]);
    }

    printf("\nEnter initial head position: ");
    scanf("%d", &head);

    printf("Enter the disk size: ");
    scanf("%d", &size);

    printf("0 = left, 1 = right\nEnter the direction: ");
    scanf("%d", &dir);

    rq[n] = head;
    n++;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(rq[j] > rq[j + 1])
            {
                temp = rq[j];
                rq[j] = rq[j + 1];
                rq[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(rq[i] == head)
        {
            pos = i;
            break;
        }
    }

    printf("\nC-SCAN service order:\n");
    printf("%d", head);

    if(dir == 1)
    {
        for(i = pos + 1; i < n; i++)
        {
            total += abs(head - rq[i]);
            head = rq[i];
            printf(" -> %d", head);
        }

        if(head != size - 1)
        {
            total += abs(head - (size - 1));
            head = size - 1;
            printf(" -> %d", head);
        }

        total += abs(head - 0);
        head = 0;
        printf(" -> %d", head);

        for(i = 0; i < pos; i++)
        {
            total += abs(head - rq[i]);
            head = rq[i];
            printf(" -> %d", head);
        }
    }
    else
    {
        for(i = pos - 1; i >= 0; i--)
        {
            total += abs(head - rq[i]);
            head = rq[i];
            printf(" -> %d", head);
        }

        if(head != 0)
        {
            total += abs(head - 0);
            head = 0;
            printf(" -> %d", head);
        }

        total += abs(head - (size - 1));
        head = size - 1;
        printf(" -> %d", head);

        for(i = n - 1; i > pos; i--)
        {
            total += abs(head - rq[i]);
            head = rq[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal head movement : %d\n", total);
}

