/***********************************************************
    isqrt.c -- 士数含
***********************************************************/

unsigned int isqrt(unsigned int x)
{
    unsigned int s, t;

    if (x == 0) return 0;
    s = 1;  t = x;
    while (s < t) {  s <<= 1;  t >>= 1;  }
    do {
        t = s;
        s = (x / s + s) >> 1;
    } while (s < t);
    return t;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int i;
    unsigned long s;

    printf("腊眶の士数含のテスト面\n");
    i = 0;
    do {
        if ((i & 0x3fff) == 0) printf("i = %u\n", i);
        s = isqrt(i);
        if (s * s > i || (s + 1) * (s + 1) <= i) {
            printf("Error: i = %u, isqrt(i) = %lu\n", i, s);
            break;
        }
    } while (++i != 0);
    printf("テスト窗位\n");
    return EXIT_SUCCESS;
}
