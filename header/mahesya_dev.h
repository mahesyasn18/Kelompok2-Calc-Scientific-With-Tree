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
double operasiAsin(double bilangan){
    if(bilangan>1 || bilangan<-1)
    {
        printf("not define\n");
    }
    else
    {
        return asin(bilangan)* SUDUT/ PI;
    }
}


//fungsi operasi Acos
double operasiAcos(double bilangan) {
	if(bilangan>1 || bilangan<-1)
    {
        printf("not define\n");
    }
    else
    {
		return acos(bilangan)*SUDUT/ PI;
    }
    
}
//fungsi operasi Atan
double operasiAtan(double bilangan) {
    return atan(bilangan) * SUDUT/ PI;
}








#endif

