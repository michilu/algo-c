/***********************************************************
    dragon2.c -- ドラゴンカーブ
***********************************************************/
#include "plotter.c"          /* ラージモデルでコンパイル */
#define ORDER  10                                 /* 位数 */
enum {RIGHT, LEFT};

int main()
{
    int k, i, p, q, dx, dy, dx1, dy1;
    static char fold[1 << ORDER];

    gr_on();  gr_window(0, 0, 640, 400, 1, 0);
    move(200, 140);
    dx = 0;  dy = 2;  draw_rel(3 * dx, 3 * dy);  p = 0;
    for (k = 1; k <= ORDER; k++) {
        fold[p] = LEFT;  q = 2 * p;
        for (i = p; i <= q; i++) {
            switch (fold[q - i]) {
            case RIGHT:
                fold[i] = LEFT;  dx1 = -dy;  dy1 = dx;
                break;
            case LEFT:
                fold[i] = RIGHT;  dx1 = dy;  dy1 = -dx;
                break;
            }
            draw_rel(dx + dx1, dy + dy1);
            draw_rel(3 * dx1, 3 * dy1);
            dx = dx1;  dy = dy1;
        }
        p = q + 1;
    }
    hitanykey();
    return EXIT_SUCCESS;
}
