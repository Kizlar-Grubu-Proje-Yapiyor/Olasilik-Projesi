#include "ortalamasapma.h"
#include "algoritmalar.h"
#include "aritmetikortalama.h"

double ortalamasapma(int size, double *arr){
	double ao = aritmetik_ortalama(size, arr);
	double tmp = 0;
	for (int i = 0; i < size; i++) {
		tmp += ldabs(ao - arr[i]);
	}
	return tmp / (double)size;
}
