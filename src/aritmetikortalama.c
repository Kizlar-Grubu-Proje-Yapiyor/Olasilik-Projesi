/*
 * Author: Ceyhun Sen
 * */

#include "aritmetikortalama.h"

double aritmetik_ortalama(int size, double *arr)
{
	double ans = 0;
	for (int i = 0; i < size; i++) {
		ans += (double)arr[i];
	}
	if (size <= 0)
		return 0;
	return ans / size;
}
