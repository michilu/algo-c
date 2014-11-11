/***********************************************************
    3dgraph.c -- 3次元グラフ
***********************************************************/
#include "plotter.c"             /* ラージモデルでコンパイル */
#include <math.h>

const double Xmin = -1, Ymin = -1, Zmin = -1,  /* 座標の下限 */
             Xmax =  1, Ymax =  1, Zmax =  1;  /* 座標の上限 */

double func(double x, double z)             /* 描く関数 (例) */
{
    double r2;

    r2 = x * x + z * z;
    return exp(-r2) * cos(10 * sqrt(r2));
}

int main()
{
    double x, y, z;
    int i, ix, iz, ok, ok1;
    static float lowerhorizon[241], upperhorizon[241];

    gr_on();  gr_window(0, 0, 240, 130, 1, 0);
    for (i = 0; i <= 240; i++) {
        lowerhorizon[i] =  1e30;  /* 正の無限大 */
        upperhorizon[i] = -1e30;  /* 負の無限大 */
    }
    for (iz = 0; iz <= 20; iz++) {
        z = Zmin + (Zmax - Zmin) / 20 * iz;
        ok1 = 0;
        for (ix = 0; ix <= 200; ix++) {
            x = Xmin + (Xmax - Xmin) / 200 * ix;
            i = ix + 2 * (20 - iz);  /* 0..240 */
            y = 30 * (func(x, z) - Ymin) / (Ymax - Ymin) + 5 * iz; /* 0..130 */
            ok = 0;
            if (y < lowerhorizon[i]) {
                lowerhorizon[i] = y;  ok = 1;
            }
            if (y > upperhorizon[i]) {
                upperhorizon[i] = y;  ok = 1;
            }
            if (ok && ok1) draw(i, y);  else move(i, y);
            ok1 = ok;
        }
    }
    hitanykey();
    return EXIT_SUCCESS;
}
