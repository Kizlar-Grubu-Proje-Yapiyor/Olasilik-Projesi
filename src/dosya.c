#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "dosya.h"
#include "sinirlar.h"

double *dosyadan_oku(int *size, FILE *fp)
{
	int i = 0;
	double *arr;
	arr = malloc(sizeof(double) * MAX_NUM);
	if (arr == NULL) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	double tmp;
	while (1) {
		fscanf(fp, "%lf", &tmp);
		if (feof(fp))
			break;
		if (ferror(fp)) {
			fprintf(stderr, "Bir hata oldu!\n");
			exit(1);
		}
		if (i >= MAX_NUM) {
			fprintf(stderr, "Desteklenen maksimum sayi miktarindan "
			                "daha fazla sayi girdiniz!\nDesteklenen "
			                "maksimum sayi miktari: %d\n\n", MAX_NUM);
			sinirlar(stderr);
			exit(1);
		}
		arr[i] = (double)tmp;
		i++;
	}
	*size = i;
	return arr;
}
