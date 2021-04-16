#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "dosya.h"

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
		arr[i] = (double)tmp;
		i++;
	}
	*size = i;
	return arr;
}
