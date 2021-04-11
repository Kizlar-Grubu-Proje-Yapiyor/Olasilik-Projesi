#include "sinirlar.h"

void sinirlar(FILE *fp)
{
	fprintf(fp,
	        "Sayi araligi: %lld - %lld\n"
	        "Maksimum sayi miktari: %lld\n"
	        "Maksimum dosya ismi uzunlugu: %lld\n",
	        LLONG_MIN, LLONG_MAX,
	        MAX_NUM,
	        MAX_DOSYA_ISIM_UZUNLUGU - 1);
}
