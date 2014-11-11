/***********************************************************
    window.c -- グラフィックス
***********************************************************/
/* 座標変換 */

#include <math.h>
#include "line.c"

static double
    gr_xfac = 1, gr_yfac = 1, gr_xconst = 0, gr_yconst = 0;
#define gr_xscr(x) (int)(gr_xfac * (x) + gr_xconst)
#define gr_yscr(y) (int)(gr_yfac * (y) + gr_yconst)

void gr_wdot(double x, double y, int color)
    /* gr_window() で定めた座標で点 (x, y) に
       色 color (= 0..maxcolor) をつける */
{
    gr_dot((unsigned int)(gr_xscr(x)),
           (unsigned int)(gr_yscr(y)), color);
}

void gr_wline(double x1, double y1,
              double x2, double y2, int color)
    /* gr_window() で定めた座標で点 (x1, y1), (x2, y2)
       を結ぶ線分を色 color (= 0..maxcolor) で描く */
{
    gr_line(gr_xscr(x1), gr_yscr(y1),
            gr_xscr(x2), gr_yscr(y2), color);
}

void gr_window(double left,  double bottom,
               double right, double top,
               int samescale, int bordercolor)
    /* 窓の左・下・右・上端の座標を指定する.
       samescale ≠ 0 なら上下と左右の尺度を同じにする.
       bordercolor ≠ 0 ならその色で枠を描く */
{
    gr_xfac = (XMAX - 1) / (right - left);
    gr_yfac = (YMAX - 1) / (bottom - top);
    if (samescale) {
        if (fabs(gr_xfac) > fabs(gr_yfac))
              gr_xfac *= fabs(gr_yfac / gr_xfac);
        else  gr_yfac *= fabs(gr_xfac / gr_yfac);
    }
    gr_xconst = 0.5 - gr_xfac * left;
    gr_yconst = 0.5 - gr_yfac * top;
    if (bordercolor) {
        gr_wline(left , bottom, left , top   , bordercolor);
        gr_wline(left , top   , right, top   , bordercolor);
        gr_wline(right, top   , right, bottom, bordercolor);
        gr_wline(right, bottom, left , bottom, bordercolor);
    }
}
