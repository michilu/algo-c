/***********************************************************
    sierpin.c -- Sierpi\'{n}ski (シェルピンスキー) 曲線
***********************************************************/
#include "plotter.c"  /* ラージモデルでコンパイル */
double h;  /* 刻み幅 */

void urd(int i), lur(int i), dlu(int i), rdl(int i);  /* 後出 */

void urd(int i)  /* up-right-down */
{
    if (i == 0) return;
    urd(i - 1);  draw_rel(h, h);
    lur(i - 1);  draw_rel(2 * h, 0);
    rdl(i - 1);  draw_rel(h, -h);
    urd(i - 1);
}

void lur(int i)  /* left-up-right */
{
    if (i == 0) return;
    lur(i - 1);  draw_rel(-h, h);
    dlu(i - 1);  draw_rel(0, 2 * h);
    urd(i - 1);  draw_rel(h, h);
    lur(i - 1);
}

void dlu(int i)  /* down-left-up */
{
    if (i == 0) return;
    dlu(i - 1);  draw_rel(-h, -h);
    rdl(i - 1);  draw_rel(-2 * h, 0);
    lur(i - 1);  draw_rel(-h, h);
    dlu(i - 1);
}

void rdl(int i)  /* right-down-left */
{
    if (i == 0) return;
    rdl(i - 1);  draw_rel(h, -h);
    urd(i - 1);  draw_rel(0, -2 * h);
    dlu(i - 1);  draw_rel(-h, -h);
    rdl(i - 1);
}

int main()
{
    int i, order;

    printf("位数 = ");  scanf("%d", &order);
    gr_on();  gr_window(0, 0, 6, 6, 1, 0);
    h = 1;
    for (i = 2; i <= order; i++) h = 3 * h / (6 + h);
    move(h, 0);
    urd(order);  draw_rel( h,  h);
    lur(order);  draw_rel(-h,  h);
    dlu(order);  draw_rel(-h, -h);
    rdl(order);  draw_rel( h, -h);
    hitanykey();
    return EXIT_SUCCESS;
}
