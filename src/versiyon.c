#include <stdio.h>
#include "versiyon.h"

void versiyon(FILE *fp)
{
	fprintf(fp,
	        "MAT0293 Olasilik ve Istatistik Projesi v1.4\n\n"
	        "Bu program GNU General Public License v3.0 ile lisanslanmistir. "
	        "Daha fazla bilgi icin 'LICENCE' adli dosyayi inceleyiniz.\n\n"
	        "Bu proje Ali Cuneyt Caglar, Ali Furkan Demir, Ceyhun Sen, Halil "
	        "Karatas ve Ibrahim Yahya Aydinli tarafindan yapilmistir.\n\n"
	        "Bursa Teknik Universitesi, 2021\n"
	        );
}
