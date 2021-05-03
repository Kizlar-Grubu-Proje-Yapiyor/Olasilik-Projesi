#include "degisimkatsayisi.h"
#include "standartsapma.h"
#include "aritmetikortalama.h"

double degisim_katsayisi(int size, double *arr)
{
	return (standart_sapma(size, arr) / aritmetik_ortalama(size, arr)) * 100;
}
