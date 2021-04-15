#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "dosya.h"

double_t *dosyadan_oku(int *size, FILE *fp)
{
	int i = 0;
	double_t *arr;
	arr = malloc(sizeof(double_t) * MAX_NUM);
	if (arr == NULL) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	double_t tmp;
	while (1) {
		fscanf(fp, "%Lf", &tmp);
		if (feof(fp))
			break;
		if (ferror(fp)) {
			fprintf(stderr, "Bir hata oldu!\n");
			exit(1);
		}
		arr[i] = (double_t)tmp;
		i++;
	}
	*size = i;
	return arr;
}
