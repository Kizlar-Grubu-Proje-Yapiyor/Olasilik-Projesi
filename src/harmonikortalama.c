#include "harmonikortalama.h"

double_t harmonikortalama(int size, double_t *arr)
{
	double_t tmp = 0;
	for (int i = 0; i < size; i++) {
		tmp += 1 / arr[i];
	}
	return (double_t)size / tmp;
}
