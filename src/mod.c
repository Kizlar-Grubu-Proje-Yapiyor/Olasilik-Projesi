#include <limits.h>
#include "mod.h"

double mod(int size, double *arr)
{
	double mx = INT_MIN, ans = 0, cnt;

	for (int i = 0; i < size; i++) {
		cnt = 0;
		if (mx == arr[i]) {
			continue;
		}
		for (int j = 0; j < size; j++) {
			if (arr[i] == arr[j])
				cnt++;
		}
		if (mx < cnt) {
			mx = cnt;
			ans = arr[i];
		}
	}

	return ans;
}
