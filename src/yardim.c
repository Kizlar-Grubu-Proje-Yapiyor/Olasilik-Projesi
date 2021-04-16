#include <stdio.h>
#include "yardim.h"

void yardim(FILE *fp, const char *argv)
{
	fprintf(fp,
	        "Kullanim: %s [SECENEK] [DEGER(LER)]\n\n"
	        "Secenekler:\n"
	        "-y, --yardim\n"
	        "\tYardimi goruntuler\n"
	        "-s, --sinirlar\n"
	        "\tBagli oldugunuz sinirlari goruntuler\n"
	        "-i, --interaktif\n"
	        "\tGerekli sayilari interaktif modda alir\n"
	        "-d [DOSYA], --dosya [DOSYA]\n"
	        "\tGirdiyi belirtilen dosyadan alir\n"
	        "\n"
	        "--aritmetik-ortalama [DEGER(LER)]\n"
	        "\tVerilen sayilarin aritmetik ortalamasini hesaplar\n"
	        "--harmonik-ortalama [DEGER(LER)]\n"
	        "\tVerilen sayilarin harmonik ortalamasini hesaplar\n"
	        "--geometrik-ortalama [DEGER(LER)]\n"
	        "\tVerilen sayilarin geometrik ortalamasini hesaplar\n"
	        "--medyan [DEGER(LER)]\n"
	        "\tVerilen sayilarin medyanini (ortanca) hesaplar\n"
	        "--mod [DEGER(LER)]\n"
	        "\tVerilen sayilarin modunu hesaplar\n"
	        "--ortalama-sapma [DEGER(LER)]\n"
	        "\tVerilen sayilarin ortalama sapmasini hesaplar\n"
	        , argv);
}
