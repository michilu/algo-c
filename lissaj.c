/***********************************************************
    lissaj.c -- Lissajous (リサジュー) 図形
***********************************************************/
#include "plotter.c"  /* ラージモデルでコンパイル */
#include <math.h>  /* sin, cos */
#define PI 3.141592653589793

int main()
{
    int i;
    double t;

    gr_on();
    gr_window(-1, -1, 1, 1, 1, 0);  /* 座標指定 */
    move(cos(0), sin(0));  /* 初期ペン位置 */
    for (i = 1; i <= 360; i++) {
        t = (PI / 180) * i;
        draw(cos(3 * t), sin(5 * t));  /* ペン移動 */
    }
    hitanykey();
    return EXIT_SUCCESS;
}
