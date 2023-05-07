/* File        : Faisal_dev.h */  
/* Deskripsi   : header file untuk menangani operasi pangkat dan operasi persen */ 
/* Dibuat oleh : Muhammad Faisal Adha/ 221511057 */ 
/* Tanggal     : 06-02-2023 */ 


#ifndef Faisal_dev_H
#define Faisal_dev_H
#include "adinda_dev.h"
#include "AhmadFauzy_dev.h"

//operasi pangkat
 /*Fungsi operasi pangkat untuk dua bilangan.
 Fungsi ini menerima dua bilangan bertipe double, 
 yaitu bilangan yang akan dipangkatkan (bilangansatu)
 dan pangkat yang akan digunakan (bilangandua), 
 lalu mengembalikan hasil operasi pangkat bilangansatu
 dengan pangkat bilangandua.*/

double operasi_pangkat(double bilangansatu,double bilangandua){
    double a,total=1;
    for(a=0;a<bilangandua;a++){
        total = operasi_perkalian(total, bilangansatu);// memanggil fungsi operasi_perkalian dari adinda_dev.h
    }
    return total;

}

//operasipersen
 /* Fungsi operasi persen untuk satu bilangan.
 Fungsi ini menerima satu bilangan bertipe double,
 yaitu bilangan yang akan diubah dari nilai persentase
 menjadi nilai desimal, lalu mengembalikan hasil pembagian bilangan tersebut dengan 100.*/

double operasi_persen(double bilangan){
	return operasi_pembagian(bilangan, 100.0);//memanggil fungsi operasi_pembagian dari AhmadFauzy_dev,h
}

#endif


 


