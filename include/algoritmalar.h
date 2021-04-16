#include "main.h"
#include <math.h>

static void ldsort(double *arr, int size);
static double max(double a, double b);
static double min(double a, double b);
static double ldabs(double a);
static double ld_root(double base, double power);
static double ld_pow(double base, double power);

// long double based sorting
static void ldsort(double *arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				double tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static double max(double a, double b)
{
	return (a > b)? a: b;
}

static double min(double a, double b)
{
	return (a < b)? a: b;
}

static double ldabs(double a)
{
	return (a >= 0)? a: -a;
}

// wrong algorithm for root. only works with base 2 and 3
static double ld_root(double base, double power)
{
	return pow(base, (double)1 / power);
}

static double ld_pow(double base, double power)
{
	double tmp = 1;
	for (int i = 0; i < power; i++)
		tmp *= base;
	return tmp;
}
