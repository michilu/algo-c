/***********************************************************
    bifur.c -- カオスとアトラクタ
***********************************************************/
#include "window.c"           /* ラージモデルでコンパイル */

int main()
{
    int i;
    double k, p, dk, kmin, kmax, pmin, pmax;

    printf("kmin = ");  scanf("%lf", &kmin);
    printf("kmax = ");  scanf("%lf", &kmax);
    printf("pmin = ");  scanf("%lf", &pmin);
    printf("pmax = ");  scanf("%lf", &pmax);
    gr_on();  gr_window(kmin, pmin, kmax, pmax, 0, 0);
    dk = (kmax - kmin) / (XMAX - 1);
    for (k = kmin; k <= kmax; k += dk) {
        p = 0.3;
        for (i = 1; i <= 50; i++) p += k * p * (1 - p);
        for (i = 51; i <= 100; i++) {
            if (p >= pmin && p <= pmax)
                gr_wdot(k, p, WHITE);
            p += k * p * (1 - p);
        }
    }
    hitanykey();
    return EXIT_SUCCESS;
}
