#include"LinkStack.h"
#include"SeqStack.h"
#include "stdio.h"
#include "malloc.h"

//顺序栈

main(){
	int i;
	int x=0;
	PSeqStack S;
	S = Init_SeqStack();
	
	for(i=0;i<5;i++){
	//	scanf("%d",&x);
		Push_SeqStack(S,i+3);
	}
	//打印栈中元素
	Print_SeqStack(S);
	//出栈		
//	Pop_SeqStack(S,&x);
	while(!Empty_SeqStack(S)){
		Pop_SeqStack(S,&x);
		printf("%d",x);
	}
	//出栈并打印
	//Pop_SeqStack_1(S);
	

	//读栈顶元素的值 
	printf("\n取出栈顶元素:%d\n",GetTop_SeqStack_1(S));
	Destroy_SeqStack(&S);
}

/*
//链栈 
main(){
	int i,x;
	PLinkStack S;
	S = Init_LinkStack();
	for(i=0;i<5;i++){
		scanf("%d",&x);
		Push_LinkStack(S,x);
	}
	Print_LinkStack(S);
	Get_LinkStack(S);
	printf("%d",Get_LinkStack(S));
	Destory_LinkStack(&S);
}
*/