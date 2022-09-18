#include"LinkStack.h"
#include"stdio.h"
#include"malloc.h"

//��ʼ����ջ
PLinkStack Init_LinkStack(){
	PLinkStack S;
	S=(PLinkStack)malloc(sizeof(LinkStack));
	if(S)
		S->top=NULL;
	return S;
}
//��ջ��
int Empty_LinkStack(PLinkStack S){
	return(S->top==NULL);
}
//��ջ
int Push_LinkStack(PLinkStack S,DataType x){
	PStackNode p;
	p = (PStackNode)malloc(sizeof(StackNode));
	if(!p){
		printf("�ڴ����");
		return 0;
	}
	p->data=x;
	p->next=S->top;
	S->top=p;
	return 1;
}
//��ջ
int Pop_LinkStack(PLinkStack S,DataType *x){
	PStackNode p;
	if(Empty_LinkStack(S)){
		printf("ջ�գ����ܳ�ջ ");
		return 0;
	}
	*x = S->top->data;
	p=S->top;
	S->top=S->top->next;
	free(p);
	return 1;
}
//ȡ��ջ��Ԫ��
int Get_LinkStack(PLinkStack S){
	int	x;
	if(Empty_LinkStack(S)){
		printf("ջ�� ");
		return 0;
	}
	x = S->top->data;
	return S->top->data;
}
//����ջ
void Destory_LinkStack(PLinkStack *S){
	PStackNode p,q;
	if(*S){
		p=(*S)->top;
		while(p){
			q=p;
			p=p->next;
			free(q);
		}
		*S=NULL;
		//*LS=NULL;
		return;
	}
}
//
void Print_LinkStack(PLinkStack S){
	PStackNode p;
	if(Empty_LinkStack(S)){
		printf("ջ�� ");
		return ;
	}else{
		p=S->top;
		while(p){
			printf("%d%\n",p->data);
			p = p->next;
		}
			return ;
	}

}