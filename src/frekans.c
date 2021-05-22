#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "frekans.h"
#include "algoritmalar.h"

void frekans(int size, double *arr)
{
	int sinif = 0;
	int *tmp = frekans_dizi(size, arr, &sinif);
	for (int i = 0; i < sinif * 3; i += 3) {
		printf("%d-%d\t\t%d\n", tmp[i], tmp[i + 1], tmp[i + 2]);
	}
	free(tmp);
	tmp = NULL;
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
int *frekans_dizi(int size, double *arr, int *sinif)
{
	int sinif_tmp = d_to_int(1 + 3.3 * log10(size));
	*sinif = sinif_tmp;

	int *tmp = (int *)malloc(sizeof(int) * sinif_tmp * 3);
	if (!tmp) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}

	int j = 0;
	qsort(arr, size, sizeof(double), cmpfunc);

	int sinif_araligi = d_to_int_up((arr[size - 1] - arr[0]) / sinif_tmp);
	int alt_deger = arr[0], ust_deger = arr[0] + sinif_araligi;
	int f_cnt = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] >= ust_deger) {
			tmp[j++] = alt_deger;
			tmp[j++] = ust_deger;
			tmp[j++] = f_cnt;
			alt_deger = ust_deger;
			ust_deger = alt_deger + sinif_araligi;
			f_cnt = 0;
		}
		f_cnt++;
	}
	tmp[j++] = alt_deger;
	tmp[j++] = ust_deger;
	tmp[j++] = f_cnt;
	return tmp;
}
