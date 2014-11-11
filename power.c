/***********************************************************
    power.c -- Îß¾è
***********************************************************/
#include <stdio.h>   /* fprintf() */
#include <stdlib.h>  /* abs() */
#include <math.h>    /* exp(), log() */
#include <limits.h>  /* INT_MAX */

double ipower(double x, int n)  /* À°¿ô¾è */
{
    int abs_n;
    double r;

    abs_n = abs(n);  r = 1;
    while (abs_n != 0) {
        if (abs_n & 1) r *= x;
        x *= x;  abs_n >>= 1;
    }
    if (n >= 0) return r;  else return 1 / r;
}

double power(double x, double y)  /* Îß¾è */
{
    if (y <= INT_MAX && y >= -INT_MAX && y == (int)y)
        return ipower(x, y);
    if (x > 0)
        return exp(y * log(x));
    if (x != 0 || y <= 0)
        fprintf(stderr, "power: domain error\n");
    return 0;
}

int main()
{
    double x, y;

    printf("x, y = ");  scanf("%lf%lf", &x, &y);
    printf("power(%g, %g) = %g\n", x, y, power(x, y));
    return EXIT_SUCCESS;
}
