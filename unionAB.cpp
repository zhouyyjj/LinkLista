//已知集合A、B，编写一个算法求A=A ∩B，A=A ∪B。
/*
	解题思路：分别用两个带头结点的单链表存储集合A和B， 
	A ∩B就是A和B中都存在	的元素，方法是删除单链表A中所有没有在B中出现的元素。
	A ∪B就是A或B中存在的元素，方法是将单链表B中所有不在A中出现的元素加入到A中。 
	 
*/ 
//求集合A和B的交集，入口参数：指向集合A和集合B的指针，返回值：无 
#include<stdio.h>
#include<malloc.h> 

typedef int DataType;

//定义链表 
typedef struct node{
	DataType date;
	struct node *next;//存放节点的位置 
}LNode,*LinkList;

//创建空链表
LinkList Creat_LinkList(viod)
{
	LinkList H;//创建一个头节点
	H=(LinkList)malloc(sizeof(LNode))
	if(H)
	H->next=NULL;
	return H; 
	
}

//查找操作，1.按序号查找 
LinkList Locate_LinkList_Pos(LinkList H, int i)
{
	LinkList p = H;
	int j = 0;

	while(p && j<i)
	{
		p = p->next;
		j++;
	}
	if (j!=i || !p)
	{
		printf("参数i出错或单链表不存在");
		return NULL;
	}
	return p;
}
//查找操作，2.按值查找 
LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	
	while(p && p->data != x)
	{
		p = p->next;
	}
	return p;
}

//插入：在单链表 的第i个位置前插入一个值为x的新结点 
int Insert_LinkList(LinkList H,int i,DataType x){
	LinkList p,q;
	p=Locate_LinkList_Pos(H,i-1);
	if(!p){
		return -1;
	}
	q=(LinkList)malloc(sizeof(LNode));
	if(!q){
		
		return 0;
	}
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 1;
}

//删除 第i个结点
int Del_LinkList(LinkList H,int i){
	LinkList p,q;
	if(H==NULL||H->next==NULL) {
		printf("单链表不存在或空表不能删除");
		return 0;
	}
	p = Locate_LinkList_Pos(H,i-1);//找第i-1个结点地址
	if(p==NULL||p->next==NULL){
		printf("参数i错误");
		return 0;
	} 
	q=p->next;
	p->next=q->next;
	free(q);
	return 1;
} 
 
//销毁单链表 
void Destroy_LinkList(LinkList *H){
	
	LinkList p,q;
	p = *H;
	while(p){
		q=p;
		p=p->next;
		free(q);
	}
	*H=NULL;
}
void print_LinkList(LinkList H)
{
	LinkList p;
	
	if(H == NULL || H->next == NULL)
	{
		printf("链表不存在或链表为空");
		return;
	}

	printf("链表中数据为：\n");
	p = H->next;
	while(p)
	{
		printf("%4d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void Insert_sec(LinkList A,LinkList B){
	LinkList pre,p;
	pre = A;
	p = pre->next;	/*刚开始pre指向头结点，p指向第一个链表结点*/ 
	int x;
	while(p){
		x = p->data;
		if(!Locate_LinkList_Value(B,x)){	/*集合B中没有x*/ 
			pre->next=p->next;
			free(p);
			p=pre->next;
		}
		else{
			pre = p;
			p = p->next;	/*考察下一个结点*/
		}
	} 
}
/*求集合A和B的并集，入口参数：入口参数：指向集合A和B的指针，返回值：无*/
void Merge_sec(LinkList A,LinkList B){
	int x;
	LinkList p;	/*初始p指向第一个结点*/ 
	p=B->next;
	while(p){
		x = p->data;
		if(!Locate_LinkList_Value(A,x)) /*集合A中没有x*/ 
			Insert_LinkList(A,1,x);	/*将集合B中有而集合A中没有的元素加入到集合A中*/
		
		p=p->next;
	}
} 

//创建空的循环单链表 
LinkList Creat_LinkList_H(void){
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if(H)
		H->next=H;
	return H;
}
//插入：在循环单链表的第尾部插入一个值为x的新结点 
int Insert_LinkList_H(LinkList H){
	LinkList p,q;
	int i,x;
	p=H;	
	scanf("%d",&x);
	p->data=x;
	p->next=H;
	for(i=1;i<10;i++){
		q=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&x);
		q->data=x;
		q->next=p->next;
		p->next=q;
		p=q; 
	}
	

	
	return 1;
}
void print_LinkList_H(LinkList H)
{
	LinkList p;

	printf("链表中数据为：\n");
	p = H;
	while(p->next!=H)
	{
		printf("%4d ", p->data);
		p = p->next;
	}
	printf("%4d ", p->data);
	printf("\n");
}

