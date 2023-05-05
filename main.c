#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "kalkulasi.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double hasil;
	char input[100];
	address root;
	Queue postfix;
	
	for(;;){
		system("cls");
		printf("Masukkan Ekspresi:");
		scanf("%s",&input);
		
		postfix=convert_postfix(input);
		root=create_tree(postfix);
		hasil=kalkulasi(root);
		
		
		printf("PostOrder: ");
		post_order(root);
		
		printf("\nhasilnya adalah %g\n",hasil);
		system("pause");
		free(postfix);
		free(root);
		
	}
	
	
	return 0;
}

