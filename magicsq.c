/***********************************************************
    magicsq.c -- ËâÊı¿Ø
***********************************************************/
/* ´ñ¿ô¼¡¤ÎËâÊı¿Ø */

#include <stdio.h>
#include <stdlib.h>

#define N 19  /* ´ñ¿ô */

int main()
{
    int i, j, k;
    static int a[N][N];

    k = 0;
    for (i = - N / 2; i <= N / 2; i++)
        for (j = 0; j < N; j++)
            a[(j - i + N) % N][(j + i + N) % N] = ++k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) printf("%4d", a[i][j]);
        printf("\n");
    }
    return EXIT_SUCCESS;
}
