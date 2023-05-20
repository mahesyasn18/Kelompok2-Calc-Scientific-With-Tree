#ifndef AhmadFauzy_dev_h
#define AhmadFauzy_dev_h
#include<stdio.h>
#define delta 0.000001

/*Nama : Ahmad Fauzy
  NIM : 221511040
  Kontrubusi : membuat modul pembagian , Logaritma biasa dan Logaritma basis 10
  referensi logika logaritma : https://www.ruangguru.com/blog/mengenal-logaritma-dan-sifat-sifatnya */
double operasi_pembagian(double bilangansatu, double bilangandua) {
    return (bilangansatu / bilangandua);
}

double operasiLogaritma(double bilangansatu, double bilangandua){
	/*ksmus data lokal*/
    double HasilPembagian = bilangandua;
    double sisa = 0;
    double Hasil = 0;
    /*algoritma*/
    if (bilangandua <= 0 || bilangansatu <= 0) { /*kondisi jika basis dan numerus lebih kecil dari 0*/
        printf("Invalid input \n");
        return 0.0 / 0.0;
    } else if (bilangansatu == bilangandua) { /*kondisi dimana basis dan numerus sama akan return 1*/
        return 1;
    } else { 
    	 while (HasilPembagian >= bilangansatu) {/*looping sampai hasil pembagian / sisa sampai hasil pembagian kurang dari basis*/
                HasilPembagian /= bilangansatu;/*membagi dan sisanya akan di simpan di hasil pembagian*/
                sisa=HasilPembagian;
                Hasil += 1;/*setiap luping hasil bertambah 1*/ 
        }
        if(HasilPembagian != 1){
        	Hasil+=sisa/bilangansatu;
		}
    }
    return Hasil;
}

double LogaritmaBasisSepuluh(double bilangansatu) {
	/*kamus data lokal*/
    double HasilPembagian = bilangansatu;
    double Hasil = 0;
	/*algoritma*/
    if (bilangansatu <= 0) {
        printf("Invalid input\n");
        return 0.0 / 0.0;
    } else {
        while (HasilPembagian >= 10) {
            HasilPembagian /= 10;
            Hasil += 1;
        }
        if (HasilPembagian != 1) {
            Hasil += HasilPembagian / 10;
        }
    }
    return Hasil;
}

#endif
