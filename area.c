/***********************************************************
    area.c -- ллюя
***********************************************************/

double area(int n, float x[], float y[])
{
    int i;
    double a;

    a = x[n - 1] * y[0] - x[0] * y[n - 1];
    for (i = 1; i < n; i++)
        a += x[i - 1] * y[i] - x[i] * y[i - 1];
    return 0.5 * a;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    static float x[4] = { 1, 3, 2, 0 }, y[4] = { 1, 2, 4, 2 };
    printf("ллюя = %g\n", area(4, x, y));
    return EXIT_SUCCESS;
}
