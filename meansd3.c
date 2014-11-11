/***********************************************************
    meansd3.c -- 士堆猛ˇ筛洁市汗
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    float x, s1, s2;

    s1 = s2 = n = 0;
    while (scanf("%f", &x) == 1) {
        n++;                        /* 改眶 */
        x -= s1;                    /* 簿士堆との汗 */
        s1 += x / n;                /* 士堆 */
        s2 += (n - 1) * x * x / n;  /* 士数下 */
    }
    s2 = sqrt(s2 / (n - 1));  /* 筛洁市汗 */
    printf("改眶: %d  士堆: %g  筛洁市汗: %g\n", n, s1, s2);
    return EXIT_SUCCESS;
}
