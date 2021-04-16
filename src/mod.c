#include <limits.h>
#include <float.h>
#include "mod.h"
#include "algoritmalar.h"

double mod(int size, double *arr)
{
	d_sort(arr, size);
	int mx = INT_MIN;
	int cnt = 0, lasti = 0;
	double ans = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] == arr[i - 1]) {
			continue;
		} else {
			cnt = i - lasti - 1;
			if (mx < cnt) {
				ans = arr[i - 1];
				mx = cnt;
			}
			lasti = i;
		}
	}
	cnt = size - lasti - 1;
	if (mx < cnt) {
		ans = arr[size - 1];
		mx = cnt;
	}
	return ans;
}
