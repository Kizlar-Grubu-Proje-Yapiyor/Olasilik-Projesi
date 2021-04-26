#include <stdio.h>
#include <stdlib.h>
#include "interaktif.h"
#include "main.h"
#include "sinirlar.h"

double *interaktif(int *size)
{
	double *arr;
	double tmp;
	printf("Diziniz kac elemanli: ");
	scanf("%d", size);
	if (*size > MAX_NUM) {
		fprintf(stderr, "Desteklenen maksimum sayi miktarindan "
		                "daha fazla sayi girdiniz!\nDesteklenen "
		                "maksimum sayi miktari: %d\n\n", MAX_NUM);
		sinirlar(stderr);
		exit(1);
	}
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
