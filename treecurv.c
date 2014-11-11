/***********************************************************
    treecurv.c -- 樹木曲線
***********************************************************/
#include "plotter.c"  /* ラージモデルでコンパイル */
#include <math.h>  /* sin(), cos() */
#define FACTOR  0.7
#define TURN    0.5

void tree(int n, double length, double angle)
{
    double dx, dy;

    dx = length * sin(angle);  dy = length * cos(angle);
    draw_rel(dx, dy);
    if (n > 0) {
        tree(n - 1, length * FACTOR, angle + TURN);
        tree(n - 1, length * FACTOR, angle - TURN);
    }
    move_rel(-dx, -dy);
}

int main()
{
    int order;

    printf("位数 = ");  scanf("%d", &order);
    gr_on();  gr_window(0, 0, 6, 4, 1, GREEN);
    move(3, 0);  tree(order, 1, 0);
    hitanykey();
    return EXIT_SUCCESS;
}
