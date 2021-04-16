#include "main.h"

static void ldsort(double_t *arr, int size);
static double_t max(double_t a, double_t b);
static double_t min(double_t a, double_t b);
static double_t ldabs(double_t a);
static double_t ld_root(double_t base, double_t power);
static double_t ld_pow(double_t base, double_t power);

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

// wrong algorithm for root. only works with base 2 and 3
static double_t ld_root(double_t base, double_t power)
{
	return ld_pow(base, (double_t)1 / power);
}

static double_t ld_pow(double_t base, double_t power)
{
	double_t tmp = 1;
	for (int i = 0; i < power; i++)
		tmp *= base;
	return tmp;
}
