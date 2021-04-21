#include <limits.h>
#include "mod.h"
#include "algoritmalar.h"

double mod(int size, double *arr)
{
	DICT *dict = create_dict();
	for (int i = 0; i < size; i++) {
		insert_dict(dict, arr[i]);
	}
	double ans = mx_key(dict);
	free_dict(dict);
	return ans;
}
