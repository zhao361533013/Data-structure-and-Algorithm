#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
**链表节点的定义
*/
typedef struct  Node{
int data;//数据域
struct Node * PNext;//指针域，存放下一个节点的地址
} Node ,* PNode ;
/**
**创建链表
*/
PNode create_list()
{
		int len,i;
		printf("请输入链表的长度：len=\n");
		scanf("%d",&len);
		PNode PHead=malloc(sizeof(Node));
		PHead->PNext=NULL;
		PNode PTail=PHead;//PTail是永远指向尾节点的指针
		for(i=0;i<len;i++)
		{
				int val;
				printf("请输入第 %d 个元素的值：", i+1);
				scanf("%d",&val);
				PNode PNew=malloc(sizeof(Node));
				PNew->data=val;
				PNew->PNext=NULL;
				PTail->PNext=PNew;
				PTail=PNew;
		}
		return PHead;

}

/**
**对链表进行遍历
*/
void traverse(PNode pHead)
{
	 PNode p=pHead->PNext;
	 while(p!=NULL)
	 {
			 printf("%d    ",p->data);
			 p=p->PNext;
	 }
	 printf("\n");
}
/**
*判断链表是否为空
*/

bool isempty(PNode pHead)
{
		if(NULL==pHead->PNext)
		{
						return true;
		}else{
		return false;
		}
}

/**
**获取链表的长度
*/
int list_num (PNode pHead)
{
	int num=0;
	PNode p=pHead->PNext;
	while(p!=NULL)
	{
			num++;
			p=p->PNext;
	}
	return  num;
}

bool insert(PNode PHead,int val,int pos){
	int i = 0;
	PNode p = PHead;
	while (NULL != p &&i < pos -1)
	{
		i++;
		p=p->PNext;
	}
	if (i>pos-1||NULL == p)
	{
		printf ("False");
		return false;
	}
	
	PNode PNew=malloc(sizeof(PNode));
	PNew->data=val;
	PNode temp=p->PNext;
	p->PNext=PNew;
	PNew->PNext=temp;
	return true;
}

delete (PNode PHead,int pos)
{
	int i=0;
	PNode p=PHead;
	//我们要删除p后面的节点，所以p不能指向最后一个节点 p->next!=NULL
	while(p->PNext!=NULL&&i<pos-1){

		p=p->PNext;
		i++;
	}
	if(i>pos-1||p->PNext==NULL)
	{
		printf("删除位置不合法\n");
	 	return false;
	}
   PNode temp=p->PNext;
   p->PNext=temp->PNext;
   free(temp);
	printf ("%d",i);

}
int main()
{

 PNode PHead= create_list();
if(isempty(PHead))
printf("链表为空\n");
printf("链表的长度为：%d\n",list_num(PHead));
traverse(PHead);
//insert_list(PHead,55,1);

 delete(PHead,6);
traverse(PHead);
return 0;
}
