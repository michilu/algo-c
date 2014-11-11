/***********************************************************
    lorenz.c -- Lorenz (ローレンツ) アトラクタ
***********************************************************/
#include "plotter.c"  /* ラージモデルでコンパイル */

#define A  10.0
#define B  28.0
#define C  (8.0 / 3.0)
#define D  0.01

int main()
{
    int k;
    double x, y, z, dx, dy, dz;

    gr_on();  gr_window(-30, 0, 30, 60, 1, GREEN);
    x = y = z = 1;
    for (k = 0; k < 3000; k++) {
        dx = A * (y - x);
        dy = x * (B - z) - y;
        dz = x * y - C * z;
        x += D * dx;  y += D * dy;  z += D * dz;
        if (k > 100) draw(x, z);  else move(x, z);
    }
    hitanykey();
    return EXIT_SUCCESS;
}
