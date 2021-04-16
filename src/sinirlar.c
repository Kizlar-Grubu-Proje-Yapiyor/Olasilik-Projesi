#include <stdio.h>
#include <limits.h>
#include "main.h"
#include "sinirlar.h"

void sinirlar(FILE *fp)
{
	fprintf(fp,
	        "Sayi araligi: %d - %d\n"
	        "Maksimum sayi miktari: %d\n"
	        "Maksimum dosya ismi uzunlugu: %d\n",
	        INT_MIN, INT_MAX,
	        MAX_NUM,
	        MAX_DOSYA_ISIM_UZUNLUGU - 1);
}
