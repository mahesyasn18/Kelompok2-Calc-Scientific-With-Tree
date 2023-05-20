/* 
Dibuat oleh : Muhammad Faisal Adha 
Deskripsi : Memuat proses perhitungan:
1.operasi pangkat 
2.operasi persen
 
*/


#ifndef Faisal_dev_H
#define Faisal_dev_H

#include "adinda_dev.h"
#include "AhmadFauzy_dev.h"


/*Fungi operasi pangkat dinamis*/
double operasi_pangkat(double bilangansatu, double bilangandua) {
    /* referensi: https://tofariyadi.blogspot.com/2014/04/contoh-program-pemangkatan-menggunakan-c.html */
    double a, total = 1;
     /*Melakukan perulangan sebanyak 'bilangandua' kali.*/
     for (a = 0; a < bilangandua; a++) {  
        /*Memanggil fungsi 'operasi_perkalian' dari 'adinda_dev.h' */
        total = operasi_perkalian(total, bilangansatu); 
     }
     /*Mengembalikan nilai akhir 'total' setelah perulangan selesai.*/ 
    return total;
}


/*Fungsi Opeasi Persen*/
double operasi_persen(double bilangan) {
    return operasi_pembagian(bilangan, 100.0); //memanggil fungsi operasi_pembagian dari AhmadFauzy_dev,h
}

#endif