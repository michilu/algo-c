/***********************************************************
    koch.c -- Koch (コッホ) 曲線
***********************************************************/
#include "plotter.c"  /* ラージモデルでコンパイル */
#include <math.h>
#define PI 3.141592653589793
#define DMAX 0.005
unsigned int a;
double d, costbl[6], sintbl[6];

void koch(void)
{
    if (d <= DMAX)
        draw_rel(d * costbl[a % 6], d * sintbl[a % 6]);
    else {
        d /= 3;  koch();  a++;  koch();
        a += 4;  koch();  a++;  koch();
        d *= 3;
    }
}

int main()
{
    gr_on();  gr_window(0, 0, 2, 1, 1, 0);
    for (a = 0; a < 6; a++) {
        costbl[a] = cos(a * PI / 3);
        sintbl[a] = sin(a * PI / 3);
    }
    move(0, 0);  d = 2;  a = 0;  koch();
    hitanykey();
    return EXIT_SUCCESS;
}
