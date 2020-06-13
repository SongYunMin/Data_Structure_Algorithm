#include <stdio.h>  
#include <stdlib.h>  
typedef struct Listnode {
    float coef;
    int expo;
    struct Listnode* link;
}Listnode;
typedef struct Listhead {
    Listnode* head;
}Listhead;
Listhead* createlinkedlist(void)
{
    Listhead* L;
    L = (Listhead*)malloc(sizeof(Listhead));
    L->head = NULL;
    return L;
}
void addlastnode(Listhead* L, float coef, int expo)
{
    Listnode* newnode;
    Listnode* p;
    newnode = (Listnode*)malloc(sizeof(Listnode));
    newnode->coef = coef;
    newnode->expo = expo;
    newnode->link = NULL;
    if (L->head == NULL)
    {
        L->head = newnode;
        return;
    }
    else
    {
        p = L->head;
        while (p->link != NULL)
        {
            p = p->link;
        }
    }
    p->link = newnode;
}
void mulpoly(Listhead* a, Listhead* b, Listhead* c)
{
    Listnode* pa = a->head;
    Listnode* pb = b->head;
    float sum;
    int exposum;
    while (pa)
    {
        while (pb)
        {
            sum = pa->coef * pb->coef;
            exposum = pa->expo + pb->expo;
            addlastnode(c, sum, exposum);
            pb = pb->link;
        }
        pa = pa->link;
        pb = b->head;
    }
}
void printpoly(Listhead* L)
{
    Listnode* p = L->head;
    for (; p; p = p->link)
    {
        printf("%3.0fx^%d", p->coef, p->expo);
    }
}
void main()
{
    Listhead* a, * b, * c;
    a = createlinkedlist();
    b = createlinkedlist();
    c = createlinkedlist();
    addlastnode(a, 3, 1);
    addlastnode(a, 5, 0);
    printf("\n a(x)=");
    printpoly(a);
    addlastnode(b, 2, 1);
    addlastnode(b, 1, 0);
    printf("\n b(x)=");
    printpoly(b);
    mulpoly(a, b, c);
    printf("\n c(x)=");
    printpoly(c);
}