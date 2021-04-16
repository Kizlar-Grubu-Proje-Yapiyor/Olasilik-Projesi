#include "ortalamasapma.h"
#include "algoritmalar.h"
#include "aritmetikortalama.h"

double_t ortalamasapma(int size, double_t *arr){
	double_t ao = aritmetik_ortalama(size, arr);
	double_t tmp = 0;
	for (int i = 0; i < size; i++) {
		tmp += ldabs(ao - arr[i]);
	}
	return tmp / (double_t)size;
}
