#include "aritmetikortalama.h"

long double aritmetik_ortalama(int size, long double *arr)
{
	long double ans = 0;
	for (int i = 0; i < size; i++) {
		ans += arr[i] / (long double)size;
	}
	return ans;
}
