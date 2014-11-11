/***********************************************************
    hilbert.c -- Hilbert (ヒルベルト) 曲線
***********************************************************/
#include "plotter.c"  /* ラージモデルでコンパイル */
double h;  /* 刻み幅 */

void rul(int i), dlu(int i), ldr(int i), urd(int i);  /* 後出 */

void rul(int i)  /* right-up-left */
{
    if (i == 0) return;
    urd(i - 1);  draw_rel( h, 0);
    rul(i - 1);  draw_rel( 0, h);
    rul(i - 1);  draw_rel(-h, 0);
    dlu(i - 1);
}

void dlu(int i)  /* down-left-up */
{
    if (i == 0) return;
    ldr(i - 1);  draw_rel( 0, -h);
    dlu(i - 1);  draw_rel(-h,  0);
    dlu(i - 1);  draw_rel( 0,  h);
    rul(i - 1);
}

void ldr(int i)  /* left-down-right */
{
    if (i == 0) return;
    dlu(i - 1);  draw_rel(-h,  0);
    ldr(i - 1);  draw_rel( 0, -h);
    ldr(i - 1);  draw_rel( h,  0);
    urd(i - 1);
}

void urd(int i)  /* up-right-down */
{
    if (i == 0) return;
    rul(i - 1);  draw_rel( 0,  h);
    urd(i - 1);  draw_rel( h,  0);
    urd(i - 1);  draw_rel( 0, -h);
    ldr(i - 1);
}

int main()
{
    int i, order;

    printf("位数 = ");  scanf("%d", &order);
    gr_on();  gr_window(0, 0, 1, 1, 1, 0);
    h = 1;
    for (i = 2; i <= order; i++) h = h / (2 + h);
    move(0, 0);  rul(order);
    hitanykey();
    return EXIT_SUCCESS;
}
