#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "frekans.h"
#include "algoritmalar.h"

void frekans(int size, double *arr)
{
	int *tmp = frekans_dizi(size, arr);
	for (int i = 0; i < (10 + 1) * 3; i += 3) {
		if (tmp[i] == 0)
			break;
		printf("%d-%d\t\t%d\n", tmp[i], tmp[i + 1], tmp[i + 2]);
	}
}

/*
 * dondurulen dizinin yapisi:
 * i % 3 == 0 olmak uzere
 * tmp[i] -> sinif baslangic degeri
 * tmp[i + 1] -> sinif bitis degeri (dahil degil)
 * tmp[i + 2] -> sinifin frekansi
 * dizi boyutu (sinif + 1) * 3
 * dizinin son 3 elemani sifir olabilir
 * bu yuzden kontrol etmelisiniz
 * ve biliyorum, berbat bir fonksiyon
 * */
int *frekans_dizi(int size, double *arr)
{
	int sinif = 1 + 3.3 * log(size);
	int *tmp = (int *)calloc(sizeof(int), (sinif + 1) * 3);
	if (!tmp) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	int j = 0;
	qsort(arr, size, sizeof(double), cmpfunc);
	double sinif_araligi_tmp = (arr[size - 1] - arr[0]) / (double)sinif;
	double ondalik = sinif_araligi_tmp - (int)sinif_araligi_tmp;
	int sinif_araligi = (int)sinif_araligi_tmp;
	if (ondalik >= 0.5)
		sinif_araligi++;
	int sinif_baslangic = arr[0];
	int f_cnt = 0;
	for (int i = 1; i < size; i++) {
		f_cnt++;
		if (arr[i] - sinif_baslangic >= sinif_araligi) {
			tmp[j++] = sinif_baslangic;
			tmp[j++] = (int)arr[i];
			tmp[j++] = f_cnt;
			sinif_baslangic = arr[i];
			f_cnt = 0;
			continue;
		}
	}
	f_cnt++;
	tmp[j++] = sinif_baslangic;
	tmp[j++] = sinif_baslangic + sinif_araligi;
	tmp[j++] = f_cnt;
	return tmp;
}
