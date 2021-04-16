#include "geometrikortalama.h"
#include "algoritmalar.h"

double geometrik_ortalama(int size, double *arr)
{
	double tmp = 1;
	for (int i = 0; i < size; i++) {
		tmp *= arr[i];
	}
	return ld_root(tmp, size);
}
