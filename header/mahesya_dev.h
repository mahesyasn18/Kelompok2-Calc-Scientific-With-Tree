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
double operasi_akar(double bilangansatu, double bilangandua) {
    /* modul operasi_akar adalah modul yang digunakan untuk operasi akar dinamis (diluar dari akar pangkat 2)
    sebagai contoh 3 akar 9 */

    double rendah = 0, tinggi = bilangansatu, tengah, hasil;

    /*dilakukan pengulangan hingga nilai variable rendah lebih kecil dari tinggi*/
    while (rendah <= tinggi) {
        /* variable tengah diisi dengan hasil pembagian antara penjumlahan dari nilai rendah dan tinggi dibagi 2*/
        tengah = operasi_pembagian(operasi_penjumlahan(rendah, tinggi), 2);
        hasil = tengah;

        /* variable tengah diisi dengan hasil pangkat dari bilangan tengah tersebut dan bilangandua */
        tengah = operasi_pangkat(tengah, bilangandua);

        /*memanggil fungsi fabs untuk mencari nilai absolute dari hasil pengurangan nilai pada tengah dan bilangansatu lalu dibandingkan dengan 0.00001*/
        if (fabs(operasi_pengurangan(tengah, bilangansatu)) < 0.00001)
            return hasil;
        else if (tengah < bilangansatu)
            rendah = hasil;
        else
            tinggi = hasil;
    }

    return hasil;
}

/* fungsi operasi akar dua */
double operasi_akar_dua(double bilangan) {
    /* modul operasi_akar adalah modul yang digunakan untuk operasi akar dinamis (diluar dari akar pangkat 2)
    sebagai contoh 3 akar 9 */
    double precision = 0.0001;
    double guess = bilangan;
    while ((guess - bilangan / guess) > precision) {
        guess = (guess + bilangan / guess) / 2;
    }
    return guess;
}

//fungsi operasi Asin

double operasi_asin(double bilangan) {
    double sum = bilangan;
    double term = bilangan;
    int n = 1;
    while (term > 0.0000001 || term < -0.0000001) { //ketelitian yang diinginkan
        term = term * bilangan * bilangan * (2 * n - 1) * (2 * n - 1) / (2 * n * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum * 180 / PI;
}

//fungsi operasi Acos

double operasi_acos(double x) {
    if (x > 1.0 || x < -1.0) {
        return -1.0; //nilai yang tidak valid
    }
    double asin_value = operasi_asin(x);
    return 90.0 - asin_value;
}

//fungsi operasi Atan

double operasi_atan(double x) {
    if (x > 1.0 || x < -1.0) {
        return -1.0; //nilai yang tidak valid
    }
    return operasi_acos(sqrt(1.0 / (x * x + 1.0)));
}

#endif