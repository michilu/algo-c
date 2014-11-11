/***********************************************************
    mandel.c -- Mandelbrot (マンデルブロート) 集合
***********************************************************/
#include "gr98.c"  /* または "grega.c".  ラージモデルでコンパイル */
#define M  1000

int main()
{
    int i, j, imax, jmax, maxiter, count;
    double xmin, xmax, ymin, ymax,
           x, y, a, b, a2, b2, dx, dy;
    static int color[M + 1];

    printf("xmin = ");  scanf("%lf", &xmin);
    printf("xmax = ");  scanf("%lf", &xmax);
    printf("ymin = ");  scanf("%lf", &ymin);
    printf("ymax = ");  scanf("%lf", &ymax);
    printf("maxiter = ");  scanf("%d", &maxiter);
    dx = xmax - xmin;  dy = ymax - ymin;
    if (dx <= 0 || dy <= 0 || maxiter <= 0 || maxiter > M)
        return EXIT_FAILURE;
    if (dx * YMAX > dy * XMAX) {
        imax = XMAX;  jmax = (int)(XMAX * dy / dx + 0.5);
    } else {
        imax = (int)(YMAX * dx / dy + 0.5);  jmax = YMAX;
    }
    dx /= imax;  dy /= jmax;
    color[0] = BLACK;  j = WHITE;
    for (i = maxiter; i > 0; i--) {
        color[i] = j;  if (j > 1) j--;
    }
    gr_on();
    for (i = 0; i <= imax; i++) {
        x = xmin + i * dx;
        for (j = 0; j <= jmax; j++) {
            y = ymax - j * dy;  a = x;  b = y;
            a2 = a * a;  b2 = b * b;  count = maxiter;
            while (a2 + b2 <= 4 && count) {
                b = 2 * a * b - y;  a = a2 - b2 - x;
                a2 = a * a;  b2 = b * b;  count--;
            }
            gr_dot(i, j, color[count]);
        }
    }
    hitanykey();
    return EXIT_SUCCESS;
}
