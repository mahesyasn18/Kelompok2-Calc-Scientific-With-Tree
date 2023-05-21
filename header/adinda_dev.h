/*
Dibuat oleh : Adinda Raisa Az-zahra
Referensi : https://jagostat.com/kalkulus2/deret-taylor-dan-maclaurin
https://stackoverflow.com/questions/40808804/implementing-taylor-series-for-sine-and-cosine-in-c

Deskripsi : Memuat proses perhitungan:
1. operasi perkalian
2. operasi sinus
3. operasi cosinus
4. operasi tangen
5. operasi cosecan
6. operasi secan
7. operasi cotangen

*/

#include<stdio.h>

#include <math.h>

#ifndef adinda_dev_H
#define adinda_dev_H
#define PI 3.14159265358979323846
#include "AhmadFauzy_dev.h"


double operasi_perkalian(double bilangansatu, double bilangandua) {
    return bilangansatu * bilangandua;
}


/* fungsi operasi sinus */
/* menghitung nilai sinus dari suatu sudut */
double operasiSinus(double bilangan) { 
	/* inputan menggunakan satuan derajat sehigga perlu dikonversi terlebih dahulu menuju radian */
    double radian = bilangan * (PI / 180); 
    /* untuk menghitung nilai jumlah semua sukunya */
    double jumlah = 0.0; 
    /* nilaipersuku adalah nilai yang dihasilkan pengoperasian per sukunya */
    double nilaipersuku = radian; 

    int n = 1;
    while (nilaipersuku != 0.0) {
        jumlah += nilaipersuku;
        /* ditambahkan dengan 2 karena suku yg digunakan adalah suku ganjil sebab turunan ganjil merupakan sinus itu sendiri */
        n += 2; 
        /* menggunakan deret taylor */
        nilaipersuku = (-1.0) * nilaipersuku * radian * radian / ((n - 1) * n); 
    }
    /* mengambalikan jumlah sebagai hasil operasi sinus */
    return jumlah;
}

/* fungsi operasi cosinus */
/* menghitung nilai cosinus dari suatu sudut */
double operasiCosinus(double bilangan) { 
	/* inputan menggunakan satuan derajat sehigga perlu dikonversi terlebih dahulu menuju radian */
    double radian = bilangan * (PI / 180); 
    /* untuk menghitung nilai jumlah semua sukunya */
    double jumlah = 0.0; 
    /* nilaipersuku adalah nilai yang dihasilkan pengoperasian per sukunya */
    /* dimulai dari satu untuk operasi cosinus */
    double nilaipersuku = 1; 

	/* dimulai dari nol karena yang digunakan suku genap, turunan genap untuk cosinus merupakan cosinus itu sendiri */
    int n = 0; 
    while (nilaipersuku != 0.0) {
        jumlah += nilaipersuku;
        /* ditambahkan dengan 2 karena suku yg digunakan adalah suku genap sebab turunan genap merupakan cosinus itu sendiri */
        n += 2;
        /* menggunakan deret taylor */
        nilaipersuku = (-1.0) * nilaipersuku * radian * radian / ((n - 1) * n);
    }
    /* mengambalikan jumlah sebagai hasil operasi sinus */
    return jumlah;
}

/* fungsi operasi tangen */
/* menghitung nilai tangen dari suatu sudut */
double operasiTangen(double bilangan){
	double result;
	
	/* pengecualian pada beberapa case karena 1/0 hasilnya tidak terdefinisi */
	if(bilangan==90 || bilangan==270){ 
		printf("Not Defined \n");
		exit(1);
	} else{
		/* tangen merupakan hasil bagi sin dengan cos */
		result=operasi_pembagian(operasiSinus(bilangan),operasiCosinus(bilangan)); 
		/* mengembalikan hasil pembagian */
		return (result);
	}
	
}


/* fungsi operasi cosecan */
/* menghitung nilai cosecan dari suatu sudut */
double operasiCosecan(double bilangan) {
    double result;
    /* pengecualian pada beberapa case karena 1/0 hasilnya tidak terdefinisi */
    if (bilangan == 0 || bilangan == 180 || bilangan == 360) {
        printf("Not Defined \n");
    } else {
    	/* cosecan merupakan satu per dari sinus */
        result = operasi_pembagian(1, operasiSinus(bilangan)); 
        /* mengembalikan hasil pembagian */
        return (result);
    }

}

/* fungsi operasi secan */
/* menghitung nilai secan dari suatu sudut */
double operasiSecan(double bilangan) {
    double result;
    /* pengecualian pada beberapa case karena 1/0 hasilnya tidak terdefinisi */
    if (bilangan == 90 || bilangan == 270) {
        printf("Not Defined \n");
    } else {
    	/* secan merupakan satu per dari cosinus */
        result = operasi_pembagian(1, operasiCosinus(bilangan)); 
        /* mengembalikan hasil pembagian */
        return (result);
    }
}

/* fungsi operasi cotangen */
/* menghitung nilai cotangen dari suatu sudut */
double operasiCotangen(double bilangan) {
    double result;
    /* pengecualian pada beberapa case karena 1/0 hasilnya tidak terdefinisi */
    if (bilangan == 0 || bilangan == 180 || bilangan == 360) {
        printf("Not Defined \n");
    } else {
    	/* cotangen merupakan satu per dari tangen */
        result = operasi_pembagian(1, operasiTangen(bilangan)); 
        /* mengembalikan hasil pembagian */
        return (result);
    }
}


#endif
