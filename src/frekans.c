#include <stdio.h>
#include <stdlib.h>
#include "frekans.h"
#include "algoritmalar.h"

void frekans(int size, double *arr, int sinif)
{
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
			printf("%d-%d\t\t%d\n", sinif_baslangic, (int)arr[i], f_cnt);
			sinif_baslangic = arr[i];
			f_cnt = 0;
			continue;
		}
	}
	f_cnt++;
	printf("%d-%d\t\t%d\n", sinif_baslangic, sinif_baslangic + sinif_araligi, f_cnt);
}
