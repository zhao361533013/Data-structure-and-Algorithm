#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
}Node,* pNode;

typedef struct stack
{
    pNode Top;
    pNode Bottom;
}Stack, *pStack;

void init(pStack n)
{
    n->Top = (pNode)malloc (sizeof(Node));
    if (n->Top == NULL)
    {
        printf("分配内存失败");
    }
    else
    {
       n->Bottom = n->Top;
       n->Top->next = NULL;
    }
}

int push(pStack n,int data){
    pNode pNew = (pNode)malloc (sizeof(pNode));
    if(pNew == NULL)
    {
        return 0;
    }
    pNew->data = data;
    pNew->next = n->Top;
    n->Top = pNew;
    return 1;
}

int  Empty (pStack n )
{
    if (n->Top == n->Bottom){
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(pStack n )
{
    pNode pSwap = NULL;
    int returnnum;
    if (Empty(n))
    {
        exit (-1);
    }

    else{
        returnnum = n->Top->data;
        pSwap = n->Top;
        n->Top = n->Top->next;
        free (pSwap);
        return returnnum;
    }
}
 void Clear (pStack n)
 {
     pNode newp =NULL;
     while (n->Top != n->Bottom)
     {
         newp = n->Top;
         n->Top = n->Top->next;
         free (newp);
     }

 }
 void  bianli (pStack n)
 {
     pNode newp = n->Top;
     while (newp != n-> Bottom)
     {
         printf("%d",newp->data);
         newp = newp->next;
     }
    printf ("\n");
 }


int main(void)
{
    int a,i,o;
    Stack n;
    init(&n);
    printf ("input the stack number\n");
    scanf("%d",&a);
    for (i=0;i<a;i++)
    {
        printf ("input data\n");
        scanf("%d",&o);
        push (&n,o);
    }
    bianli(&n);
    pop (&n);
    bianli (&n);
    Clear (&n);
    bianli (&n);
    return 0;
}
