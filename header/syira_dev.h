#include <stdio.h>
#include <string.h>
#include <math.h>
#ifndef syira_dev_H
#define syira_dev_H
#include <math.h>
#include <string.h>
#include "adinda_dev.h"

double operasiPengurangan(double bilangansatu, double bilangandua ){
	return bilangansatu - bilangandua;
}


double operasiFaktorial(double bilangan){
	int i;
	double pembagi;
	
	pembagi=bilangan;
	for(i=1;i<pembagi;i++){
		bilangan=operasiPerkalian(bilangan,i);
	}
	
	return bilangan;
}




#endif
