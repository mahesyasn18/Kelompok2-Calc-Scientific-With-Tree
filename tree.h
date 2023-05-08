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
	double operand;
	address right;
	address left;
}Tree;

typedef struct Node *node;
typedef struct Node{
	node next;
	infotype oprtr;
	double operand;
}ElmtList;

typedef struct{
node top;
}Stack;

typedef struct {
node First;
node Last;
}Queue;


Queue convert_postfix(char *input);
int is_operator(infotype oper);
void enqueue_operand(Queue *First,double item);
void enqueue_operator(Queue *Postfix, char item);
int operator_degree(infotype oper);
void push_stack(Stack *First,char item);
char pop_stack(Stack *First);
node create_node_list();
address create_tree(Queue postfix);
address create_node_operand(double input);
address create_node_operator(char input);
void post_order(address root);
double dequeue_operand(Queue *queueOperand);






#endif



