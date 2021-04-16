#include "harmonikortalama.h"

double harmonikortalama(int size, double *arr)
{
	double tmp = 0;
	for (int i = 0; i < size; i++) {
		tmp += 1 / arr[i];
	}
	return (double)size / tmp;
}
