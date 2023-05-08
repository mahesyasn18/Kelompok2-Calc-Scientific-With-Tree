#include<stdio.h>

#include <math.h>

#ifndef adinda_dev_H
#define adinda_dev_H
#define PI 3.14159265358979323846#include "AhmadFauzy_dev.h"


double operasiPerkalian(double bilangansatu, double bilangandua) {
    return bilangansatu * bilangandua;
}

double operasiSinus(double bilangan) { // menghitung nilai sinus dari suatu sudut
    double radian = bilangan * (PI / 180); // inputan menggunakan satuan derajat sehigga perlu dikonversi terlebih dahulu menuju radian
    double jumlah = 0.0; // untuk menghitung nilai jumlah semua sukunya
    double nilaipersuku = radian; // nilaipersuku adalah nilai yang dihasilkan pengoperasian per sukunya

    int n = 1;
    while (nilaipersuku != 0.0) {
        jumlah += nilaipersuku;
        n += 2; // ditambahkan dengan 2 karena suku yg digunakan adalah suku ganjil sebab turunan ganjil merupakan sinus itu sendiri
        nilaipersuku = (-1.0) * nilaipersuku * radian * radian / ((n - 1) * n); //menggunakan deret taylor
    }
    return jumlah;
}

double operasiCosinus(double bilangan) { // menghitung nilai cosinus dari suatu sudut
    double radian = bilangan * (PI / 180); // inputan menggunakan satuan derajat sehigga perlu dikonversi terlebih dahulu menuju radian
    double jumlah = 0.0; // untuk menghitung nilai jumlah semua sukunya
    double nilaipersuku = 1; // nilaipersuku adalah nilai yang dihasilkan pengoperasian per sukunya

    int n = 0; // dimulai dari nol karena yang digunakan suku genap, turunan genap untuk cosinus merupakan cosinus itu sendiri
    while (nilaipersuku != 0.0) {
        jumlah += nilaipersuku;
        n += 2;
        nilaipersuku = (-1.0) * nilaipersuku * radian * radian / ((n - 1) * n);
    }
    return jumlah;
}

double operasiTangen(double bilangan) {
    double result;
    if (bilangan == 90 || bilangan == 270) {
        printf("Not Defined \n");
    } else {
        result = operasiPembagian(operasiSinus(bilangan), operasiCosinus(bilangan)); //tangen merupakan hasil bagi sin dengan cos
        return (result);
    }

}

double operasiCosecan(double bilangan) {
    double result;
    if (bilangan == 0 || bilangan == 180 || bilangan == 360) {
        printf("Not Defined \n");
    } else {
        result = operasiPembagian(1, operasiSinus(bilangan)); // cosecan merupakan satu per dari sinus
        return (result);
    }

}

double operasiSecan(double bilangan) {
    double result;
    if (bilangan == 90 || bilangan == 270) {
        printf("Not Defined \n");
    } else {
        result = operasiPembagian(1, operasiCosinus(bilangan)); //tangen merupakan hasil bagi sin dengan cos
        return (result);
    }
}

double operasiCotangen(double bilangan) {
    double result;
    if (bilangan == 0 || bilangan == 180 || bilangan == 360) {
        printf("Not Defined \n");
    } else {
        result = operasiPembagian(1, operasiTangen(bilangan)); // cosecan merupakan satu per dari sinus
        return (result);
    }
}

double konversi_fahrenheit(double bilangan) {
    double result;
    result = (9.0 / 5.0 * bilangan) + 32;
    return result;
}

double konversi_kelvin(double bilangan) {
    double result;
    result = bilangan + 273.15;
    return result;
}

float konversi_reamur(float bilangan) {
    float result;
    result = bilangan * (4.0 / 5.0);
    return result;
}

#endif