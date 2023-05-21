#include "kalkulasi.h"
#include "header/mahesya_dev.h"
#include "header/adinda_dev.h"
#include "header/AhmadFauzy_dev.h"
#include "header/syira_dev.h"
#include "header/Faisal_dev.h"

/*Proses perhitungan aritmatika dan operasi yang memerlukan dua operand terhadap satu operator*/
double kalkulasi(address root) {
    if (root -> data != '\0') {
        double left = kalkulasi(root->left);
        double right = kalkulasi(root->right);
        switch (root -> data) {
        case '+': /*operasi untuk modul penjumlahan */
            return operasi_penjumlahan(left, right);
        case '-':/*operasi untuk modul pengurangan */
            return operasi_pengurangan(left, right);
        case '/':/*operasi untuk modul pembagian */
            return operasi_pembagian(left, right);
        case '*':/*operasi untuk modul perkalian. */
            return operasi_perkalian(left, right);
        case '^':/*operasi untuk modul pangkat dinamis. (contoh 1.5^3) */
            return operasi_pangkat(left, right);
        case '&': /*operasi untuk modulus karena % sudah digunakan oleh operasi persen. (contoh 4&2) */
            return operasi_modulus(left, right);
        default:
            break;
        }
    }
    return root->operand;
}

/* Proses perhitungan trigonometri */
/* Modul untuk identifikasi proses trigonometri dan validasi*/
double proses_perhitungan_trigonometri(double angka, char operator[]) {
    if (strcmp(operator, "sin(") == 0) { /* operator == "sin(" */
        return operasiSinus(angka); 
    } else if (strcmp(operator, "cos(") == 0) {
        return operasiCosinus(angka);
    } else if (strcmp(operator, "tan(") == 0) {
        return operasiTangen(angka);
    } else if (strcmp(operator, "asin(") == 0) {
        return operasi_asin(angka);
    } else if (strcmp(operator, "acos(") == 0) {
        return operasi_acos(angka);
    } else if (strcmp(operator, "atan(") == 0) {
        return operasi_atan(angka);
    } else if (strcmp(operator, "csc(") == 0) {
        return operasiCosecan(angka);
    } else if (strcmp(operator, "sec(") == 0) {
        return operasiSecan(angka);
    } else if (strcmp(operator, "cot(") == 0) {
        return operasiCotangen(angka);
    } else {
        if (strcmp(operator, "SIN") == 0 || strcmp(operator, "SIN(") == 0 || strcmp(operator, "sin") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya sin(...), contoh sin(60)", operator);
        } else if (strcmp(operator, "COS") == 0 || strcmp(operator, "COS(") == 0 || strcmp(operator, "cos") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya cos(...), contoh cos(45)", operator);
        } else if (strcmp(operator, "TAN") == 0 || strcmp(operator, "TAN(") == 0 || strcmp(operator, "tan") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya tan(...), contoh tan(30)", operator);
        } else if (strcmp(operator, "ASIN") == 0 || strcmp(operator, "ASIN(") == 0 || strcmp(operator, "asin") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya asin(...), contoh asin(0.5)", operator);
        } else if (strcmp(operator, "ACOS") == 0 || strcmp(operator, "ACOS(") == 0 || strcmp(operator, "acos") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya acos(...), contoh acos(0.5)", operator);
        } else if (strcmp(operator, "ATAN") == 0 || strcmp(operator, "ATAN(") == 0 || strcmp(operator, "atan") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya atan(...), contoh atan(0.5)", operator);
        } else if (strcmp(operator, "CSC") == 0 || strcmp(operator, "CSC(") == 0 || strcmp(operator, "csc") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya csc(...), contoh csc(40)", operator);
        } else if (strcmp(operator, "SEC") == 0 || strcmp(operator, "SEC(") == 0 || strcmp(operator, "sec") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya sec(...), contoh sec(0.5)", operator);
        } else if (strcmp(operator, "COT") == 0 || strcmp(operator, "COT(") == 0 || strcmp(operator, "cot") == 0) {
            printf("Error, operator yang anda masukkan: %s, seharusnya COT(...), contoh cot(0.5)", operator);
        } else {
            printf("Operator Tidak Diketahui: %s", operator);
        }
        exit(1);
    }
}

/* Proses perhitungan logaritma */
/* Modul untuk validasi penulisan operasi logaritma */
double proses_perhitungan_logaritma(double angka1, double angka2, char opera[]) {
    if (strcmp(opera, "log(") == 0) {
        return operasi_logaritma(angka2, angka1); /* Jika sesuai maka akan masuk ke modul operasi_logaritma */
    } else {
        if (strcmp(opera, "LOG(") == 0 || strcmp(opera, "log") == 0 || strcmp(opera, "LOG") == 0) {
            printf("Error, Operator Tidak Diketahui: %s, seharusnya nlog(..), contoh 4log(16)", opera);
        } else {
            printf("Error, Operator Tidak Diketahui: %s", opera);
        }

        exit(1);
    }
}

/* Proses perhitungan untuk operasi logaritma basis sepuluh atau operasi yang memerlukan 1 operand dan string operator dan 
dan validasi penulisannya*/
double proses_perhitungan_single_operand_long_operator(double angka, char opera[]) {
    if (strcmp(opera, "log(") == 0) {
        return operasi_logaritma_basis_sepuluh(angka);
    } else {
        if (strcmp(opera, "LOG(") == 0 || strcmp(opera, "log") == 0 || strcmp(opera, "LOG") == 0) {
            printf("Error, Operator Tidak Diketahui: %s, seharusnya log(..), contoh log(10)", opera);
        } else {
            printf("Error, Operator Tidak Diketahui: %s", opera);
        }
        exit(1);
    }
}



/* Proses perhitungan untuk operasi yang memerlukan 1 operand dan satu char operator 
dan validasi penulisannya */
double proses_perhitungan_single_operand_single_operator(double angka, char opera) {
    if (opera == '!') {
        return operasi_faktorial(angka);
    } else if (opera == '%') {
        return operasi_persen(angka);
    } else if (opera == 'v') {
        return operasi_akar_dua(angka);
    } else {
        printf("Operator Tidak Diketahui: %c", opera);
        return -1; // return nilai error
    }
}

/* Proses perhitungan untuk operasi yang memiliki dua buah operand dan satu char operator
dan validasi penulisannya*/
double proses_perhitungan_double_operand_single_operator(double angka1, double angka2, char opera) {
    if (opera == 'v') {
        return operasi_akar_dinamis(angka2, angka1);
    } else {
        printf("Error, Operator Tidak Diketahui: %s", opera);
        exit(1);
    }
}
