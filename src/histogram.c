#include <stdio.h>
#include "histogram.h"
#include "frekans.h"

void histogram(int size, double *arr)
{
	int sinif;
	int *tmp = frekans_dizi(size, arr, &sinif);
	for (int i = 0; i < sinif * 3; i += 3) {
		if (tmp[i] == 0)
			break;
		printf("%d-%d\t\t", (int)tmp[i], (int)tmp[i + 1]);
		for (int j = 0; j < (int)tmp[i + 2]; j++)
			printf("|");
		printf("\n");
	}
}
