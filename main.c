#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float hasil;
	char input[100],temp;
	address P;
	Stack X;
	Queue Z;
	node Q;
	Z.First=NULL;
	Z.Last=NULL;
	X.Head=NULL;
	printf("Masukkan Ekspresi:");
	scanf("%s",&input);fflush(stdin);
	convertPostfix(&Z,&X,input);
	P=Create_Tree(Z);
	hasil=kalkulasi(P);
	printf("hasilnya adalah %g\n",hasil);
	printf("PostOrder: ");
	PostOrder(P);
	return 0;
}

