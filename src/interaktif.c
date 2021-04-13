#include "interaktif.h"

long double *interaktif(int *size)
{
	long double *arr;
	long long tmp;
	printf("Diziniz kac elemanli: ");
	scanf("%d", size);
	arr = (long double *)malloc(sizeof(long double) * (*size));
	if (!arr) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	printf("%d adet sayiyi giriniz: ", *size);
	for (int i = 0; i < (*size); i++) {
		scanf("%lld", &tmp);
		arr[i] = (long double)tmp;
	}
	return arr;
}
