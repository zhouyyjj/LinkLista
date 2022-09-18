#include"SeqStack.h"
#include "stdio.h"
#include"malloc.h"
//��ʼ����ջ 
PSeqStack Init_SeqStack(){
	PSeqStack S;
	S=(PSeqStack)malloc(sizeof(SeqStack));
	if(S)
		S->top=-1;
	return S;
}
//��ջ��
int Empty_SeqStack(PSeqStack S){
	if(S->top==-1)
		return 1;
	else
		return 0;
}
//��ջ 
int Push_SeqStack(PSeqStack S,DataType x){
	if(S->top==MAXSIZE-1)
		return 0;		//ջ��������ջ 
	else{
		S->top++;
		S->data[S->top]=x;
		return 1;
	}
}
//��ջ
int Pop_SeqStack(PSeqStack S,DataType *x){
	if(Empty_SeqStack(S))
		return 0;		//ջ�ղ��ܳ�ջ 
	else{
		*x = S->data[S->top];
		S->top--;
		return 1;
	}
}
//��ջ����ӡ
int Pop_SeqStack_1(PSeqStack S){
	int i=0;
	if(Empty_SeqStack(S))
		return 0;		//ջ�ղ��ܳ�ջ 
	else{
		while(S->top!=-1){
		//	x = S->data[S->top];			
			printf("��ջԪ����:%d\n",S->data[S->top]);
			S->top--;
		}
		
		return 1;
	}
}
//ȡ��ջ��Ԫ��
int GetTop_SeqStack(PSeqStack S,DataType *x){
	if(Empty_SeqStack(S))
		return 0;		//����ջ����Ϣ
	else{
		*x = S->data[S->top];	//ջ��Ԫ�ش���*x��
		return *x;
	}
}
int GetTop_SeqStack_1(PSeqStack S){
	if(Empty_SeqStack(S))
		return 0;		//����ջ����Ϣ
	else{
		
		return S->data[S->top];
	}
}
//����ջ 
void Destroy_SeqStack(PSeqStack *S){
	if(*S)
		free(*S);
	*S=NULL;
	return;
}
//��ӡջ��Ԫ�� 
int Print_SeqStack(PSeqStack S){
	int i;
	if(Empty_SeqStack(S))
		return 0;	
	else{
		for(i=0;i<=S->top;i++)
			printf("%d ",S->data[i]);
		return 1;
	}
	
}