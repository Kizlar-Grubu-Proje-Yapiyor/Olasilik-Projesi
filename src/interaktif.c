#include <stdio.h>
#include <stdlib.h>
#include "interaktif.h"

double_t *interaktif(int *size)
{
	double_t *arr;
	long long tmp;
	printf("Diziniz kac elemanli: ");
	scanf("%d", size);
	arr = (double_t *)malloc(sizeof(double_t) * (*size));
	if (!arr) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	printf("%d adet sayiyi giriniz: ", *size);
	for (int i = 0; i < (*size); i++) {
		scanf("%lld", &tmp);
		arr[i] = (double_t)tmp;
	}
	return arr;
}
