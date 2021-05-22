int cmpfunc (const void *a, const void *b);
double d_abs(double a);
double d_factorial(double n);

#ifndef HASH_RATE
# define HASH_RATE 1000
#endif

typedef struct NODE {
	double key;
	int cnt;
	struct NODE *next;
} NODE;

typedef struct DICT {
	struct NODE *head[HASH_RATE];
	int size;
} DICT;

DICT *create_dict();
NODE *create_node(double key);
DICT *insert_dict(DICT *dict, double n);
int val_dict(DICT *dict, double key);
int dict_size(DICT *dict);
double mx_key(DICT *dict);
void free_dict(DICT *dict);
