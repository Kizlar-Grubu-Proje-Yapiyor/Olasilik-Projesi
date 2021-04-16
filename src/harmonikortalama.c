#include "harmonikortalama.h"

double harmonik_ortalama(int size, double *arr)
{
	double tmp = 0;
	for (int i = 0; i < size; i++) {
		tmp += 1 / arr[i];
	}
	return (double)size / tmp;
}
