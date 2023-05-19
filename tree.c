/*
dibuat oleh : Adinda Raisa Azzahra & Mahesya Setia Nugraha
referensi logika: http://bwahyudi.staff.gunadarma.ac.id/Downloads/files/22353/INFIX1.pdf
file : tree.c
Deskripsi : Memuat proses konversi infix ke postfix hingga pembuatan binary tree dari hasil postfix

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "tree.h"
#include "kalkulasi.h"

Queue convert_postfix(char * input) {
    Queue postfix;
    Stack operatorStackTemp;
    postfix.First = NULL;
    postfix.Last = NULL;
    operatorStackTemp.top = NULL;

    char token, tempOperator;
    int i, temp, j;

    double angka;
    /* melakukan perulangan sepanjang input */
    for (i = 0; i < strlen(input); i++) {
        /* sebuah operand atau operator disimpan dalam variable token */
        token = input[i];

        /* pengecekan token apakah digit atau bukan dan juga pengecekan untuk nilai token negatif */
        if (isdigit(token) || (token == '-' && is_operator(input[i - 1])) || (token == '-' && i == 0) || (token == '-' && input[i - 1] == '(')) {
            char num[strlen(input)];
            j = 0;
            
            /* jika token merupakan - (lambang negatif) maka masukan pada array num */
            if (token == '-') {
                num[j++] = token; 
                i++;
            }

            //melakukan perulangan inputan berikutnya hingga inputan bukan sebuah digit
            while (isdigit(input[i]) || input[i] == '.') {
                num[j++] = input[i];
                i++;
            }


            num[j] = '\0';
            //mengubah char num menjadi angka menggunakan strtod (string to double)
            angka = strtod(num, NULL);

            //memasukan angka ke queue postfix
            enqueue_operand( & postfix, angka);
            i--;
          /* proses untuk menentukan apakah token sebuah character dan subvar topnya tidak kosong dan operatornya bukan '(' */
        } else if (is_operator(token) && operatorStackTemp.top != NULL && operatorStackTemp.top -> oprtr != '(') {
            /* tempOperator diisi dengan nilai dari subvar oprtr yang ditunjuk oleh top dari stack */
            tempOperator = operatorStackTemp.top -> oprtr;
            while (operator_degree(token) <= operator_degree(tempOperator) && operatorStackTemp.top != NULL) {
                enqueue_operator( & postfix, pop_stack( & operatorStackTemp));
            }
            push_stack( & operatorStackTemp, token);
        } else if (token == ')') {
            tempOperator = operatorStackTemp.top -> oprtr;
            while (tempOperator != '(') {
                enqueue_operator( & postfix, pop_stack( & operatorStackTemp));
                tempOperator = operatorStackTemp.top -> oprtr;
            }
            pop_stack( & operatorStackTemp);

          /* proses untuk menetukan operator trigonometri */
          /* operasi yang tersedia (sin, cos, tan, asin, acos, atan, cosecan, secan, cotangen) */
             
        } else if (token == 's' || token == 'c' || token == 't' || token == 'a' || token == 'S' || token == 'C' || token == 'T' || token == 'A') {
            char trigono[7];
            char sudut[20];
            j = 0;
            int x = 0;
            double hasil;
            /* melakukan perulangan pake input hingga menemukan ')' */
            while (input[i] != ')') {
                /* jika tidak terdapat ')' maka akan muncul message error*/
                if (input[i] == '\0') {
                    printf("Error: Tidak ditemukan karakter penutup ')'\n");
                    exit(1) ; 
                }

                /* jika input merupakan digit atau titik */
                if (isdigit(input[i]) || input[i] == '.') {
                    sudut[x++] = input[i]; /* maka masukan pada array of char sudut */
                } else {
                    trigono[j++] = input[i]; /* maka masukan pada array of char trigono */
                }
                i++;
            }
            sudut[x] = '\0';
            /* konversi nilai sudut dalam bentuk char ke decimal dengan fungsi strtod */
            angka = strtod(sudut, NULL);
            /* menghitung sebuah operasi trigonomeri */
            hasil = proses_perhitungan_trigonometri(angka, trigono);
            enqueue_operand( & postfix, hasil);
        } else if (token == 'l' || token == 'L') {
            char log[10];
            char Num[100];
            float angka;
            float a, hasil;
            int j = 0, x = 0;
            if (isdigit(input[i - 1])) {
                a = dequeue_operand( & postfix);
                while (input[i] != ')') {
                    if (isdigit(input[i]) || input[i] == '.') {
                        Num[j++] = input[i];
                    } else {
                        log[x++] = input[i];
                    }
                    i++;
                }
                Num[j] = '\0';
                angka = strtof(Num, NULL);
                hasil = proses_perhitungan_logaritma(angka, a, log);
                enqueue_operand( & postfix, hasil);
            } else {
                while (input[i] != ')') {
                    if (isdigit(input[i]) || input[i] == '.') {
                        Num[j++] = input[i];
                    } else {
                        log[x++] = input[i];
                    }
                    i++;
                }
                Num[j] = '\0';
                angka = strtof(Num, NULL);
                hasil = proses_perhitungan_single_operand_long_operator(angka, log);
                enqueue_operand( & postfix, hasil);
            }

        } else if (token == '!' || token == '%') {
            double angka, hasil;
            if (isdigit(input[i - 1])) {
                angka = dequeue_operand( & postfix);
                hasil = proses_perhitungan_single_operand_single_operator(angka, token);
                enqueue_operand( & postfix, hasil);
            }
        } else if (token == 'v') {
            char nomor[100];
            double bilangan, bilangan2, hasil;
            int top_no = 0;

            if (!isdigit(input[--i])) {
                i = i + 2;
                while (isdigit(input[i])) {
                    if (isdigit(input[i]) || input[i] == '.') {
                        nomor[top_no++] = input[i++];
                    }
                }
                nomor[top_no] = '\0';

                bilangan = strtod(nomor, NULL);
                hasil = proses_perhitungan_single_operand_single_operator(bilangan, token);
                enqueue_operand( & postfix, hasil);

            } else {
                i = i + 2;
                while (isdigit(input[i])) {
                    if (isdigit(input[i]) || input[i] == '.') {
                        nomor[top_no++] = input[i++];
                    }
                }
                nomor[top_no] = '\0';
                bilangan2 = strtod(nomor, NULL);
                bilangan = dequeue_operand( & postfix);
                enqueue_operand( & postfix, bilangan);
                enqueue_operand( & postfix, bilangan2);
                push_stack( & operatorStackTemp, token);
            }

        } else {
            push_stack( & operatorStackTemp, token);
        }
    }

    while (operatorStackTemp.top != NULL) {
        tempOperator = pop_stack( & operatorStackTemp);
        enqueue_operator( & postfix, tempOperator);
    }

    return postfix;
}

int is_operator(infotype oper) {
    if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == 'v' || oper == '&') {
        return 1;
    }
    return 0;
}

void enqueue_operand(Queue * Postfix, double item) {
    node new_node_operand;
    new_node_operand = create_node_list();
    new_node_operand -> oprtr = '\0';
    new_node_operand -> operand = item;

    if (Postfix -> First == NULL) {
        Postfix -> First = new_node_operand;
        Postfix -> Last = new_node_operand;
        Postfix -> Last -> next = NULL;
    } else {
        Postfix -> Last -> next = new_node_operand;
        Postfix -> Last = new_node_operand;
    }
}

void enqueue_operator(Queue * Postfix, char item) {
    node new_node_operator;
    new_node_operator = create_node_list();
    new_node_operator -> oprtr = item;
    if (Postfix -> First == NULL) {
        Postfix -> First = new_node_operator;
        Postfix -> Last = new_node_operator;
        Postfix -> Last -> next = NULL;
    } else {
        Postfix -> Last -> next = new_node_operator;
        Postfix -> Last = new_node_operator;
    }
}

double dequeue_operand(Queue * postfix) {
    double found;
    node First, Last, Throw;
    First = postfix -> First;
    Last = postfix -> Last;
    if (First == NULL) {
        printf("Queue Empty");

    } else {
        if (First != Last) {
            while (First -> next != Last) {
                First = First -> next;
            }
            Throw = Last;
            found = Last -> operand;
            postfix -> Last = First;
            postfix -> Last -> next = NULL;
            free(Throw);
            return found;
        } else {
            Throw = Last;
            found = Last -> operand;
            postfix -> Last = NULL;
            postfix -> First = NULL;
            free(Throw);
            return found;
        }

    }
}

int operator_degree(infotype oper) {
    if (oper == '+' || oper == '-') {
        return 1;
    } else if (oper == '*' || oper == '/') {
        return 2;
    } else if (oper == '^' || oper == 'v' || oper == '&') {
        return 3;
    } else if (oper == '(' || oper == ')') {
        return 0;
    } else {
        printf("Error, Operator Tidak Diketahui: %c", oper);
        exit(1);
    }
}

void push_stack(Stack * First, char item) {
    node new_node;
    new_node = create_node_list();
    if (new_node == NULL) {
        printf("Gagal Alokasi");
    } else {
        new_node -> oprtr = item;
        new_node -> next = NULL;
        if (First -> top == NULL) {
            First -> top = new_node;
            First -> top -> next = NULL;
        } else {
            new_node -> next = First -> top;
            First -> top = new_node;
        }
    }
}

char pop_stack(Stack * First) {
// modul untuk menghapus top pada stack (pop stack)
    node node_temp;
    node_temp = First -> top;
    First -> top = node_temp -> next;
    return node_temp -> oprtr;
    free(node_temp); // didealokasi
}

node create_node_list() {
// modul untuk membuat node baru pada setiap list yang dibentuk
    node new_node;

    new_node = (node) malloc(sizeof(ElmtList));
    if (new_node == NULL) {
        printf("Gagal Alokasi");
    } else {
        (new_node) -> next = NULL; // jika node berhasil dibuat
    }

    return new_node; // node yang berhasil dibentuk dikembalikan
}

address create_tree(Queue postfix) {
// modul untuk membuat tree yang berisi ekspresi matematika yang diinputkan
	address new_node_tree;
    address stack[50];
    node temp_postfix;
    int i, len, top = -1;
    infotype opera;
    double operand;

    temp_postfix = postfix.First;

    while (temp_postfix != NULL) {
        if (temp_postfix -> oprtr != '\0') {
            opera = temp_postfix -> oprtr;
            new_node_tree = create_node_operator(opera);
            right(new_node_tree) = stack[top--];
            left(new_node_tree) = stack[top--];
        } else {
            operand = temp_postfix -> operand;
            new_node_tree = create_node_operand(operand);
        }
        stack[++top] = new_node_tree;
        temp_postfix = temp_postfix -> next;
    }
    return (stack[0]);
}

address create_node_operator(char input) {
    address new_node_operator;
    new_node_operator = (address) malloc(sizeof(Tree));
    new_node_operator -> data = input;
    new_node_operator -> left = NULL;
    new_node_operator -> right = NULL;
    return new_node_operator;
}

address create_node_operand(double input) {
    address new_node_operand;
    new_node_operand = (address) malloc(sizeof(Tree));
    new_node_operand -> operand = input;
    new_node_operand -> left = NULL;
    new_node_operand -> right = NULL;
    new_node_operand -> data = '\0';
    return new_node_operand;
}

void post_order(address root) {
    if (root != Nil) {
        post_order(left(root));
        post_order(right(root));
        if (root -> data != '\0') {
            printf("%c ", root -> data);
        } else {
            printf("%g ", root -> operand);
        }
    }
}
