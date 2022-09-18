#include"SeqStack.h"
#include "stdio.h"
#include"malloc.h"
//初始化空栈 
PSeqStack Init_SeqStack(){
	PSeqStack S;
	S=(PSeqStack)malloc(sizeof(SeqStack));
	if(S)
		S->top=-1;
	return S;
}
//判栈空
int Empty_SeqStack(PSeqStack S){
	if(S->top==-1)
		return 1;
	else
		return 0;
}
//入栈 
int Push_SeqStack(PSeqStack S,DataType x){
	if(S->top==MAXSIZE-1)
		return 0;		//栈满不能入栈 
	else{
		S->top++;
		S->data[S->top]=x;
		return 1;
	}
}
//出栈
int Pop_SeqStack(PSeqStack S,DataType *x){
	if(Empty_SeqStack(S))
		return 0;		//栈空不能出栈 
	else{
		*x = S->data[S->top];
		S->top--;
		return 1;
	}
}
//出栈并打印
int Pop_SeqStack_1(PSeqStack S){
	int i=0;
	if(Empty_SeqStack(S))
		return 0;		//栈空不能出栈 
	else{
		while(S->top!=-1){
		//	x = S->data[S->top];			
			printf("出栈元素是:%d\n",S->data[S->top]);
			S->top--;
		}
		
		return 1;
	}
}
//取出栈顶元素
int GetTop_SeqStack(PSeqStack S,DataType *x){
	if(Empty_SeqStack(S))
		return 0;		//给出栈空信息
	else{
		*x = S->data[S->top];	//栈顶元素存入*x中
		return *x;
	}
}
int GetTop_SeqStack_1(PSeqStack S){
	if(Empty_SeqStack(S))
		return 0;		//给出栈空信息
	else{
		
		return S->data[S->top];
	}
}
//销毁栈 
void Destroy_SeqStack(PSeqStack *S){
	if(*S)
		free(*S);
	*S=NULL;
	return;
}
//打印栈中元素 
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