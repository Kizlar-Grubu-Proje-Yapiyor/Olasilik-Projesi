#include "dosya.h"

long double *dosyadan_oku(int *size, FILE *fp)
{
	int i = 0;
	long double *arr;
	arr = malloc(sizeof(long double) * MAX_NUM);
	if (arr == NULL) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	long long tmp;
	while (1) {
		fscanf(fp, "%lld", &tmp);
		if (feof(fp))
			break;
		if (ferror(fp)) {
			fprintf(stderr, "Bir hata oldu!\n");
			exit(1);
		}
		arr[i] = (long double)tmp;
		i++;
	}
	*size = i;
	return arr;
}
