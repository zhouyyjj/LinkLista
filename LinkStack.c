#include"LinkStack.h"
#include"stdio.h"
#include"malloc.h"

//³õÊ¼»¯¿ÕÕ»
PLinkStack Init_LinkStack(){
	PLinkStack S;
	S=(PLinkStack)malloc(sizeof(LinkStack));
	if(S)
		S->top=NULL;
	return S;
}
//ÅĞÕ»¿Õ
int Empty_LinkStack(PLinkStack S){
	return(S->top==NULL);
}
//ÈëÕ»
int Push_LinkStack(PLinkStack S,DataType x){
	PStackNode p;
	p = (PStackNode)malloc(sizeof(StackNode));
	if(!p){
		printf("ÄÚ´æÒç³ö");
		return 0;
	}
	p->data=x;
	p->next=S->top;
	S->top=p;
	return 1;
}
//³öÕ»
int Pop_LinkStack(PLinkStack S,DataType *x){
	PStackNode p;
	if(Empty_LinkStack(S)){
		printf("Õ»¿Õ£¬²»ÄÜ³öÕ» ");
		return 0;
	}
	*x = S->top->data;
	p=S->top;
	S->top=S->top->next;
	free(p);
	return 1;
}
//È¡³öÕ»¶¥ÔªËØ
int Get_LinkStack(PLinkStack S){
	int	x;
	if(Empty_LinkStack(S)){
		printf("Õ»¿Õ ");
		return 0;
	}
	x = S->top->data;
	return S->top->data;
}
//Ïú»ÙÕ»
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
		printf("Õ»¿Õ ");
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