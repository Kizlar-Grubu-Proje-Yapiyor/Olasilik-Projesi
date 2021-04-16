#include <stdio.h>
#include <stdlib.h>
#include "interaktif.h"

double_t *interaktif(int *size)
{
	double_t *arr;
	double_t tmp;
	printf("Diziniz kac elemanli: ");
	scanf("%d", size);
	arr = (double_t *)malloc(sizeof(double_t) * (*size));
	if (!arr) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	printf("%d adet sayiyi giriniz: ", *size);
	for (int i = 0; i < (*size); i++) {
		scanf("%Lf", &tmp);
		arr[i] = tmp;
	}
	return arr;
}
