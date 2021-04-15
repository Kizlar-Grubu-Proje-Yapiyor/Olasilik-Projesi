#include <limits.h>
#include "mod.h"
#include "algoritmalar.h"

// i am too lazy to write a dictionary lib, so here is a really bad algorithm
double_t mod(int size, double_t *arr)
{
	ldsort(arr, size);
	double_t mx = (double_t)LLONG_MIN;
	int cnt = 0, lasti = 0, ans = arr[0];
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
