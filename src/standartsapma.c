#include "standartsapma.h"
#include "varyans.h"
#include <math.h>

double standart_sapma(int size, double *arr)
{
	return sqrt(varyans(size, arr));
}
