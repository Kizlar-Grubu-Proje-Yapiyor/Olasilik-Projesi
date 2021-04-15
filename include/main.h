#ifndef MAX_NUM
# define MAX_NUM 100000
#endif

#ifndef MAX_DOSYA_ISIM_UZUNLUGU
# define MAX_DOSYA_ISIM_UZUNLUGU 256
#endif

#ifdef _WIN32
# define double_t double
#endif

#ifdef __APPLE__
# define double_t double
#endif

#ifdef __linux__
# define double_t long double
#endif
