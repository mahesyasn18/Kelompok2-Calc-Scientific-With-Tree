 /*
Dibuat oleh : Arya Putra Kusumah
Deskripsi : Membuat Operasi perhitungan:
Operasi Penjumlahan
Operasi Modulus
*/

        

#ifndef AryaKusumah_dev_H
#define AryaKusumah_dev_H

/*Menghitung operasi penjumlahan dengan menggunakan bilangan satu dan dua*/
double operasi_penjumlahan(double bilangansatu, double bilangandua){
	return bilangansatu + bilangandua; 
}

/*Menghitung operasi modulus yang satu bilangannya habis di bagi dengan bilangan lain dengan 
menggunakan "&" yang seharusnya menggunakan "%" dikarenakan "%" sudah dipakai pada operasi lain*/
double operasi_modulus (double bilangansatu, double bilangandua){
    /*Referensi : https://www.tutorialspoint.com/cplusplus-program-to-convert-double-type-variables-into-int*/
    
    /*Bilangan satu dan dua di konversi dari double ke integer dengan perintah (int)*/
    return (int)bilangansatu%(int)bilangandua;

}



#endif
