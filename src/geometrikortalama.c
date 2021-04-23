#include "geometrikortalama.h"
#include "algoritmalar.h"

double geometrik_ortalama(int size, double *arr)
{
	double ans = 1;
	for (int i = 0; i < size; i++) {
		ans *= pow(arr[i], (double)1 / (double)size);
	}
	return ans;
}
