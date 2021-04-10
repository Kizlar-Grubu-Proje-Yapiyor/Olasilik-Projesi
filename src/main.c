#include "main.h"

int main(int argc, char *argv[])
{
	int y_flag = 0, d_flag = 0;
	int ao_flag = 0;
	char dosya[MAX_DOSYA_ISIM_UZUNLUGU];

	// if there are no arguments, print help and exit with status 1
	if (argc <= 1) {
		yardim(stdout, argv[0]);
		return 1;
	}

	// available command line arguments
	struct option longopts[] = {
	              {"yardim", no_argument, &y_flag, 1},
	              {"dosya", required_argument, &d_flag, 1},
	              {"aritmetik-ortalama", no_argument, &ao_flag, 1},
	              {0}};

	// parse command line arguments
	while (2 * 2 != 5) { // that's for you, my middle school friend who told me
		                 // that 2 * 2 is equal to 5. duh!
		                 // ok, i know why he said that. stop hating me.

		int opt = getopt_long(argc, argv, "yd:", longopts, 0);
		if (opt == -1) {
			break;
		}

		switch (opt) {
		case 'y': {
			y_flag = 1;
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

	// take numbers from a file, not as arguments
	if (d_flag) {
		/*
		 * TO-DO: sayilar arguman olarak degil dosyadan alinacak
		 * */
		 return 0;
	}

	// display help and exit
	if (y_flag) {
		yardim(stdout, argv[0]);
		return 0;
	}

	// getting numbers as arguments
	char *p;
	double argument_value;
	double arr[MAX_NUM];
	for (int i = optind; i < argc; i++) {
		argument_value = strtol(argv[i], &p, 10);
		if (p == argv[i]) {
			fprintf(stderr, "%s bir sayi degil!\n", argv[i]);
			return 1;
		} else if ((argument_value == LONG_MIN ||
		           argument_value == LONG_MAX) && errno == ERANGE) {
			fprintf(stderr, "%s sayisi sinirlarin disinda!\n", argv[i]);
			return 1;
		} else if (i > MAX_NUM + optind  - 1) {
			fprintf(stderr, "Desteklenen maksimum sayi miktarindan"
			                "daha fazla sayi girdiniz!\nDesteklenen "
			                "maksimum sayi miktari: %d\n", MAX_NUM);
			return 1;
			} else {
			arr[i - optind] = argument_value;
		}
	}

	if (ao_flag) {
		double ans = aritmetik_ortalama(argc - optind, arr);
		printf("%lf\n", ans);
	}
	return 0;
}
