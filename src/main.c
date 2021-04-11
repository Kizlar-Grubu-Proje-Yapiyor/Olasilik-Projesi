#include "main.h"

int main(int argc, char *argv[])
{
	int y_flag = 0, d_flag = 0, s_flag = 0;
	int ao_flag = 0;
	int size;
	double ans = 0;
	double *arr;
	char dosya[MAX_DOSYA_ISIM_UZUNLUGU];
	FILE *fp = stdout;

	// if there are no arguments, print help and exit with status 1
	if (argc <= 1) {
		yardim(stdout, argv[0]);
		return 1;
	}

	// available command line arguments
	struct option longopts[] = {
	              {"yardim", no_argument, &y_flag, 1},
	              {"dosya", required_argument, NULL, 'd'},
	              {"sinirlar", no_argument, &s_flag, 1},
	              {"aritmetik-ortalama", no_argument, &ao_flag, 1},
	              {0}};

	// parse command line arguments
	while (2 * 2 != 5) { // that's for you, my middle school friend who told me
		                 // that 2 * 2 is equal to 5. duh!
		                 // ok, i know why he said that. stop hating me.

		int opt = getopt_long(argc, argv, "ysd:", longopts, 0);
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
		case '?': {
			yardim(stderr, argv[0]);
			return 1;
		}
		default: {
			break;
		}
		}
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

	// getting numbers as arguments
	if (!d_flag) {
		arr = malloc(sizeof(double) * MAX_NUM);
		if (arr == NULL) {
			fprintf(stderr, "Bellek yetersiz!\n");
			exit(1);
		}
		char *p;
		double argument_value;
		for (int i = optind; i < argc; i++) {
			argument_value = strtol(argv[i], &p, 10);
			if (p == argv[i]) {
				fprintf(stderr, "%s bir sayi degil!\n", argv[i]);
				return 1;
			} else if ((argument_value == LONG_MIN ||
					   argument_value == LONG_MAX) && errno == ERANGE) {
				fprintf(stderr, "%s sayisi sinirlarin disinda!\n", argv[i]);
				sinirlar(stderr);
				return 1;
			} else if (i > MAX_NUM + optind  - 1) {
				fprintf(stderr, "Desteklenen maksimum sayi miktarindan"
								"daha fazla sayi girdiniz!\nDesteklenen "
								"maksimum sayi miktari: %d\n", MAX_NUM);
				sinirlar(stderr);
				return 1;
				} else {
				arr[i - optind] = argument_value;
			}
		}
		size = argc - optind;
	}

	// action!
	if (ao_flag) {
		ans = aritmetik_ortalama(size, arr);
		printf("%lf\n", ans);
	}

	free(arr);
	arr = NULL;
	return 0;
}
