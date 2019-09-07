#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
	int date;
	struct node *next;
}node,*pnode;////NODE等价于 struct Node; PNODE等价于struct Node *

pnode create_lk() //生成 
{
	pnode p = (node*)malloc(sizeof(node));//头结点
	pnode temp = p;//temp指向p
	//生成链表
	for(int i=1;i<5;i++)
	{
		pnode a = (node*)malloc(sizeof(node));//动态生成
		a -> date = i;
		a -> next = NULL;
		temp -> next = a;
		temp  = temp ->next; 
	} 
	return p;
}
int long_(pnode p)//查询长度 
{
	int l = 0;
	while(p)
	{
		p = p->next;
		l++;
	}
	return l;
}

pnode inset_lk(pnode p,int i,int x) //在第i个位置插入x这个数 
{
	pnode it = (pnode)malloc(sizeof(pnode));
	pnode num = (pnode)malloc(sizeof(pnode));
	num ->date = x;
	for(int flag = 1;flag<i;flag++)
	{
		p = p->next ;
	}
	it = p->next; 
	p ->next = num;
	num ->next = it;
	return p;
}

pnode delet_lk(pnode p,int i) //在第i个位置删除 
{
	pnode flag = (pnode)malloc(sizeof(pnode));
	pnode temp = (pnode)malloc(sizeof(pnode));
	temp = p;
	
	if(i==0)
	{
		printf("不能删除头结点");
		return p;
	}
	else
	{
		if(i==long_(p))
		{
			while(--i)
			{
				temp = temp->next;
			}
			temp->next = NULL;
			flag = temp->next;
			free(flag);
			return p;
		}
		else
		{
			while(--i)
			{
				temp = temp->next;
			}
			flag = temp ->next;
			temp->next = flag->next ;
			free(flag);
			return p;
		}
	}
}


int main()
{
	pnode p = create_lk();
	p = delet_lk(p,4);
	p = p->next ;
	printf("%d\n",p->date);
	printf("%d",long_(p));
}




 
