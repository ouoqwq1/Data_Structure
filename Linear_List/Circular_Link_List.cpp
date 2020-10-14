#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define bool int
#define true 1
#define false 0
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkNode;
void InitList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = L;
    L->data = 0;
}
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s, *r;
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    L->data = n; //Head L->data = length of the entire Linear List
    r->next = L;
}
bool InsertionSort(LinkNode *L) //use the insertion sort to sort the linear list
{
    int i = 1, temp;
    LinkNode *r = L;
    if (r->next == L)
        return false;
    while (i < L->data)
    {
        r = L->next;
        for (int j = 0; j <= L->data - i; j++)
        {
            if (r->next == L)
                break;
            if (r->data > r->next->data)
            {
                temp = r->data;
                r->data = r->next->data;
                r->next->data = temp;
            }
            r = r->next;
        }
        ++i;
    }
    return true;
}
LinkNode *LocateElement(LinkNode *L, ElemType e)
{
    LinkNode *r = L->next;
    if (r->next == L)
        return L;
    while (1)
    {
        if (r->data == e || r == L)
            break;
        r = r->next;
    }
    return r;
}
bool InsertElement(LinkNode *L, ElemType e)
{
    LinkNode *r = L, *s;
    if (r->next == L)
        return false;
    s = (LinkNode *)malloc(sizeof(LinkNode));
    ++L->data;
    if (e <= r->next->data)
    {
        s->data = e;
        s->next = r->next;
        L->next = s;
        return true;
    }
    r = L->next;
    while (r->next != L)
    {
        if (e <= r->next->data)
        {
            s->data = e;
            s->next = r->next;
            r->next = s;
            return true;
        }
        r = r->next;
    }
    s->data = e;
    s->next = L;
    r->next = s;
    return true;
}
bool DeleteElement(LinkNode *&L, ElemType e)
{
    LinkNode *temp, *p = L;
    if (p->next == L)
        return false;
    while (p->next != L)
    {
        if (p->next->data == e)
        {
            temp = p->next;
            p->next = p->next->next;
            free(temp);
            --L->data;
        }
        else
        {
            p = p->next;
            if (e < p->data)
                return true;
        }
    }
    return true;
}
bool ModifyElement(LinkNode *L, ElemType e, ElemType new_e)
{
    if (DeleteElement(L, e) == 0)
        return false;
    InsertElement(L, new_e);
    return true;
}
bool GetList(LinkNode *L, LinkNode *L1, int low, int high)
{
    LinkNode *p = L, *s = L1;
    if (p->next == L || p->next->data > high)
        return false;
    p = p->next;
    while (p->data < low)
    {
        p = p->next;
        if (p == L)
            return false;
    }
    while (p->data <= high)
    {
        s->next = (LinkNode *)malloc(sizeof(LinkNode));
        s->next->data = p->data;
        ++L1->data;
        p = p->next;
        if (p == L)
        {
            s->next = L1;
            return true;
        }
        s = s->next;
    }
    return true;
}
bool DisList(LinkNode *L)
{
    LinkNode *p = L;
    if (p->next == L)
        return false;
    p = p->next;
    while (p != L)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return true;
}
int main()
{
    LinkNode *rear, *New;
    ElemType a[] = {11, 22, 33, 78, 99, 99, 23, 44, 45, 55, 66, 77}, e;
    InitList(rear);
    InitList(New);
    CreateListR(rear, a, 12);
    printf("  rear:");
    DisList(rear);
    InsertionSort(rear);
    printf("After sort \n  rear:");
    DisList(rear);
    InsertElement(rear, 1);
    printf("  rear:");
    DisList(rear);
    InsertElement(rear, 67);
    printf("  rear:");
    DisList(rear);
    InsertElement(rear, 100);
    printf("  rear:");
    DisList(rear);
    InsertElement(rear, 102);
    printf("  rear:");
    DisList(rear);
    DeleteElement(rear, 102);
    printf("  rear:");
    DisList(rear);
    DeleteElement(rear, 99);
    printf("  rear:");
    DisList(rear);
    InsertElement(rear, 2);
    printf("  rear:");
    DisList(rear);
    ModifyElement(rear, 66, 2);
    printf("  rear:");
    DisList(rear);
    GetList(rear, New, 3, 105);
    printf("  New:");
    DisList(New);
    return 0;
}
