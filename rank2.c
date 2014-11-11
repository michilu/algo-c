/***********************************************************
    rank2.c -- ½ç°Ì¤Å¤±
***********************************************************/

#define MAX 100  /* ËşÅÀ */

void find_rank(int n, int a[], int rank[])
{
    int i;
    static int count[MAX + 2];

    for (i = 0; i <= MAX; i++) count[i] = 0;
    for (i = 0; i < n; i++) count[a[i]]++;
    count[MAX + 1] = 1;
    for (i = MAX; i > 0; i--) count[i] += count[i + 1];
    for (i = 0; i < n; i++) rank[i] = count[a[i] + 1];
}

#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
    int i, a[N], rank[N];

    for (i = 0; i < N; i++)
        a[i] = (MAX + 1.0) / (RAND_MAX + 1.0) * rand();
    find_rank(N, a, rank);
    printf("    score rank\n");
    for (i = 0; i < N; i++)
        printf("%2d: %5d %4d\n", i, a[i], rank[i]);
    return EXIT_SUCCESS;
}
