#include <stdio.h>
#include "yardim.h"

void yardim(FILE *fp, const char *argv)
{
	fprintf(fp,
	        "Kullanim:\n"
	        " %s [SECENEK(LER)] [DEGER(LER)]\n"
	        " %s [SECENEK(LER)] N R\n"
	        "\n"
	        "Genel secenekler:\n"
	        " -y, --yardim\n"
	        "\tYardimi goruntuler\n"
	        " -v, --versiyon\n"
	        "\tVersiyon bilgisini goruntuler\n"
	        " -s, --sinirlar\n"
	        "\tBagli oldugunuz sinirlari goruntuler\n"
	        " -i, --interaktif\n"
	        "\tGerekli sayilari interaktif modda alir\n"
	        " -d [DOSYA], --dosya [DOSYA]\n"
	        "\tGirdiyi belirtilen dosyadan alir\n"
	        " --detay\n"
	        "\tCiktida hangi formulun cevabi oldugunu da yazar\n"
	        " --butun-formuller\n"
	        "\tDizi ile hesaplanabilen butun formulleri hesaplar\n"
	        "\n"
	        "Kullanilabilir formuller:\n"
	        " --adet [DEGER(LER)]\n"
	        "\tVerilen dizideki elamanlarin sayisini verir\n"
	        " --sirala [DEGER(LER)]\n"
	        "\tVerilen dizinin siralanmis halini verir\n"
	        " --aritmetik-ortalama [DEGER(LER)]\n"
	        "\tVerilen sayilarin aritmetik ortalamasini hesaplar\n"
	        " --harmonik-ortalama [DEGER(LER)]\n"
	        "\tVerilen sayilarin harmonik ortalamasini hesaplar\n"
	        " --geometrik-ortalama [DEGER(LER)]\n"
	        "\tVerilen sayilarin geometrik ortalamasini hesaplar\n"
	        " --medyan [DEGER(LER)]\n"
	        "\tVerilen sayilarin medyanini (ortanca) hesaplar\n"
	        " --mod [DEGER(LER)]\n"
	        "\tVerilen sayilarin modunu hesaplar\n"
	        " --ortalama-sapma [DEGER(LER)]\n"
	        "\tVerilen sayilarin ortalama sapmasini hesaplar\n"
	        " --standart-sapma [DEGER(LER)]\n"
	        "\tVerilen sayilarin standart sapmasini hesaplar\n"
	        " --varyans [DEGER(LER)]\n"
	        "\tVerilen sayilarin varyansini hesaplar\n"
	        " --degisim-katsayisi [DEGER(LER)]\n"
	        "\tVerilen sayilarin degisim katsayisini hesaplar\n"
	        " --permutasyon N R\n"
	        "\tN sayisinin R'li permutasyonunu hesaplar\n"
	        " --kombinasyon N R\n"
	        "\tN sayisinin R'li kombinasyonunu hesaplar\n"
	        " --frekans [DEGER(LER)]\n"
	        "\tVerilen sayilarin frekans dagilimini verir\n"
	        " --histogram [DEGER(LER)]\n"
	        "\tVerilen sayilarin histogram grafigini verir\n"
	        "\n"
	        "Ornekler:\n"
	        " Aritmetik ortalamayi argumanlar ile hesaplamak:\n"
	        "\t%s --aritmetik-ortalama [DEGER(LER)]\n"
	        " Standart sapmayi stdin'den deger okuyarak hesaplama:\n"
	        "\t%s --standart-sapma --interaktif\n"
	        " Histogram grafigini dosyadan veri okuyarak hesaplama:\n"
	        "\t%s --histogram --dosya [DOSYA]\n"
	        " Dizi ile hesaplanabilen butun formulleri hesaplamak icin:\n"
	        "\t%s --butun-formuller [DEGER(LER)]\n"
	        " Degerleri dosyadan alip, butun formulleri isimleri ile yazdirmak icin:\n"
	        "\t%s --butun-formuller --detay -d [DOSYA]\n"
	        " Kombinasyon hesaplamak icin:\n"
	        "\t%s --kombinasyon N R\n"
	        , argv, argv, argv, argv, argv, argv, argv, argv);
}
