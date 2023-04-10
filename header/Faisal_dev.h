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

double operasiPangkat(double bilangansatu,double bilangandua){
//    double a,total=1;
//    for(a=0;a<bilangandua;a++){
//        total = operasiPerkalian(total, bilangansatu);// menggunakan fungsi operasiPerkalian dari adinda_dev.h
//    }
    return pow(bilangansatu, bilangandua);

}

//operasipersen
 /* Fungsi operasi persen untuk satu bilangan.
 Fungsi ini menerima satu bilangan bertipe double,
 yaitu bilangan yang akan diubah dari nilai persentase
 menjadi nilai desimal, lalu mengembalikan hasil pembagian bilangan tersebut dengan 100.*/

double operasipersen(double bilangan){
	return operasiPembagian(bilangan, 100.0);//menggunakan fungsi operasiPembagian dari AhmadFauzy_dev,h
}

#endif


 


