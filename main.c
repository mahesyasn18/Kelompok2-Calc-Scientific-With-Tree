#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double hasil;
	char input[100];
	address root;
	Queue postfix;
	
	printf("Masukkan Ekspresi:");
	scanf("%s",&input);
	
	postfix=convertPostfix(input);
	root=Create_Tree(postfix);
	hasil=kalkulasi(root);
	
	printf("PostOrder: ");
	PostOrder(root);
	
	printf("\nhasilnya adalah %g\n",hasil);
	
	return 0;
}

