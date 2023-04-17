#include <stdio.h>
#include <string.h>
#include <math.h>
#ifndef syira_dev_H
#define syira_dev_H
#include <math.h>
#include <string.h>

double operasiPengurangan(double bilangansatu, double bilangandua ){
	return bilangansatu - bilangandua;
}

double operasiSinus(double bilangan)
{
	double radian;
    radian = bilangan * M_PI /180;
    return sin(radian);
}

double operasiFaktorial(double factorial){
	int i, n;
	n = factorial;
	factorial = 1;
	for (i = 1; i <= n; ++i)
    {
    	factorial *= i;
    }
}




#endif
