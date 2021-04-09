#include "main.h"

int main(int argc, char *argv[])
{
	FILE *fp = stdout;
	int opt = 0;
	char file_name[256];
	int counter = 0;

	struct option longopts[] = {
	              {"yardim", no_argument, NULL, 'y'},
	              {"dosya", required_argument, NULL, 'd'},
	              {"aritmetik-ortalama", required_argument, NULL, 'a'},
	              {"mesaj", required_argument, NULL, 'm'},
	              {0}};

	if (argc <= 1) {
		yardim(fp, argv[0]);
	}

	while (opt != -1) {
		counter++;
		opt = getopt_long(argc, argv, "yd:a:m:", longopts, 0);

		switch (opt) {
		case 'y': {
			yardim(fp, argv[0]);
			return 0;
		}
		case 'd': {
			strncpy(file_name, optarg ? optarg : "out.txt", sizeof(file_name));
			file_name[sizeof(file_name) - 1] = '\0';
			break;
		}
		case 'a': {
			/*
			 * TO-DO: Burası bircok case'de gecerli oldugu icin hepsinde
			 * calisacak sekilde ayarlanmali.
			 * */
			errno = 0;
			char *p;
			long argument_value;
			double arr[MAX_NUM];
			for (int i = counter + 1; i < argc; i++) {
				argument_value = strtol(argv[i], &p, 10);
				if (p == argv[i]) {
					fprintf(stderr, "%s bir sayi degil!\n", argv[i]);
					return 1;
				} else if ((argument_value == LONG_MIN ||
				           argument_value == LONG_MAX) && errno == ERANGE) {
					fprintf(stderr, "%s sayisi cok buyuk!\n", argv[i]);
					return 1;
				} else if (i >= MAX_NUM + counter + 1) {
					fprintf(stderr, "Desteklenen maksimum sayi miktarindan"
					                "daha fazla sayi girdiniz!\nDesteklenen "
					                "maksimum sayi miktari: %d\n", MAX_NUM);
					return 1;
				} else {
					arr[i - counter - 1] = argument_value;
				}
			}
			fprintf(fp, "%lf\n", aritmetik_ortalama(argc - counter - 1, arr));
			return 0;
		}
		case 'm': {
			printf("m, %s\n", optarg);
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
	return 0;
}
