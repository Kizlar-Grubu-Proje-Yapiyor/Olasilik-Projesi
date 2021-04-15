#include <stdlib.h>
#include "algoritmalar.h"
#include "medyan.h"

double_t medyan(int size, double_t *arr)
{
	ldsort(arr, size);
	return (size % 2)? arr[size / 2]:
	(arr[size / 2 - 1] + arr[size / 2]) / 2;
}
