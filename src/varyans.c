#include "varyans.h"
#include "aritmetikortalama.h"
#include <math.h>

double varyans(int size, double *arr)
{
	double ao = aritmetik_ortalama(size, arr);
	for (int i = 0; i < size; i++) {
		arr[i] = arr[i] - ao;
		arr[i] = pow(arr[i], 2);
	}
	return aritmetik_ortalama(size, arr);
}
