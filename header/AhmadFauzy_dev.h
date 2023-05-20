/*Nama : Ahmad Fauzy
  NIM : 221511040
  Kontrubusi : membuat modul pembagian , Logaritma biasa dan Logaritma basis 10
  referensi logika logaritma : https://www.ruangguru.com/blog/mengenal-logaritma-dan-sifat-sifatnya */
  

#ifndef AhmadFauzy_dev_h
#define AhmadFauzy_dev_h
#include "AryaKusumah_dev.h"
#include "math.h"
#include<stdio.h>
#define delta 0.000001

double operasi_pembagian(double bilangansatu, double bilangandua) {
    return (bilangansatu / bilangandua);
}

double operasi_logaritma(double bilangansatu, double bilangandua){
	/*ksmus data lokal*/
    double HasilPembagian = bilangandua;
    double sisa = 0;
    double Hasil = 0;
    double temp;
    /*algoritma*/
    if (bilangandua <= 0 || bilangansatu <= 0) { /*kondisi jika basis dan numerus lebih kecil dari 0*/
        printf("Invalid input \n");
        return 0;
    } else if (bilangansatu == bilangandua) { /*kondisi dimana basis dan numerus sama akan return 1*/
        return 1;
    } else { 
    	 while (HasilPembagian >= bilangansatu) {/*looping sampai hasil pembagian / sisa sampai hasil pembagian kurang dari basis*/
                HasilPembagian = operasi_pembagian(HasilPembagian, bilangansatu);/*membagi dan sisanya akan di simpan di hasil pembagian*/
                sisa=HasilPembagian;
                Hasil =operasi_penjumlahan(Hasil, 1);/*setiap looping hasil bertambah 1*/ 
        }
        if(HasilPembagian != 1){
        	while(pow(bilangansatu,Hasil) <= bilangandua){
        		Hasil = pow(sisa, temp);
        		temp+=0.0001;
			}
		}
    }
    return Hasil;
}

double operasi_logaritma_basis_sepuluh(double bilangansatu) {
	/*kamus data lokal*/
    double HasilPembagian = bilangansatu;
    double Hasil = 0;
    double temp;
	/*algoritma*/
    if (bilangansatu <= 0) {
        printf("Invalid input\n");
        return 0;
    } else {
        while (HasilPembagian >= 10) {
            HasilPembagian = operasi_pembagian(HasilPembagian, 10);
            Hasil =operasi_penjumlahan(Hasil, 1);
        }
        if (HasilPembagian != 1) {
        	while(pow(10,Hasil) <= bilangansatu){
        		Hasil = pow(sisa, temp);
        		temp+=0.0001;
			}
        }
    }
    return Hasil;
}

#endif
