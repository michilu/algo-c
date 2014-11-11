/***********************************************************
    endian.c -- エンディアンネス
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 1;
    if (*((char *)&i))
        printf("little-endian\n");
    else if (*((char *)&i + (sizeof(int) - 1)))
        printf("big-endian\n");
    else
        printf("不明\n");
    return EXIT_SUCCESS;
}
