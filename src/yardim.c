#include "yardim.h"

void yardim(FILE *fp, const char *argv)
{
	fprintf(fp, "Kullanim: %s [ARGUMAN] [OPSIYONEL ARGUMANLAR]\n");
	fprintf(fp, "Secenekler:\n\n", argv);
	fprintf(fp, "-y, --yardim\n");
	fprintf(fp, "\tYardimi goruntule\n");
	fprintf(fp, "-d [DOSYA], --dosya [DOSYA]\n");
	fprintf(fp, "\tGirdiyi belirtilen dosyadan al\n");

	fprintf(fp, "\n");

	fprintf(fp, "--aritmetik-ortalama [SAYILAR]\n");
	fprintf(fp, "\tVerilen sayilarin aritmetik ortalamasini hesaplar\n");
}
