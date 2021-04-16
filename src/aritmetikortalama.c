#include "aritmetikortalama.h"

double aritmetik_ortalama(int size, double *arr)
{
	double ans = 0;
	for (int i = 0; i < size; i++) {
		ans += arr[i] / (double)size;
	}
	return ans;
}
