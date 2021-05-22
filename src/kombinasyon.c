#include "kombinasyon.h"
#include "algoritmalar.h"

double kombinasyon(double base, double power)
{
	return d_factorial(base) / (d_factorial(base - power) * (d_factorial(power)));
}
