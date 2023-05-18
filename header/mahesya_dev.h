#ifndef mahesya_dev_H
#define mahesya_dev_H

#include<math.h>
#define PI 3.14159265358979323846
#define SUDUT 180.0
#include "Faisal_dev.h"
#include "AryaKusumah_dev.h"
#include "AhmadFauzy_dev.h"
#include "adinda_dev.h"
#include "syira_dev.h"

/* fungsi operasi akar dinamis */
double operasi_akar_dinamis(double bilangansatu, double bilangandua) {
	/* referensi: https://www.geeksforgeeks.org/square-root-of-a-number-without-using-sqrt-function/ */
    double rendah = 0, tinggi = bilangansatu, tengah, hasil;

    while (rendah <= tinggi) {
    	/* Menghitung tengah sebagai rata-rata rendah dan tinggi */
        tengah = operasi_pembagian(operasi_penjumlahan(rendah, tinggi), 2);
        
        /* Menggunakan nilai tengah sebagai tebakan akar */
        hasil = tengah; 

		/* Menghitung tebakan pangkat */
        tengah = operasi_pangkat(tengah, bilangandua); 

		/* Jika selisih antara tebakan pangkat dan bilangansatu kurang dari presisi yang diberikan */
        if (fabs(operasi_pengurangan(tengah, bilangansatu)) < 0.00001)
            return hasil; /* Mengembalikan tebakan akar */ 
        else if (tengah < bilangansatu)
            rendah = hasil; /* Jika tebakan pangkat terlalu rendah, ubah rendah menjadi hasil */ 
        else
            tinggi = hasil; /* Jika tebakan pangkat terlalu tinggi, ubah tinggi menjadi hasil */  
    }

	/* Mengembalikan tebakan akhir sebagai hasil akar */
    return hasil;
}

/* fungsi operasi akar dua */
double operasi_akar_dua(double bilangan) {
	/* referensi: https://www.geeksforgeeks.org/square-root-of-a-number-without-using-sqrt-function/ */

	/* Memperhitungkan nilai-nilai persamaan */
	double tebakan_awal = bilangan;
	double hasil = operasi_pembagian(operasi_penjumlahan(tebakan_awal,operasi_pembagian(bilangan,tebakan_awal)) ,2);

	/* Karena ingin mendapatkan hingga 5 angka desimal, perbedaan absolut */
	/* tidak boleh melebihi 0.00001 */
	while (fabs(operasi_pengurangan(tebakan_awal,hasil)) >= 0.00001) {
	    tebakan_awal = hasil;
	    hasil =  operasi_pembagian(operasi_penjumlahan(tebakan_awal,operasi_pembagian(bilangan,tebakan_awal)) ,2);
	}
	return hasil;
}

/* Fungsi Operasi Asin */
double operasi_asin(double bilangan) {
	/* referensi: https://stackoverflow.com/questions/20196000/own-asin-function-with-taylor-series-not-accurate*/
	if (bilangan > 1.0 || bilangan < -1.0) {
        printf("Not Define\n"); /* nilai yang tidak valid */
        return 0;
    }
    /* Inisialisasi jumlah dengan suku awal sebanyak bilangan */
    double jumlah = bilangan;  
    /* Inisialisasi suku dengan suku awal sebanyak bilangan */
    double suku = bilangan; 
    /* Mulai dengan n = 1 */
    int n = 1;  

    while (suku > 0.0000001 || suku < -0.0000001) {
        /* Hitung suku berikutnya */
        //suku = suku * bilangan * bilangan * (2 * n - 1) * (2 * n - 1) / (2 * n * (2 * n + 1));
        suku = operasi_pembagian(operasi_perkalian(suku, operasi_perkalian(bilangan,operasi_perkalian(bilangan,operasi_perkalian(operasi_pengurangan(operasi_perkalian(2,n),1),operasi_pengurangan(operasi_perkalian(2,n),1))))), operasi_perkalian(2,operasi_perkalian(n,operasi_penjumlahan(1,operasi_perkalian(2,n)))));
        
        /* Tambahkan suku ke jumlah */
        jumlah =  operasi_penjumlahan(jumlah,suku);
        /* Tambahkan nilai n untuk iterasi berikutnya */
        n++; 
    }

    /* Konversi hasil dari radian ke derajat */
    return jumlah * 180 / PI;
}

/* fungsi operasi Acos */
double operasi_acos(double bilangan) {
    if (bilangan > 1.0 || bilangan < -1.0) {
        printf("Not Define\n"); 
        return 0;
    }
    /* mencari nilai asin (dalam derajat) */
    double nilai_asin = operasi_asin(bilangan);
    
    /* Mengembalikan hasil pengurangan nilai_asin dari setengah sudut (SUDUT/2) yang mana menjadi hasil operasi acos (dalam derajat)*/
    return operasi_pengurangan(operasi_pembagian(SUDUT,2),nilai_asin);
}


/* fungsi operasi Atan */
double operasi_atan(double bilangan) {
    if (bilangan > 1.0 || bilangan < -1.0) {
        printf("Not Define\n"); /* nilai yang tidak valid */
        return 0;
    }
    
    /* Mengembalikan hasil operasi atan yang berasal dari operasi acos dari hasil akar dua */
    return operasi_acos(operasi_akar_dua(operasi_pembagian(1.0,operasi_penjumlahan(operasi_perkalian(bilangan,bilangan), 1.0))));
}

#endif
