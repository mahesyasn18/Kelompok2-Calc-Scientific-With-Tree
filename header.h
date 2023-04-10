#ifndef kalku_h
#define kalku_h
#define Data(P) (P)->data
#define right(P) (P)->right
#define left(P) (P)->left
#define Nil NULL
#include <ctype.h>

typedef char infotype;
typedef struct Elemen *address;
typedef struct Elemen{
	infotype data;
	float operand;
	address right;
	address left;
	int isOperator;
}Tree;

typedef struct Node *node;
typedef struct Node{
	node next;
	infotype oprtr;
	float operand;
	int isoperator;
}ElmtList;

typedef struct{
node Head;
}Stack;

typedef struct {
node First;
node Last;
}Queue;


void InfixToPostfix(infotype* input, infotype postfix[]);
int derajatOperator(infotype oper);
int isOperator(infotype oper);
address CreateNode(infotype data);
address BuildTree(infotype postfix[]);
void PostOrder(address P);
void ViewAsc(Queue First);
void EnqueOperand(Queue *First,float item,node *P);
void convertPostfix(Queue *Z,Stack *X,char *input);
void ViewAscStack(Stack First);
void PushStack(Stack *First,char item,node *P);
char PopStack(Stack *First);
address Create_Tree(Queue Z);
address CreateNodeOperand(float input);
address CreateNodeOperator(char input);
double kalkulasi(address P);



#endif


