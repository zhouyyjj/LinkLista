#include"LinkStack.h"
#include"SeqStack.h"
#include "stdio.h"
#include "malloc.h"

//˳��ջ

main(){
	int i;
	int x=0;
	PSeqStack S;
	S = Init_SeqStack();
	
	for(i=0;i<5;i++){
	//	scanf("%d",&x);
		Push_SeqStack(S,i+3);
	}
	//��ӡջ��Ԫ��
	Print_SeqStack(S);
	//��ջ		
//	Pop_SeqStack(S,&x);
	while(!Empty_SeqStack(S)){
		Pop_SeqStack(S,&x);
		printf("%d",x);
	}
	//��ջ����ӡ
	//Pop_SeqStack_1(S);
	

	//��ջ��Ԫ�ص�ֵ 
	printf("\nȡ��ջ��Ԫ��:%d\n",GetTop_SeqStack_1(S));
	Destroy_SeqStack(&S);
}

/*
//��ջ 
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