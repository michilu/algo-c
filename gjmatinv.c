/***********************************************************
    gjmatinv.c -- µÕ¹ÔÎó
***********************************************************/
#include "matutil.c"

double matinv(int n, matrix a)
{
    int i, j, k;
    double t, u, det;

    det = 1;
    for (k = 0; k < n; k++) {
        t = a[k][k];  det *= t;
        for (i = 0; i < n; i++) a[k][i] /= t;
        a[k][k] = 1 / t;
        for (j = 0; j < n; j++)
            if (j != k) {
                u = a[j][k];
                for (i = 0; i < n; i++)
                    if (i != k) a[j][i] -= a[k][i] * u;
                    else        a[j][i] = -u / t;
            }
    }
    return det;
}

/************** °Ê²¼¤Ï¥Æ¥¹¥ÈÍÑ *****************/

#include <math.h>
#include <limits.h>

double rnd(void)  /* Íð¿ô  0 < rnd() < 1 */
{
    static unsigned long seed = 123456789UL;  /* ´ñ¿ô */

    return (seed *= 69069UL) / (ULONG_MAX + 1.0);
}

int main()
{
    int i, j, k, n;
    matrix a, b;
    double s, t;

    printf("n = ");  scanf("%d", &n);
    a = new_matrix(n, n);  b = new_matrix(n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = b[i][j] = rnd() - rnd();
    printf("A\n");
    matprint(a, n, 7, "%10.6f");
    s = matinv(n, b);
    printf("¹ÔÎó¼° = %g\n", s);
    printf("A^{-1}\n");
    matprint(b, n, 7, "%10.6f");
    t = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            s = (i == j);
            for (k = 0; k < n; k++)
                s -= a[i][k] * b[k][j];
            t += s * s;
        }
    printf("A A^{-1} ¤ÎÀ®Ê¬¤ÎÆó¾èÊ¿¶Ñ¸íº¹ %g\n",
        sqrt(t / (n * n)));
    t = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            s = (i == j);
            for (k = 0; k < n; k++)
                s -= b[i][k] * a[k][j];
            t += s * s;
        }
    printf("A^{-1} A ¤ÎÀ®Ê¬¤ÎÆó¾èÊ¿¶Ñ¸íº¹ %g\n",
        sqrt(t / (n * n)));
    return EXIT_SUCCESS;
}
