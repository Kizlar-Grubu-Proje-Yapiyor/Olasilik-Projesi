#include "geometrikortalama.h"
#include "algoritmalar.h"

double_t geometrik_ortalama(int size, double_t *arr)
{
	double_t tmp = 1;
	for (int i = 0; i < size; i++) {
		tmp *= arr[i];
	}
	return ld_root(tmp, size);
}
