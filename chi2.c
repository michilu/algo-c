/***********************************************************
    p_chi2.c -- ¥«¥¤2¾èÊ¬ÉÛ
***********************************************************/
#include <math.h>

#define PI 3.14159265358979323846264

double p_nor(double z)  /* Àµµ¬Ê¬ÉÛ¤Î²¼Â¦ÎßÀÑ³ÎÎ¨ */
{
    int i;
    double z2, prev, p, t;

    z2 = z * z;
    t = p = z * exp(-0.5 * z2) / sqrt(2 * PI);
    for (i = 3; i < 200; i += 2) {
        prev = p;  t *= z2 / i;  p += t;
        if (p == prev) return 0.5 + p;
    }
    return (z > 0);
}

double q_nor(double z)  /* Àµµ¬Ê¬ÉÛ¤Î¾åÂ¦ÎßÀÑ³ÎÎ¨ */
{
    return 1 - p_nor(z);
}

double q_chi2(int df, double chi2)  /* ¾åÂ¦ÎßÀÑ³ÎÎ¨ */
{
    int k;
    double s, t, chi;

    if (df & 1) {  /* ¼«Í³ÅÙ¤¬´ñ¿ô */
        chi = sqrt(chi2);
        if (df == 1) return 2 * q_nor(chi);
        s = t = chi * exp(-0.5 * chi2) / sqrt(2 * PI);
        for (k = 3; k < df; k += 2) {
            t *= chi2 / k;  s += t;
        }
        return 2 * (q_nor(chi) + s);
    } else {      /* ¼«Í³ÅÙ¤¬¶ö¿ô */
        s = t = exp(-0.5 * chi2);
        for (k = 2; k < df; k += 2) {
            t *= chi2 / k;  s += t;
        }
        return s;
    }
}

double p_chi2(int df, double chi2)  /* ²¼Â¦ÎßÀÑ³ÎÎ¨ */
{
    return 1 - q_chi2(df, chi2);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    double chi2;

    printf("***** p_chi2(df, chi2) *****\n");
    printf("chi2   %-16s %-16s %-16s %-16s\n",
        "df=1", "df=2", "df=5", "df=20");
    for (i = 0; i < 20; i++) {
        chi2 = 0.5 * i;
        printf("%4.1f %16.14f %16.14f %16.14f %16.14f\n",
            chi2, p_chi2(1, chi2), p_chi2(2, chi2),
                  p_chi2(5, chi2), p_chi2(20, chi2));
    }
    return EXIT_SUCCESS;
}
