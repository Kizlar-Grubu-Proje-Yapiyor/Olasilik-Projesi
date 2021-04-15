#include "aritmetikortalama.h"

double_t aritmetik_ortalama(int size, double_t *arr)
{
	double_t ans = 0;
	for (int i = 0; i < size; i++) {
		ans += arr[i] / (double_t)size;
	}
	return ans;
}
