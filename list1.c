/***********************************************************
    list1.c -- �ꥹ��
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define NIL 100  /* �����ź�� + 1 */
typedef int indextype, infotype;

infotype info[NIL];
indextype next[NIL];

indextype add_list(infotype x, indextype p)
{
    static indextype avail = 0;
    indextype q;

    q = avail++;
    if (q == NIL) {
        printf("���դǤ�.\n");  exit(EXIT_FAILURE);
    }
    info[q] = x;  next[q] = p;
    return q;
}

void show_list(indextype p)
{
    while (p != NIL) {
        printf(" %d", info[p]);  p = next[p];
    }
    printf("\n");
}

indextype reverse_list(indextype p)
{
    indextype q, t;

    q = NIL;
    while (p != NIL) {
        t = q;  q = p;  p = next[p];  next[q] = t;
    }
    return q;
}

int main()
{
    infotype x;
    indextype head;

    head = NIL;                             /* ���Υꥹ�� */
    for (x = 1; x <= 9; x++)
        head = add_list(x, head);                 /* ��Ͽ */
    show_list(head);                              /* ɽ�� */
    head = reverse_list(head);        /* �ս���¤��ؤ��� */
    show_list(head);                              /* ɽ�� */
    return EXIT_SUCCESS;
}
