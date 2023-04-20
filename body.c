#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "tree.h"
#include "header/mahesya_dev.h"
#include "header/adinda_dev.h"

#include "header/AhmadFauzy_dev.h"
#include "header/syira_dev.h"
#include "header/adinda_dev.h"
#include "header/AhmadFauzy_dev.h"
#include "header/Faisal_dev.h"


void InfixToPostfix(infotype* input, infotype postfix[]){
	infotype stack[50], c;
	int i, length,top=-1, x=0,oper1, oper2;
	
	length=strlen(input);
	printf("length: %d \n", length);
	printf("input: %s \n", input);
	
	for(i=0;i<length;i++){
		c=input[i];
		if(isdigit(c)){
			postfix[x++]=c;
		} else{
			if(isOperator(c) && top!=-1 && stack[top]!='('){
				oper1=derajatOperator(c);
				oper2=derajatOperator(stack[top]);
				while(oper1<=oper2 && top!=-1 ){
					postfix[x++]=stack[top--];
				}
				stack[++top]=c;
			} else if(c==')'){
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
	}  else if(oper=='(' || oper==')'){
		return 0;
	}else{
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

void PostOrder(address P){
	
	if(P!=Nil){
		PostOrder(left(P));
		PostOrder(right(P));
		if(P->data!='\0'){
			printf("%c ", P->data);
		}else{
			printf("%g ",P->operand);
		}
	}
}

void PushStack(Stack *First,char item){
	node P;
	P = CreateNodeList();
	if(P==NULL){
		printf("Gagal Alokasi");
	}
	else{
		P->oprtr=item;
		P->next=NULL;
		if(First->Head==NULL){
			First->Head=P;
			First->Head->next=NULL;	
		}else{
			P->next=First->Head;
			First->Head=P;
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

node CreateNodeList(){
	node P;
	
	P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	} else{
		(P)->next=NULL;
	}
	
	return P;
}

void EnqueOperator(Queue *Postfix, char item){
	node P;
	
	P=CreateNodeList();
	P->oprtr=item;
	if(Postfix->First==NULL){
		Postfix->First=P;
		Postfix->Last=P;
		Postfix->Last->next=NULL;
	} else{
		Postfix->Last->next=P;
		Postfix->Last=P;
	}
}

void EnqueOperand(Queue *Postfix,double item){
	node P;

	P=CreateNodeList();
	P->oprtr = '\0';
	P->operand=item;
	
	if(Postfix->First==NULL){
		Postfix->First=P;
		Postfix->Last=P;
		Postfix->Last->next=NULL;
	} else{
		Postfix->Last->next=P;
		Postfix->Last=P;
	}
}
	
//float kalkulasi()
Queue convertPostfix(char *input){
	Queue queueOperand;
	Stack operatorStackTemp;
	
	queueOperand.First=NULL;
	queueOperand.Last=NULL;
	operatorStackTemp.Head=NULL;
	
	char token,tempOperator;
	int i,temp,j;
	
	double angka;
	for(i=0;i<strlen(input);i++){
		token=input[i];
		if(isdigit(token)){
			char num[strlen(input)];
			j=0;
			while(isdigit(input[i]) || input[i]=='.'){
				num[j++]=input[i];
				i++;
			}
			num[j]='\0';
			angka=strtod(num, NULL);
			EnqueOperand(&queueOperand,angka);
			i--;
			
			
		}
		else if (token=='s' ||token=='c' ||token=='t' ||token=='a' ){
			char trigono[7];
			char sudut[20];
			j=0;
			int x=0;
			double hasil;
			while(input[i]!=')'){
				if(isdigit(input[i]) || input[i]=='.'){
					sudut[x++]=input[i];
				}else{
					trigono[j++]=input[i];
				} 
				i++;
			}
			sudut[x]='\0';
			angka=strtod(sudut, NULL);
			hasil=prosesPerhitunganTrigonometri(angka, trigono);
			EnqueOperand(&queueOperand, hasil);
			
		}else if(isOperator(token)&& operatorStackTemp.Head!=NULL && operatorStackTemp.Head->oprtr!='('){
			tempOperator=operatorStackTemp.Head->oprtr;
			while(derajatOperator(token)<=derajatOperator(tempOperator) && operatorStackTemp.Head!=NULL){
				EnqueOperator(&queueOperand,PopStack(&operatorStackTemp));
			}
			PushStack(&operatorStackTemp,token);
		}else if(token==')'){
			tempOperator=operatorStackTemp.Head->oprtr;
			while(tempOperator!='('){
				EnqueOperator(&queueOperand,PopStack(&operatorStackTemp));
				tempOperator=operatorStackTemp.Head->oprtr;
			}
			PopStack(&operatorStackTemp);
		}else{
			PushStack(&operatorStackTemp,token);
		}
	}
	while(operatorStackTemp.Head!=NULL){
		tempOperator=PopStack(&operatorStackTemp);
		EnqueOperator(&queueOperand,tempOperator);
	}
	
	return queueOperand;
}

address Create_Tree(Queue Z){
	address P;
	address stack[50];
	node Q;
	int i, len, top=-1;
	infotype c;
	double d;
	
	Q=Z.First;
	
	while(Q!=NULL){
		if(Q->oprtr!='\0'){
			c=Q->oprtr;
			P=CreateNodeOperator(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}else{
			d=Q->operand;
			P=CreateNodeOperand(d);
		}
		stack[++top]=P;
		Q=Q->next;
	}
	return(stack[0]);
}

address CreateNodeOperand(double input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand=input;
	P->left=NULL;
	P->right=NULL;
	P->data = '\0';
	return P;
	
}

address CreateNodeOperator(char input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->data=input;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

double kalkulasi(address P){
	if(P->data!='\0'){
		double left= kalkulasi(P->left),right= kalkulasi(P->right);
		if(P->data=='+'){
			return operasiPenjumlahan(left, right);
		}else if(P->data=='-'){
			return operasiPengurangan(left,right);
		}else if(P->data=='/'){
			return operasiPembagian(left,right);
		}else if(P->data=='*'){
			return operasiPerkalian(left,right);
		}else if(P->data=='^'){
			return pow(kalkulasi(P->left) , kalkulasi(P->right));
		}
		else if(P->data=='v'){
			return operasiAkar(right,left);
		}
	}
	
	return P->operand;
}

double prosesPerhitunganTrigonometri(double angka, char operator[]){
	if(strcmp(operator,"sin(")==0){
		return operasiSinus(angka);
	}
	else if(strcmp(operator,"cos(")==0){
		return operasiCosinus(angka);
	}else if(strcmp(operator,"tan(")==0){
		return operasiTangen(angka);
	}else if(strcmp(operator,"asin(")==0){
		return operasiAsin(angka);
	}else if(strcmp(operator,"acos(")==0){
		return operasiAcos(angka);
	}else if(strcmp(operator,"atan(")==0){
		return operasiAtan(angka);
	}else if(strcmp(operator,"csc(")==0){
		return operasiCosecan(angka);
	}else if(strcmp(operator,"sec(")==0){
		return operasiSecan(angka);
	}else if(strcmp(operator,"cot(")==0){
		return operasiCotangen(angka);
	}
	else{
		if(strcmp(operator,"SIN")==0||strcmp(operator,"SIN(")==0||strcmp(operator,"sin")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya sin(...), contoh sin(60)", operator);
		}else if(strcmp(operator,"COS")==0||strcmp(operator,"COS(")==0||strcmp(operator,"cos")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya cos(...), contoh cos(45)", operator);
		}else if(strcmp(operator,"TAN")==0||strcmp(operator,"TAN(")==0||strcmp(operator,"tan")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya tan(...), contoh tan(30)", operator);
		}else if(strcmp(operator,"ASIN")==0||strcmp(operator,"ASIN(")==0||strcmp(operator,"asin")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya asin(...), contoh asin(0.5)", operator);
		}else if(strcmp(operator,"ACOS")==0||strcmp(operator,"ACOS(")==0||strcmp(operator,"acos")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya acos(...), contoh acos(0.5)", operator);
		}else if(strcmp(operator,"ATAN")==0||strcmp(operator,"ATAN(")==0||strcmp(operator,"atan")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya atan(...), contoh atan(0.5)", operator);
		}else if(strcmp(operator,"CSC")==0||strcmp(operator,"CSC(")==0||strcmp(operator,"csc")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya csc(...), contoh csc(40)", operator);
		}else if(strcmp(operator,"SEC")==0||strcmp(operator,"SEC(")==0||strcmp(operator,"sec")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya sec(...), contoh sec(0.5)", operator);
		}else if(strcmp(operator,"COT")==0||strcmp(operator,"COT(")==0||strcmp(operator,"cot")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya COT(...), contoh cot(0.5)", operator);
		}else{
			printf("Operator Tidak Diketahui sin: %s", operator);
		}
        exit(1);
	}
}

