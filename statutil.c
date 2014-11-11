/***********************************************************
    statutil.c -- ¿���̥ǡ���
***********************************************************/
#include "matutil.c"   /* �����Ѥξ�ƻ�� */
#include <errno.h>     /* {\tt errno} */
#include <limits.h>    /* {\TT INT\_MAX} */
#include <math.h>      /* {\tt fabs()} */
#include <string.h>    /* {\tt strchr()} */

#define READERROR -1.00E+37;  /* �ɹ����顼 */
#define MISSING   -0.98E+37;  /* ��¬�� */
#define readerror(x) ((x) < -0.99E+37)
#define missing(x)   ((x) < -0.97E+37)

double getnum(FILE *datafile)
{
    double x;
    char *rest, s[83];

    do {
        if (fscanf(datafile, "%81s%*[^ \t\n]", s) != 1)
            return READERROR;
    } while (strchr("0123456789+-.", s[0]) == NULL);
    if (s[0] == '.' && s[1] == '\0') return MISSING;
    s[81] = '?';  s[82] = '\0';  x = strtod(s, &rest);
    if (errno == 0 && *rest == '\0' && fabs(x) <= 0.97E+37)
        return x;
    errno = 0;  return READERROR;
}

FILE *open_data(char *filename, int *addr_n, int *addr_m)
{
    FILE *datafile;
    double x, y;

    *addr_n = *addr_m = 0;
    if ((datafile = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "�ǡ����ե����뤬�����ޤ���.\n");
        return NULL;
    }
    x = getnum(datafile);  y = getnum(datafile);
    if (x <= 0 || x > INT_MAX || y <= 0 || y > INT_MAX) {
        fprintf(stderr, "�Կ���������ɤ�ޤ���.\n");
        fclose(datafile);  return NULL;
    }
    *addr_n = (int)x;  *addr_m = (int)y;
    fprintf(stderr, "%d �� %d ��Υǡ����Ǥ�.\n",
        *addr_n, *addr_m);
    return datafile;
}

int read_data(FILE *datafile, int n, int m, matrix x)
{
    int i, j, err;
    unsigned long missings;
    double t;

    err = 0;  missings = 0;
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
        if (err) {  x[j][i] = READERROR;  continue;  }
        t = getnum(datafile);  x[j][i] = (SCALAR)t;
        if (! missing(t)) continue;
        if (readerror(t)) {
            fprintf(stderr, "�ɹ��ߥ��顼(%d,%d)\n", i+1, j+1);
            err = 2;
        } else missings++;
    }
    fprintf(stderr, "�ɹ��߽�λ (��¬�� %lu ��)\n", missings);
    return err | (missings != 0);
}

#ifdef TEST  /* �ʲ��ϻ����� */

int main()
{
    int i, j, n, m;
    matrix x;  /* {\tt matrix} ���� {\tt matutil.c} ����� */
    FILE *datafile;
    char filename[256];

    printf("�ǡ����ե�����̾? ");
    scanf("%255s", filename);
    datafile = open_data(filename, &n, &m);     /* �ǡ����ե�����򳫤� */
    if (datafile == NULL) return EXIT_FAILURE;  /* ���� */
    x = new_matrix(m, n);                       /* ��������� */
    read_data(datafile, n, m, x);               /* �ǡ������ɤ� */
    fclose(datafile);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            if (readerror(x[j][i]))    printf(" E");  /* �ɹ����� */
            else if (missing(x[j][i])) printf(" .");  /* ��¬�� */
            else             printf(" %g", x[j][i]);  /* ���� */
        printf("\n");
    }
    return EXIT_SUCCESS;
}

#endif  /* #ifdef TEST */