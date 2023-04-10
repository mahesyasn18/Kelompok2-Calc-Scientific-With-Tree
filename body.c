#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "header.h"

void InfixToPostfix(infotype* input, infotype postfix[]){
	infotype stack[50], c;
	int i, length,top=-1, x=0,oper1, oper2;
	
	length=strlen(input);
	printf("length: %d \n", length);
	printf("input: %s \n", input);
	
	for(i=0;i<length;i++){
		c=input[i];
		if(isdigit(c)){
//			char num[length];
//			int j=0;
//			while(isdigit(input[i] || input[i]=='.')){
//				num[j++]=input[i];
//				i++;
//			}
//			i--;
//			postfix[x++]=num;
			postfix[x++]=c;
		} else{
			if(isOperator(c) && top!=-1 && stack[top]!='('){
//				printf("\noper: %c", c);
//				printf("\ntop: %c", stack[top]);
				oper1=derajatOperator(c);
				oper2=derajatOperator(stack[top]);
				while(oper1<=oper2 && top!=-1 ){
					postfix[x++]=stack[top--];
				}
				stack[++top]=c;
			} else if(c==')'){
//				printf("\noper: %c", c);
				postfix[x++]=stack[top--];
				top--;	
			} else{
				stack[++top]=c;
			}
		}
		
	}
	while(top!=-1){
		postfix[x++]=stack[top--];
	}
	postfix[x] = '\0';
}

int derajatOperator(infotype oper){
	if(oper=='+' || oper=='-'){
		return 1;
	} else if(oper=='*' || oper=='/'){
		return 2;
	} else if(oper=='^' || oper=='v'){
		return 3;
	} else{
		printf("Error, Operator Tidak Diketahui: %c", oper);
        exit(1);
	}
}

int isOperator(infotype oper){
	if(oper=='+' || oper=='-' || oper=='*' || oper=='/' || oper=='^' || oper=='v'){
		return 1;
	} 
	return 0;
}

address CreateNode(infotype data){
	address P;
	
	P = (address) malloc (sizeof (Tree));
	Data(P)=data;
	right(P)=Nil;
	left(P)=Nil;
	
	return P;
}

address BuildTree(infotype postfix[]){
	address P;
	address stack[50];
	int i, len, top=-1;
	infotype c;
	
	len=strlen(postfix);
	
	for(i=0;i<len;i++){
		c=postfix[i];
		if(isdigit(c)){
			P=CreateNode(c);
		} else{
			P=CreateNode(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}
		stack[++top]=P;
	}
	return(stack[0]);
}

void PostOrder(address P){
	
	if(P!=Nil){
		PostOrder(left(P));
		PostOrder(right(P));
		if(P->isOperator==1){
			printf("%c ", P->data);
		}else{
			printf("%g ",P->operand);
		}
	}
}

void PushStack(Stack *First,char item,node *P){
	*P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{

		(*P)->oprtr=item;
		(*P)->isoperator=1;
		(*P)->next=NULL;
		if(First->Head==NULL){
			(*First).Head=*P;
			(*First).Head->next=NULL;	
		}else{
			(*P)->next=First->Head;
			First->Head=*P;
		}
	
	
}
}

char PopStack(Stack *First){
	node P;
	P=First->Head;
	First->Head=P->next;
	return P->oprtr;
	free(P);
}


void ViewAsc(Queue First){
	node P;
	P=First.First;
	if(P!=NULL){
		
		while(P!=NULL){
			if(P->isoperator==1){
				printf("%c ",P->oprtr);
			}else{
				printf("%g ",P->operand);
			}
		P=P->next;
		}
	}
	else if(P==NULL){
		printf("list kosong");
	}
}

void ViewAscStack(Stack First){
	node P;
	P=First.Head;
	if(P!=NULL){
		
		while(P!=NULL){
			if(P->isoperator==1){
				printf("%c ",P->oprtr);
			}else{
				printf("%g ",P->operand);
			}
			P=P->next;
		}
	}
	else if(P==NULL){
		printf("list kosong");
	}
}

void EnqueOperator(Queue *First,char item,node *P){
	*P = (address) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->oprtr=item;
		(*P)->next=NULL;
		(*P)->isoperator=1;
		if(First->First==NULL){
			(*First).First=*P;
			(*First).Last=*P;
			(*First).Last->next=NULL;	
		}else{
			(*P)->next=NULL;
			First->Last->next=*P;
			First->Last=*P;
		}
	
}
}

void EnqueOperand(Queue *First,float item,node *P){
	*P = (address) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->operand=item;
		(*P)->next=NULL;
		(*P)->isoperator=0;
		if(First->First==NULL){
			(*First).First=*P;
			(*First).Last=*P;
			(*First).Last->next=NULL;	
		}else{
			(*P)->next=NULL;
			First->Last->next=*P;
			First->Last=*P;
		}
	
}
}
//float kalkulasi()
void convertPostfix(Queue *Z,Stack *X,char *input){
	node P;
	char token,c;
	int i,temp;
//	float num=0,num2;
	float angka;
	for(i=0;i<strlen(input);i++){
		token=input[i];
		if(isdigit(token)){
			char num[strlen(input)];
			int j=0;
			while(isdigit(input[i]) || input[i]=='.'){
				num[j++]=input[i];
				i++;
			}
			num[j]='\0';
			angka=strtof(num, NULL);
			EnqueOperand(&*Z,angka,&P);
			i--;
			
			
			
//			if(isdigit(token)){
//			num=num*10+(token-'0');
//			}else if(token=='.'){
//			num2=(input[i+1]-'0');
//			num2=num2/10;
//			num=num+num2;	
//			i++;
//			}
//			 if(isdigit(input[i+1])!=1&&input[i+1]!='.'){
//				EnqueOperand(&*Z,num,&P);
//				num=0;
//			}
		}else if(isOperator(token)&&X->Head!=NULL&&X->Head->oprtr!='('){
			c=X->Head->oprtr;
			while(derajatOperator(token)<=derajatOperator(c)&&X->Head!=NULL){
				EnqueOperator(&*Z,PopStack(&*X),&P);
			}
			PushStack(&*X,token,&P);
		}else if(token==')'){
			c=X->Head->oprtr;
			while(c!='('){
				EnqueOperator(&*Z,PopStack(&*X),&P);
				c=X->Head->oprtr;
			}
			PopStack(&*X);
		}else{
			PushStack(&*X,token,&P);
		}
	}
	while(X->Head!=NULL){
		c=PopStack(&*X);
		EnqueOperator(&*Z,c,&P);
	}
	
	
}

address Create_Tree(Queue Z){
	
	address P;
	address stack[50];
	node Q;
	int i, len, top=-1;
	infotype c;
	float d;
	
	Q=Z.First;
	
	while(Q!=NULL){
		if(Q->isoperator==1){
			c=Q->oprtr;
			P=CreateNodeOperator(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}else{
			d=Q->operand;
			P=CreateNodeOperand(d);
		}
//		if(isdigit(c)){
//			P=CreateNode(c);
//		} else{
//			P=CreateNode(c);
//			right(P)=stack[top--];
//			left(P)=stack[top--];
//		}
		stack[++top]=P;
		Q=Q->next;
	}
	return(stack[0]);
}

address CreateNodeOperand(float input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand=input;
	P->isOperator=0;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

address CreateNodeOperator(char input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->data=input;
	P->isOperator=1;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

double kalkulasi(address P){
	if(P->isOperator==1){
		if(P->data=='+'){
			return kalkulasi(P->left) + kalkulasi(P->right);
		}else if(P->data=='-'){
			return kalkulasi(P->left) - kalkulasi(P->right);
		}else if(P->data=='-'){
			return kalkulasi(P->left) - kalkulasi(P->right);
		}else if(P->data=='/'){
			return kalkulasi(P->left) / kalkulasi(P->right);
		}else if(P->data=='*'){
			return kalkulasi(P->left) * kalkulasi(P->right);
		}else if(P->data=='^'){
			return pow(kalkulasi(P->left) , kalkulasi(P->right));
		}
	}
	
	return P->operand;
}

double calculate(address root){
	// root adalah operator
    if(root->isOperator){
    	// Melakukan perhitungan
        switch(root->data){
            case '+':{
                return calculate(root->left) + calculate(root->right);
                break;
            }
            case '-':{
                return calculate(root->left) - calculate(root->right);
                break;
            }
            case '*':{
                return calculate(root->left) * calculate(root->right);
                break;
            }
            case '/':{
                if(calculate(root->right) == 0) {
				}
                else
                    return calculate(root->left) / calculate(root->right);
                break;
            }
            case '^':{
                return pow(calculate(root->left), calculate(root->right));
                break;
            }
            
        }
    }
    
    return root->operand;
}
