# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	int number;
	struct Node *next;
}Lnode,*LinkedList;

LinkedList create(int a){
	Lnode *R,*p,*q;
	int i;
	R =(Lnode*) malloc (sizeof(Lnode));
	q = R;
	for (i = 1; i < a; i ++)
	{
		p = (Lnode*) malloc (sizeof(Lnode));
		q->number = i;
		q->next = p;
		q = p;
	}
	p ->number = a;
	p ->next = R;
	R = p ;
	return R;
}

void find (LinkedList R,int b)
{
	int i;
	Lnode *n;
	
	while (R->next != R) {
		for (i = 1; i < b; i++) {
			R = R->next;
		}
		n = R->next;
		R->next = R->next->next;
		free (n);
	}
	
	printf ("%d",R->number);
}

int main (void)
{
	int a,b;
	printf (" shu ru liang ge shu, yi ge shi hou zi, yi ge shi bao shu");
	scanf ("%d %d",&a,&b);
	LinkedList R = create(a);
	printf ("%d\n",R->number);
	find (R,b);
	return 0;
}
