#include "main.h"
#include <math.h>

static void d_sort(double *arr, int size);
static double d_max(double a, double b);
static double d_min(double a, double b);
static double d_abs(double a);
static double d_root(double base, double power);


static void d_sort(double *arr, int size)
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

static double d_max(double a, double b)
{
	return (a > b)? a: b;
}

static double d_min(double a, double b)
{
	return (a < b)? a: b;
}

static double d_abs(double a)
{
	return (a >= 0)? a: -a;
}

static double d_root(double base, double power)
{
	return pow(base, (double)1 / power);
}
