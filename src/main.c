#include "main.h"

int main(int argc, char *argv[])
{
	FILE *fp = stdout;
	int opt = 0;
	char file_name[256];

	struct option longopts[] = {
	              {"yardim", no_argument, NULL, 'y'},
	              {"dosya", optional_argument, NULL, 'd'},
	              {"mesaj", required_argument, NULL, 'm'},
	              {0}};

	while (opt != -1) {
		opt = getopt_long(argc, argv, "yd::m:", longopts, 0);
		switch (opt) {
		case 'y':
			yardim(fp, argv[0]);
			break;
		case 'd':
			strncpy(file_name, optarg ? optarg : "out.txt", sizeof(file_name));
			file_name[sizeof(file_name) - 1] = '\0';
			break;
		case 'm':
			printf("m, %s\n", optarg);
			break;
		case '?':
			yardim(stderr, argv[0]);
			return 1;
		default:
			break;
		}
	}
	return 0;
}
