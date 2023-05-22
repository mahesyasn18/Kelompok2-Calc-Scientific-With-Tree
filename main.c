#include <stdio.h>

#include <stdlib.h>

#include "tree.h"

#include "kalkulasi.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char * argv[]) {
    double hasil;  
    char input[100];  
    address root;  
    Queue postfix;  
	/* Looping tak terbatas */
    for (;;) {
        system("cls");
		
		/* Input ekspresi matematika dalam bentuk infix */  
        printf("Masukkan Ekspresi:");  
        scanf("%s", &input);  

		/* konversi dari infix ke postfix */
        postfix = convert_postfix(input);  
        
        /* Membuat tree dari ekspresi postfix */
        root = create_tree(postfix);
		
		/* Menghitung hasil */  
        hasil = kalkulasi(root); 

		/* Menampilkan hasil post order dari tree */
        printf("PostOrder: ");  
        post_order(root);

		/* Menampilkan hasil kalkulasi */
        printf("\nhasilnya adalah %g\n", hasil);
        system("pause"); 
        
        /* Membebaskan memori yang dialokasikan untuk tree*/
        free(root); 
    }

    return 0;
}
