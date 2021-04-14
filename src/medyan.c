#include "medyan.h"

long double medyan(int size, long double *arr)
{
	ldsort(arr, size);
	return (size % 2)? arr[size / 2]:
	(arr[size / 2 - 1] + arr[size / 2]) / 2;
}
