#include "yardim.h"

void yardim(FILE *fp, const char *argv)
{
	fprintf(fp, "Kullanim: %s [SECENEK]\nSecenekler:\n\n", argv);
	fprintf(fp, "-y, --yardim\n");
	fprintf(fp, "\tYardimi goruntule\n");
	fprintf(fp, "-d [DOSYA], --dosya [DOSYA]\n");
	fprintf(fp, "\tCiktiyi belirtilen dosyaya yonlendir\n");
}
