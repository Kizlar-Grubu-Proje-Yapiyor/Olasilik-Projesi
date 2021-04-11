#include "yardim.h"

void yardim(FILE *fp, const char *argv)
{
	fprintf(fp,
	        "Kullanim: %s [SECENEK] [OPSIYONEL ARGUMANLAR]\n"
	        "Secenekler:\n\n"
	        "-y, --yardim\n"
	        "\tYardimi goruntule\n"
			"-s, --sinirlar\n"
			"\tBagli oldugunuz sinirlari goruntuler\n"
	        "-d [DOSYA], --dosya [DOSYA]\n"
	        "\tGirdiyi belirtilen dosyadan al\n"
            "\n"
            "--aritmetik-ortalama [SAYILAR]\n"
	        "\tVerilen sayilarin aritmetik ortalamasini hesaplar\n");
}
