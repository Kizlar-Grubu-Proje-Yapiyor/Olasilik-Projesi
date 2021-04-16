#include "main.h"

// long double based sorting
static void ldsort(double_t *arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				double_t tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static double_t max(double_t a, double_t b)
{
	return (a > b)? a: b;
}

static double_t min(double_t a, double_t b)
{
	return (a < b)? a: b;
}

static double_t ldabs(double_t a)
{
	return (a >= 0)? a: -a;
}
