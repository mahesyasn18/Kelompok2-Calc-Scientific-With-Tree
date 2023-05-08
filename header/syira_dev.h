#include <stdio.h>
#include <string.h>
#include <math.h>
#ifndef syira_dev_H
#define syira_dev_H
#include <math.h>
#include <string.h>
#include "adinda_dev.h"

double operasi_pengurangan(double bilangansatu, double bilangandua ){
	//operasi pengurangan dengan menggunakan bilangan satu dan dua, lalu mengembalikan nilai dari pengurangan bilangan satu dan dua
	return bilangansatu - bilangandua;
}


double operasi_faktorial(double bilangan){
	int i;
	double pembagi;
	
	pembagi = bilangan; //membuat variable untuk di isikan dengan bilangan yang di masukkan
	for(i = 1; i < pembagi; i++){
		bilangan = operasiPerkalian(bilangan, i); // memanggil modul perkalian untuk operasi mengali dan memasukkan ke variable
	}
	
	return bilangan;
}




#endif
