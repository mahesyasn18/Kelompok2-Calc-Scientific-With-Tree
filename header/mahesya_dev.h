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

//fungsi operasi akar
double operasiAkar(double bilangansatu, double bilangandua) {
	double rendah = 0, tinggi = bilangansatu, tengah, hasil;
	
	while (rendah <= tinggi) {
	//memanggil fungsi operasiPembagian pada AhmadFauzy_dev.h 
    tengah = operasiPembagian(operasiPenjumlahan(rendah, tinggi),2);
    hasil = tengah;
    
    //memanggil fungsi operasiPangkat pada Faisal_dev.h 
    tengah = operasiPangkat(tengah, bilangandua);
    
    //memanggil fungsi untuk mencari nilai absolute dari hasil pengurangan nilai pada tengah dan bilangansatu lalu dibandingkan dengan 0.00001
    if (fabs(operasiPengurangan(tengah,bilangansatu)) < 0.00001)
    	return hasil;
    else if (tengah < bilangansatu)
        rendah = hasil;
    else
        tinggi = hasil;
   }
   
   return hasil;
}

double operasiAkardua(double bilangan){
	return sqrt(bilangan);
}

//fungsi operasi Asin

double operasiAsin(double bilangan) {
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


double operasiAcos(double x) {
    if (x > 1.0 || x < -1.0) {
        return -1.0; //nilai yang tidak valid
    }
    double asin_value = operasiAsin(x);
    return  90.0 - asin_value;
}

//fungsi operasi Atan

double operasiAtan(double x) {
	if (x > 1.0 || x < -1.0) {
	return -1.0; //nilai yang tidak valid
	}
	return operasiAcos(sqrt(1.0 / (x*x + 1.0)));
}









#endif

