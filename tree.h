#ifndef tree_h
#define tree_h
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
void EnqueOperand(Queue *First,double item);
Queue convertPostfix(char *input);
void ViewAscStack(Stack First);
void PushStack(Stack *First,char item);
char PopStack(Stack *First);
address Create_Tree(Queue Z);
address CreateNodeOperand(double input);
address CreateNodeOperator(char input);
double kalkulasi(address P);
double prosesPerhitunganTrigonometri(double angka, char operator[]);
node CreateNodeList();


#endif



