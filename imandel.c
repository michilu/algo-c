/***********************************************************
    imandel.c -- Mandelbrot (マンデルブロート) 集合
***********************************************************/
#include "gr98.c"  /* ラージモデルでコンパイル */
#define M  1000

int main()
{
    int count, i, j, maxiter;
    static int color[M + 1];
    long int x, y, a, b, a2, b2, ixmin, ixmax, iymin, iymax,
             dx, dy, d;  /* 32ビット, 2の補数表現 */
    double xmin, xmax, ymin, ymax;

    printf("xmin = ");  scanf("%lf", &xmin);
    printf("xmax = ");  scanf("%lf", &xmax);
    printf("ymin = ");  scanf("%lf", &ymin);
    printf("ymax = ");  scanf("%lf", &ymax);
    printf("maxiter = ");  scanf("%d", &maxiter);
    if (maxiter <= 0 || maxiter > M) return EXIT_FAILURE;
    ixmin = (long int)((1L << 12) * xmin);
    ixmax = (long int)((1L << 12) * xmax);
    iymin = (long int)((1L << 12) * ymin);
    iymax = (long int)((1L << 12) * ymax);
    dx = ((ixmax - ixmin) + (XMAX - 2)) / (XMAX - 1);
    dy = ((iymax - iymin) + (YMAX - 2)) / (YMAX - 1);
    d = (dx > dy) ? dx : dy;
    if (d <= 0) return EXIT_FAILURE;
    color[0] = BLACK;  j = WHITE;
    for (i = maxiter; i > 0; i--) {
        color[i] = j;  if (j > 1) j--;
    }
    gr_on();  i = 0;
    for (x = ixmin; x <= ixmax; x += d) {
        j = 0;
        for (y = iymax; y >= iymin; y -= d) {
            a = x;  a2 = a * a;
            b = y;  b2 = b * b;
            count = maxiter;
            while (a2 + b2 <= (4L << 24) && count) {
                b = ((a * b) >> 11) - y;
                a = ((a2 - b2) >> 12) - x;
                a2 = a * a;  b2 = b * b;  count--;
            }
            gr_dot(i, j, color[count]);
            j++;
        }
        i++;
    }
    hitanykey();
    return EXIT_SUCCESS;
}
