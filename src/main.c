#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "main.h"
#include "yardim.h"
#include "sinirlar.h"
#include "interaktif.h"
#include "dosya.h"
#include "aritmetikortalama.h"
#include "medyan.h"
#include "mod.h"
#include "harmonikortalama.h"
#include "ortalamasapma.h"
#include "geometrikortalama.h"
#include "varyans.h"
#include "standartsapma.h"
#include "degisimkatsayisi.h"
#include "permutasyon.h"
#include "kombinasyon.h"
#include "frekans.h"
#include "algoritmalar.h"
#include "histogram.h"

int main(int argc, char *argv[])
{
	int y_flag = 0, d_flag = 0, s_flag = 0, i_flag = 0;
	int ao_flag = 0, m_flag = 0, mod_flag = 0, ho_flag = 0;
	int osap_flag = 0, go_flag = 0, v_flag = 0, ss_flag = 0;
	int dty_flag = 0, btn_flag = 0, dk_flag = 0;
	int p_flag = 0, k_flag = 0, f_flag = 0, h_flag = 0;
	int adet_flag = 0, sirala_flag = 0;
	int size = 0;
	double ans = 0;
	double *arr;
	char dosya[MAX_DOSYA_ISIM_UZUNLUGU];
	FILE *fp = stdout;

	// if there are no arguments, print help and exit with status 1
	if (argc <= 1) {
		fprintf(stderr, "Arguman girilmedi!\n\n");
		yardim(stderr, argv[0]);
		return 1;
	}

	// available command line arguments
	struct option longopts[] = {
	              {"yardim", no_argument, &y_flag, 1},
	              {"dosya", required_argument, NULL, 'd'},
	              {"sinirlar", no_argument, &s_flag, 1},
	              {"interaktif", no_argument, &i_flag, 1},
	              {"detay", no_argument, &dty_flag, 1},
	              {"butun-formuller", no_argument, &btn_flag, 1},
	              {"frekans", no_argument, &f_flag, 1},
	              {"aritmetik-ortalama", no_argument, &ao_flag, 1},
	              {"medyan", no_argument, &m_flag, 1},
	              {"mod", no_argument, &mod_flag, 1},
	              {"harmonik-ortalama", no_argument, &ho_flag, 1},
	              {"ortalama-sapma", no_argument, &osap_flag, 1},
	              {"geometrik-ortalama", no_argument, &go_flag, 1},
	              {"varyans", no_argument, &v_flag, 1},
	              {"standart-sapma", no_argument, &ss_flag, 1},
	              {"degisim-katsayisi", no_argument, &dk_flag, 1},
	              {"permutasyon", no_argument, &p_flag, 1},
	              {"kombinasyon", no_argument, &k_flag, 1},
	              {"adet", no_argument, &adet_flag, 1},
	              {"sirala", no_argument, &sirala_flag, 1},
	              {"histogram", no_argument, &h_flag, 1},
	              {0}
	              };

	// parse command line arguments
	while (2 * 2 != 5) {
		int opt = getopt_long(argc, argv, "ysd:i", longopts, 0);
		if (opt == -1) {
			break;
		}

		switch (opt) {
			case 'y': {
				y_flag = 1;
				break;
			}
			case 's': {
				s_flag = 1;
				break;
			}
			case 'd': {
				d_flag = 1;
				strncpy(dosya, optarg, sizeof(dosya));
				dosya[sizeof(dosya) - 1] = '\0';
				break;
			}
			case 'i': {
				i_flag = 1;
				break;
			}
			case '?': {
				yardim(stderr, argv[0]);
				return 1;
			}
			default: {
				break;
			}
		}
	}


	// display help and exit
	if (y_flag) {
		yardim(stdout, argv[0]);
		return 0;
	}

	// display limits and exit
	if (s_flag) {
		sinirlar(stdout);
		return 0;
	}


	// take numbers from stdin
	if (i_flag) {
		arr = interaktif(&size);
	}

	// take numbers from the specified file
	if (d_flag) {
		fp = fopen(dosya, "r");
		if (fp == NULL) {
			fprintf(stderr, "Dosya acilmaya calisirken bir sorun olustu!\n");
			return 1;
		}
		arr = dosyadan_oku(&size, fp);
		fclose(fp);
	}

	// take numbers as arguments
	if (!d_flag && !i_flag) {
		arr = malloc(sizeof(double) * MAX_NUM);
		if (arr == NULL) {
			fprintf(stderr, "Bellek yetersiz!\n");
			exit(1);
		}
		char *p;
		double argument_value;
		for (int i = optind; i < argc; i++) {
			argument_value = (double)strtod(argv[i], &p);
			if (p == argv[i]) {
				fprintf(stderr, "%s bir sayi degil!\n", argv[i]);
				return 1;
			} else if ((argument_value == INT_MIN ||
			            argument_value == INT_MAX) && errno == ERANGE) {
				fprintf(stderr, "%s sayisi sinirlarin disinda!\n", argv[i]);
				sinirlar(stderr);
				return 1;
			} else if (i > MAX_NUM + optind  - 1) {
				fprintf(stderr, "Desteklenen maksimum sayi miktarindan "
				                "daha fazla sayi girdiniz!\nDesteklenen "
				                "maksimum sayi miktari: %d\n\n", MAX_NUM);
				sinirlar(stderr);
				return 1;
			} else {
				arr[i - optind] = argument_value;
			}
		}
		size = argc - optind;
	}


	// action!
	if (adet_flag || btn_flag) {
		if (dty_flag) {
			printf("Eleman sayisi: ");
		}
		printf("%d\n", size);
	}
	if (sirala_flag) {
		if (dty_flag) {
			printf("Siralanmis liste: ");
		}
		qsort(arr, size, sizeof(double), cmpfunc);
		for (int i = 0; i < size; i++)
			printf("%d ", (int)arr[i]);
		printf("\n");
	}
	if (ao_flag || btn_flag) {
		if (dty_flag) {
			printf("Aritmetik ortalama: ");
		}
		ans = aritmetik_ortalama(size, arr);
		printf("%lf\n", ans);
	}
	if (ho_flag || btn_flag) {
		if (dty_flag) {
			printf("Harmonik ortalama: ");
		}
		ans = harmonik_ortalama(size, arr);
		printf("%lf\n", ans);
	}
	if (go_flag || btn_flag) {
		if (dty_flag) {
			printf("Geometrik ortalama: ");
		}
		ans = geometrik_ortalama(size, arr);
		printf("%lf\n", ans);
	}
	if (m_flag || btn_flag) {
		if (dty_flag) {
			printf("Medyan: ");
		}
		ans = medyan(size, arr);
		printf("%lf\n", ans);
	}
	if (mod_flag || btn_flag) {
		if (dty_flag) {
			printf("Mod: ");
		}
		ans = mod(size, arr);
		printf("%lf\n", ans);
	}
	if (osap_flag || btn_flag) {
		if (dty_flag) {
			printf("Ortalama sapma: ");
		}
		ans = ortalama_sapma(size, arr);
		printf("%lf\n", ans);
	}
	if (ss_flag || btn_flag) {
		if (dty_flag) {
			printf("Standart sapma: ");
		}
		ans = standart_sapma(size, arr);
		printf("%lf\n", ans);
	}
	if (v_flag || btn_flag) {
		if (dty_flag) {
			printf("Varyans: ");
		}
		ans = varyans(size, arr);
		printf("%lf\n", ans);
	}
	if (dk_flag || btn_flag) {
		if (dty_flag) {
			printf("Degisim katsayisi: ");
		}
		ans = degisim_katsayisi(size, arr);
		printf("%lf\n", ans);
	}
	if (p_flag) {
		if (dty_flag) {
			printf("Permutasyon: ");
		}
		ans = permutasyon(arr[0], arr[1]);
		printf("%lf\n", ans);
	}
	if (k_flag) {
		if (dty_flag) {
			printf("Kombinasyon: ");
		}
		ans = kombinasyon(arr[0], arr[1]);
		printf("%lf\n", ans);
	}
	if (f_flag) {
		if (dty_flag) {
			printf("Siniflar\tFrekans\t\n");
		}
		frekans(size, arr);
	}
	if (h_flag) {
		if (dty_flag) {
			printf("Siniflar\tFrekans\t\n");
		}
		histogram(size, arr);
	}


	free(arr);
	arr = NULL;
	return 0;
}
