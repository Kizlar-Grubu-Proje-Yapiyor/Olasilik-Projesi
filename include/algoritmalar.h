#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static int cmpfunc (const void * a, const void * b)
{
	if ((*(double *)a) > (*(double *)b))
		return 1;
	else if (*(double *)a < *(double *)b)
		return -1;
	return 0;
}

static double d_abs(double a)
{
	return (a >= 0)? a: -a;
}

static double d_root(double base, double power)
{
	return pow(base, (double)1 / power);
}


// stupid dictionary implementation
#ifndef HASH_RATE
# define HASH_RATE 1000
#endif

typedef struct NODE NODE;
typedef struct DICT DICT;

static DICT *create_dict();
static NODE *create_node(double key);
static DICT *insert_dict(DICT *dict, double n);
static int val_dict(DICT *dict, double key);
static int dict_size(DICT *dict);
static double mx_key(DICT *dict);
static void free_dict(DICT *dict);

struct NODE {
	double key;
	int cnt;
	NODE *next;
};

struct DICT {
	NODE *head[HASH_RATE];
	int size;
};

static DICT *create_dict()
{
	DICT *tmp = (DICT *)malloc(sizeof(DICT *));
	if (!tmp) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	for (int i = 0; i < HASH_RATE; i++) {
		tmp->head[i] = malloc(sizeof(NODE *));
		if (!tmp->head[i]) {
			fprintf(stderr, "Bellek yetersiz!\n");
			exit(1);
		}
		tmp->head[i] = NULL;
	}
	tmp->size = 0;
	return tmp;
}

static NODE *create_node(double key)
{
	NODE *tmp = (NODE *)malloc(sizeof(NODE *));
	if (!tmp) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	tmp->key = key;
	tmp->cnt = 1;
	tmp->next = NULL;
	return tmp;
}

static DICT *insert_dict(DICT *dict, double n)
{
	int i_key = (int)n / HASH_RATE;
	if (!dict->head[i_key]) {
		NODE *tmp = create_node(n);
		dict->head[i_key] = tmp;
		dict->size++;
		return dict;
	}
	NODE *tmp = dict->head[i_key];
	while (tmp) {
		if (tmp->key == n) {
			tmp->cnt++;
			return dict;
		}
		if (tmp->next) {
			tmp = tmp->next;
		} else {
			break;
		}
	}
	tmp->next = create_node(n);
	dict->size++;
	return dict;
}

static int val_dict(DICT *dict, double key)
{
	if (!dict) {
		return 0;
	}
	int i_key = (int)key / HASH_RATE;
	NODE *tmp = dict->head[i_key];
	while (tmp) {
		if (tmp->key == key) {
			return tmp->cnt;
		}
		tmp = tmp->next;
	}
	return 0;
}

static int dict_size(DICT *dict)
{
	return dict->size;
}

static double mx_key(DICT *dict)
{
	double ans = 0;
	int mx = -1;
	NODE *tmp;
	for (int i = 0; i < HASH_RATE; i++) {
		tmp = dict->head[i];
		while (tmp) {
			if (mx < tmp->cnt) {
				ans = tmp->key;
				mx = tmp->cnt;
			}
			tmp = tmp->next;
		}
	}
	return ans;
}
// it's broken. any help will be great.
static void free_dict(DICT *dict)
{
	NODE *cur;
	for (int i = 0; i < HASH_RATE; i++) {
		cur = dict->head[i];
		while (cur) {
			NODE *tmp = cur->next;
			free(cur);
			cur = tmp;
		}
	}
	free(dict);
	dict = NULL;
}
