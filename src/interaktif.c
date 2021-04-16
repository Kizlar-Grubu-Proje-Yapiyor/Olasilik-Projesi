#include <stdio.h>
#include <stdlib.h>
#include "interaktif.h"

double *interaktif(int *size)
{
	double *arr;
	double tmp;
	printf("Diziniz kac elemanli: ");
	scanf("%d", size);
	arr = (double *)malloc(sizeof(double) * (*size));
	if (!arr) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	printf("%d adet sayiyi giriniz: ", *size);
	for (int i = 0; i < (*size); i++) {
		scanf("%lf", &tmp);
		arr[i] = tmp;
	}
	return arr;
}
