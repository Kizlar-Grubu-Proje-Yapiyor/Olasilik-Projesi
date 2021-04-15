#include <stdio.h>
#include <limits.h>
#include "main.h"
#include "sinirlar.h"

void sinirlar(FILE *fp)
{
	fprintf(fp,
	        "Sayi araligi: %lld - %lld\n"
	        "Maksimum sayi miktari: %d\n"
	        "Maksimum dosya ismi uzunlugu: %d\n",
	        LLONG_MIN, LLONG_MAX,
	        MAX_NUM,
	        MAX_DOSYA_ISIM_UZUNLUGU - 1);
}
