/*Nama : Ahmad Fauzy
  NIM : 221511040
  Kontrubusi : membuat modul pembagian , Logaritma biasa dan Logaritma basis 10
  referensi logika logaritma : https://www.ruangguru.com/blog/mengenal-logaritma-dan-sifat-sifatnya */
  

#ifndef AhmadFauzy_dev_h
#define AhmadFauzy_dev_h
#include "AryaKusumah_dev.h"
#include "math.h"
#include<stdio.h>
#define delta 0.00001

double operasi_pembagian(double bilangansatu, double bilangandua) {
    return (bilangansatu / bilangandua);
}

double operasi_logaritma(double bilangansatu, double bilangandua){
	/*ksmus data lokal*/
    double HasilPembagian = bilangandua; /*Hasil pembagian : sebagai penampung dari Numerus */
    double Hasil = 0; /*Hasil : sebagai penampung dari hasil akhir*/
    double temp = delta; /*temp : sebagai penampung sementara untuk nilai delta yang terus bertambah sampai nilai dari hasil akhir mencapai paling mendekati numerus */
    /*algoritma*/
    if (bilangandua <= 0 || bilangansatu <= 0) { /*kondisi jika basis dan numerus lebih kecil dari 0  dan akan menampikan invalid input*/
        printf("Invalid input \n"); 
        return 0; /*jika invalid input akan mengembalikan nilai 0*/
    } else if (bilangansatu == bilangandua) { /*kondisi dimana basis dan numerus sama akan return 1*/
        return 1; /*jika basis dan numerus sama maka akan mengembalikan nilai 1*/
    } else { 
    	 while (HasilPembagian >= bilangansatu) {/*looping sampai hasil pembagian / sisa sampai hasil pembagian kurang dari basis*/
                HasilPembagian = operasi_pembagian(HasilPembagian, bilangansatu);/*membagi dan sisanya akan di simpan di hasil pembagian*/
                Hasil =operasi_penjumlahan(Hasil, 1);/*setiap looping hasil bertambah 1*/ 
        }
        if(HasilPembagian != 1){ /*kondisi jika hasil pembagian tidak sama dengan satu artinya ada sisa yang menyebabkan hasil akan ada "," */
        	while(pow(bilangansatu,Hasil) <= bilangandua){ /*ulangi terus sampai Hasil mendekati dengan numerus namun tidak lebih dari numerus */
        		Hasil = operasi_penjumlahan(Hasil, temp); /*sisa */
			}
		}
    }
    return Hasil;
}

double operasi_logaritma_basis_sepuluh(double bilangansatu) {
	/*kamus data lokal*/
    double HasilPembagian = bilangansatu;
    double Hasil = 0;
    double temp = 0;
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
        		Hasil = pow(HasilPembagian, temp);
        		temp=operasi_penjumlahan(temp, delta);
			}
        }
    }
    return Hasil;
}

#endif
