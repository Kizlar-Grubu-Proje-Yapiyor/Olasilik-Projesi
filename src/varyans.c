#include "varyans.h"
#include "aritmetikortalama.h"
#include "main.h"
#include <math.h>

double varyans(int size, double *arr)
{
	double ao = aritmetik_ortalama(size, arr);
	double arrtmp[size];
	for (int i = 0; i < size; i++) {
		arrtmp[i] = pow(arr[i] - ao, 2);
	}
	return aritmetik_ortalama(size, arrtmp);
}
