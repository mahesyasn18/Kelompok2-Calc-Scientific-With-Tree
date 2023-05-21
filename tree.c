/*
dibuat oleh : Adinda Raisa Az-zahra & Mahesya Setia Nugraha
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

/* Modul convert_postfix adalah modul yang digunakan untuk konversi infix ke postfix */
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

            //kembali ke index array input sebelumnya
            i--;
          /* proses untuk mencari derajat operator */
        } else if (is_operator(token) && operatorStackTemp.top != NULL && operatorStackTemp.top -> oprtr != '(') {
            /* tempOperator diisi dengan operator yang terdapat di operatorStackTemp */
            tempOperator = operatorStackTemp.top -> oprtr;
            /* dilakukan perulangan hingga kondisi degree token TIDAK <= tempOperator dan operatorStackTemp nya NULL */
            while (operator_degree(token) <= operator_degree(tempOperator) && operatorStackTemp.top != NULL) {
                /* operator yang memenuhi kondisi akan di keluarkan dari stack operatorStackTemp dan akan masukan pada queue postfix */
                enqueue_operator( & postfix, pop_stack( & operatorStackTemp));
            }
            /* jika terdapat kondisi dimana derajat token = tempOperator TAPI operatorStackTemp.top nya NULL maka dimasukkan ke dalam stack operatorStackTemp*/
            push_stack( & operatorStackTemp, token);
          /* proses untuk operasi dalam kurung */  
        } else if (token == ')') {
            /* operator pada operatorStackTemp ditampung oleh tempOperator */ 
            tempOperator = operatorStackTemp.top -> oprtr;
            /* dilakukan perulangan hingga tempOperator '('  */ 
            while (tempOperator != '(') {
                /* operator dimasukan ke dalam queue postfix  */ 
                enqueue_operator( & postfix, pop_stack( & operatorStackTemp));
                tempOperator = operatorStackTemp.top -> oprtr;
            }
             /* operator '(' dikeluarkan dari stack operatorStackTemp*/ 
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
            /* hasil dari perhitungan dimasukkan ke dalam queue postfix */
            enqueue_operand( & postfix, hasil);
        /* proses untuk operator log */
        } else if (token == 'l' || token == 'L') {
            char log[10];
            char Num[100];
            double angka;
            double pangkat, hasil;
            int j = 0, x = 0;
            /* menghitung sebuah operasi logaritma diluar basis 10 */
            if (isdigit(input[i - 1])) {
                pangkat = dequeue_operand( & postfix);
                while (input[i] != ')') {
                    /* jika tidak terdapat ')' maka akan muncul message error*/
                    if (input[i] == '\0') {
                        printf("Error: Tidak ditemukan karakter penutup ')'\n");
                        exit(1) ; 
                    }

                    /* jika input merupakan digit atau titik */
                    if (isdigit(input[i]) || input[i] == '.') {
                        Num[j++] = input[i]; /* maka masukan pada array of char Num */
                    } else {
                        log[x++] = input[i]; /* maka masukan pada array of char log */
                    }
                    i++;
                }
                Num[j] = '\0';
                /* konversi nilai sudut dalam bentuk char ke decimal dengan fungsi strtod */
                angka = strtof(Num, NULL);
                /* menghitung sebuah operasi logaritma */
                hasil = proses_perhitungan_logaritma(angka, pangkat, log);
                /* hasil dari perhitungan dimasukkan ke dalam queue postfix */
                enqueue_operand( & postfix, hasil);

              /* menghitung sebuah operasi logaritma basis 10 */
            } else {
                /* jika tidak terdapat ')' maka akan muncul message error */
                if (input[i] == '\0') {
                    printf("Error: Tidak ditemukan karakter penutup ')'\n");
                    exit(1) ; 
                }

                /* jika input merupakan digit atau titik */
                while (input[i] != ')') {
                    if (isdigit(input[i]) || input[i] == '.') {
                        Num[j++] = input[i]; /* maka masukan pada array of char Num */
                    } else {
                        log[x++] = input[i]; /* maka masukan pada array of char log */
                    }
                    i++;
                }
                Num[j] = '\0';
                /* konversi nilai sudut dalam bentuk char ke decimal dengan fungsi strtod */
                angka = strtod(Num, NULL);
                /* menghitung sebuah operasi logaritma basis 10*/
                hasil = proses_perhitungan_single_operand_long_operator(angka, log);
                /* hasil dari perhitungan dimasukkan ke dalam queue postfix */
                enqueue_operand( & postfix, hasil);
            }
          /* proses untuk operator faktorial dan persen */
        } else if (token == '!' || token == '%') {
            double angka, hasil;
            /* jika inputan sebelumnya berupa angka */
            if (isdigit(input[i - 1])) {
                /* keluarkan angka terakhir yang ada di queue postfix */
                angka = dequeue_operand( & postfix); 
                /* menghitung sebuah operasi faktorial atau persen */
                hasil = proses_perhitungan_single_operand_single_operator(angka, token);
                /* hasil dari perhitungan dimasukkan ke dalam queue postfix */
                enqueue_operand( & postfix, hasil);
            }
          /* proses untuk operator akar pangkat dinamis dan akar pangkat 2 */
        } else if (token == 'v') {
            char nomor[100];
            double bilangan, bilangan2, hasil;
            int top_no = 0;

            /* proses untuk menentukan operasi akar pangkat dua */
            if (!isdigit(input[--i])) {
                /* mengembalikan index array input agar ke index semula */
                i = i + 2;

                /* dilakukan perulangan hingga kondisi input bukanlah sebuah digit */
                while (isdigit(input[i])) {
                    if (isdigit(input[i]) || input[i] == '.') {
                        nomor[top_no++] = input[i++];
                    }
                }
                nomor[top_no] = '\0';

                /* konversi nilai sudut dalam bentuk char ke decimal dengan fungsi strtod */
                bilangan = strtod(nomor, NULL);
                /* menghitung operasi akar pangkat dua */
                hasil = proses_perhitungan_single_operand_single_operator(bilangan, token);
                /* hasil dari perhitungan dimasukkan ke dalam queue postfix */
                enqueue_operand( & postfix, hasil);
            } else {
                i = i + 2;
                while (isdigit(input[i])) {
                    if (isdigit(input[i]) || input[i] == '.') {
                        nomor[top_no++] = input[i++];
                    }
                }
                nomor[top_no] = '\0';

                /* nilai akar */
                bilangan2 = strtod(nomor, NULL);
                /* nilai pangkat */
                bilangan = dequeue_operand( & postfix);

                /* menghitung operasi akar pangkat dinamis */
                hasil = proses_perhitungan_double_operand_single_operator(bilangan, bilangan2, token);
                /* hasil dari perhitungan dimasukkan ke dalam queue postfix */
                enqueue_operand( & postfix, hasil);
            }

        } else {
            /* jika operator + - / * ^ &  yang tidak memenuhi kondisi di atas maka akan dimasukkan ke dalam stack operatorStackTemp*/
            push_stack( & operatorStackTemp, token);
        }
    }

    /* melakukan perulangan pada stack operatorStackTemp hingga kondisi topnya NULL*/
    while (operatorStackTemp.top != NULL) {
        /*sebuah operator dari stack operatorStackTemp dikeluarkan dan di tampung di operator*/
        tempOperator = pop_stack( & operatorStackTemp);
        /* hasil dari perhitungan dimasukkan ke dalam queue postfix */
        enqueue_operator( & postfix, tempOperator);
    }
    
    /* mengembalikan queue postfix*/
    return postfix;
}

/* modul is_operator adalah modul untuk mengecek apakah inputan berupa operator atau bukan  */
int is_operator(infotype oper) {
    /* jika operator + - * / ^ &*/
    if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == '&') {
        return 1; /* kembalikan nilai 1*/
    }
    return 0; /*jika tidak kembalikan nilai 0 */
}

/* modul enqueue_operand digunakan untuk membuat node baru yang berisi bilangan */
void enqueue_operand(Queue * Postfix, double item) {
    node new_node_operand;
    /*membuat node baru*/
    new_node_operand = create_node_list();
    new_node_operand -> oprtr = '\0'; /*subvar oprtr di set nilai kosong */
    new_node_operand -> operand = item; /*subvar operand diisi nilai dari parameter item */

    /* jika queue kosong */
    if (Postfix -> First == NULL) {
        /*maka Pointer First dan Last diisi dengan node baru*/
        Postfix -> First = new_node_operand;
        Postfix -> Last = new_node_operand;
        Postfix -> Last -> next = NULL;
    } else {
        /*maka Pointer Last dengan subvar next diisi dengan node baru*/
        Postfix -> Last -> next = new_node_operand;
        Postfix -> Last = new_node_operand;
    }
}

/* modul enqueue_operator digunakan untuk membuat node baru yang berisi operator */
void enqueue_operator(Queue * Postfix, char item) {
    node new_node_operator;
    /*membuat node baru*/
    new_node_operator = create_node_list(); 
    new_node_operator -> oprtr = item; /*subvar oprtr diisi nilai dari parameter item */

    /* jika queue kosong */
    if (Postfix -> First == NULL) {
        /*maka Pointer First dan Last diisi dengan node baru*/
        Postfix -> First = new_node_operator;
        Postfix -> Last = new_node_operator;
        Postfix -> Last -> next = NULL;
    } else {
        /*maka Pointer Last dengan subvar next diisi dengan node baru*/
        Postfix -> Last -> next = new_node_operator;
        Postfix -> Last = new_node_operator;
    }
}

/* modul dequeue_operand digunakan untuk membuat menghapus atau kembali ke node operand terakhir */
double dequeue_operand(Queue * postfix) {
    double found;
    node First, Last, Throw;
    First = postfix -> First; /*pointer First diisi dengan node yang ditunjuk oleh First*/
    Last = postfix -> Last; /*pointer Last diisi dengan node yang ditunjuk oleh Last*/
    /* Jika First Null */
    if (First == NULL) {
        printf("Queue Empty"); /*Maka queue postfix kosong*/

    } else {
        if (First != Last) {
            /* Lakukan Perulangan hingga First = Last */
            while (First -> next != Last) {
                First = First -> next;
            }
            /* Throw diisi Last */
            Throw = Last;
            /* found diisi oleh nilai dari subvar operand */
            found = Last -> operand;
            /* Last diisi oleh  First dari posisi terkini */
            postfix -> Last = First;
            /* suvbar next Last di kosongkan */
            postfix -> Last -> next = NULL;
            /* node pada throw di hapus dari memory */
            free(Throw); 
            return found;
        } else {
            /* Throw diisi Last */
            Throw = Last;
            /* found diisi oleh nilai dari subvar operand */
            found = Last -> operand;
            /* Last dan First di kosongkan */
            postfix -> Last = NULL;
            postfix -> First = NULL;
            /* node pada throw di hapus dari memory */
            free(Throw);
            return found;
        }

    }
}

/*Modul operator_degree digunakan untuk mencari derajat prioritas dari sebuah operator*/
int operator_degree(infotype oper) {
    /*3 menunujukan derajat prioritas tertinggi dan 1 terendah*/
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

/* modul push_stack adalah modul yang digunakan untuk membuat node baru pada sebuah stack */
void push_stack(Stack * First, char item) {
    node new_node;
    /*membuat node baru*/
    new_node = create_node_list();
    if (new_node == NULL) { /* jika new_node kosong maka alokasi gagal*/
        printf("Gagal Alokasi");
    } else {
        new_node -> oprtr = item; /* subvar oprtr (operator) diisi oleh nilai dari parameter item */
        new_node -> next = NULL; /* subvar next diisi NULL */
        if (First -> top == NULL) { /* jika top nya NULL */
            First -> top = new_node; /* maka node baru akan menjadi top nya*/
            First -> top -> next = NULL;
        } else {
            /* maka node baru akan menjadi top nya dan node lama bukan lagi top*/
            new_node -> next = First -> top;
            First -> top = new_node;
        }
    }
}

/*modul pop_stack untuk menghapus top pada stack (pop stack)*/ 
char pop_stack(Stack * First) {
    node node_temp;
    node_temp = First -> top;
    /*subvar top diisi dengan node yang ditunjuk oleh subvar next*/
    First -> top = node_temp -> next;
    return node_temp -> oprtr;
    free(node_temp); /*node_temp di dealokasi*/ 
}

/* modul untuk membuat node baru pada setiap list yang dibentuk */
node create_node_list() {
    node new_node;
    /*melakukan alokasi sebuah node*/
    new_node = (node) malloc(sizeof(ElmtList));
    if (new_node == NULL) { /*jika hasilnya NULL maka alokasi gagal*/
        printf("Gagal Alokasi");
    } else {
        (new_node) -> next = NULL;  /*jika node berhasil dibuat*/
    }

    return new_node; /*node kosong dikembalikan*/
}

/*modul create_tree adalah modul yang digunakan untuk membuat tree yang berisi ekspresi matematika yang diinputkan*/ 
address create_tree(Queue postfix) {
	address new_node_tree;
    address stack[50]; /*digunakan untuk bantuan pembuatan tree*/ 
    node temp_postfix;
    int i, len, top = -1;
    infotype opera;
    double operand;
    
    temp_postfix = postfix.First; /*temp_postfix diisi dengan node First queue postfix*/ 

    /* lakukan perulangan pada temp_postfix hingga NULL */ 
    while (temp_postfix != NULL) {
        /*jika subvar oprtr (operator) tidak NULL */
        if (temp_postfix -> oprtr != '\0') {
            opera = temp_postfix -> oprtr; /*maka isi variable opera dengan operator yang ada di subvar oprtr*/
            new_node_tree = create_node_operator(opera); /*membuat node baru untuk operator*/
            /*subvar pointer left dan right diisi dengan node yang ditunjuk oleh top sebelumnya*/
            right(new_node_tree) = stack[top--]; 
            left(new_node_tree) = stack[top--];
        } else {
            operand = temp_postfix -> operand; /*maka isi variable operand dengan bilangan yang ada di subvar operand*/
            new_node_tree = create_node_operand(operand); /*membuat node baru untuk operand*/
        }
        /*subvar top ditambah 1 lalu diisi dengan node yang baru*/
        stack[++top] = new_node_tree;
        temp_postfix = temp_postfix -> next;
    }
    /*kembalikan stack index yang pertama (yang menunjuk root dari pohon)*/
    return (stack[0]);
}

address create_node_operator(char input) {
    address new_node_operator;
    /* alokasi untuk membuat node baru untuk operator */
    new_node_operator = (address) malloc(sizeof(Tree));
    new_node_operator -> data = input; /*subvar data diisi input*/
    /*subvar left, right di NULL kan*/
    new_node_operator -> left = NULL; 
    new_node_operator -> right = NULL; 
    /*kembalikan stack index yang pertama (yang menunjuk root dari pohon)*/
    return new_node_operator;
}

address create_node_operand(double input) {
    address new_node_operand;
    /* alokasi untuk membuat node baru untuk operand */
    new_node_operand = (address) malloc(sizeof(Tree));
    new_node_operand -> operand = input; /*subvar data diisi input*/
    /*subvar left, right di NULL kan*/
    new_node_operand -> left = NULL;
    new_node_operand -> right = NULL;
    /*subvar data (operator di NULL kan)*/
    new_node_operand -> data = '\0';
    return new_node_operand;
}

void post_order(address root) {
    if (root != Nil) {
        post_order(left(root)); /*visit anak kiri*/
        post_order(right(root)); /*visit anak kanan*/
        if (root -> data != '\0') {
            printf("%c ", root -> data);
        } else {
            printf("%g ", root -> operand);
        }
    }
}
