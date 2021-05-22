#include "permutasyon.h"
#include "algoritmalar.h"

double permutasyon(double base, double power)
{
	return (d_factorial(base) / d_factorial(base - power));
}
