/***********************************************************
    permsign.c -- √÷¥π§Œ…‰πÊ
***********************************************************/
#define N 4

int sign(int v[])
{
    int i, j, p, w[N + 1];

    for (i = 1; i <= N; i++) w[v[i]] = i;
    p = 1;
    for (i = 1; i < N; i++) {
        j = v[i];
        if (j != i) {
            v[w[i]] = j;  w[j] = w[i];  p = -p;
        }
    }
    return p;
}

#include <stdio.h>
#include <stdlib.h>

int nextperm(int a[])
{
    int i, j, t;

    i = N - 1;
    a[0] = 0;  /* »÷øÕ */
    while (a[i] >= a[i + 1]) i--;
    if (i == 0) return 0;  /* ¥∞Œª */
    j = N;
    while (a[i] >= a[j]) j--;
    t = a[i];  a[i] = a[j];  a[j] = t;
    i++;  j = N;
    while (i < j) {
        t = a[i];  a[i] = a[j];  a[j] = t;  i++;  j--;
    }
    return 1;  /* Ã§Œª */
}

void test1(void)
{
    int i, count, a[N + 1], v[N + 1];

    printf("º≠ΩÒº∞ΩÁΩ¯:\n");
    count = 0;
    for (i = 1; i <= N; i++) a[i] = i;
    do {
        printf("%5d: ", ++count);
        for (i = 1; i <= N; i++) printf("%4d", v[i] = a[i]);
        printf("  %s√÷¥π\n", (sign(v) == 1) ? "∂ˆ" : "¥Ò");
    } while (nextperm(a));
}

void test2(void)
{
    int i, k, t, p[N + 1], c[N + 2], v[N + 1], count;

    printf("∏ﬂ¥π§À§Ë§ÎΩÁŒÛ¿∏¿Æ:\n");
    count = 0;
    for (i = 1; i <= N; i++) c[i] = p[i] = i;
    c[N + 1] = 0;  /* »÷øÕ */
    for (k = 2; k <= N; c[k]--) {
        if (k & 1) i = 1;  else i = c[k];
        t = p[k];  p[k] = p[i];  p[i] = t;
        printf("%5d: ", ++count);
        for (i = 1; i <= N; i++) printf("%4d", v[i] = p[i]);
        printf("  %s√÷¥π\n", (sign(v) == 1) ? "∂ˆ" : "¥Ò");
        for (k = 2; c[k] == 1; k++) c[k] = k;
    }
}

int main()
{
    test1();
    test2();
    return EXIT_SUCCESS;
}
