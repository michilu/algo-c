/***********************************************************
    meansd2.c --  ø∂—√Õ°¶…∏Ω‡ –∫π
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    float x, s1, s2;

    s1 = s2 = n = 0;
    while (scanf("%f", &x) == 1) {
        n++;  s1 += x;  s2 += x * x;
    }
    s1 /= n;                                  /*  ø∂— */
    s2 = (s2 - n * s1 * s1) / (n - 1);        /*  ¨ª∂ */
    if (s2 > 0) s2 = sqrt(s2);  else s2 = 0;  /* …∏Ω‡ –∫π */
    printf("∏ƒøÙ: %d   ø∂—: %g  …∏Ω‡ –∫π: %g\n", n, s1, s2);
    return EXIT_SUCCESS;
}
