#include <math.h>
#include <stdlib.h>

static int cmpfunc (const void * a, const void * b)
{
	return *(double *)a - *(double *)b;
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
	NODE *head;
	int size;
};

static DICT *create_dict()
{
	DICT *tmp = (DICT *)malloc(sizeof(DICT *));
	tmp->head = NULL;
	tmp->size = 0;
	return tmp;
}

static NODE *create_node(double key)
{
	NODE *tmp = (NODE *)malloc(sizeof(NODE *));
	tmp->key = key;
	tmp->cnt = 1;
	tmp->next = NULL;
	return tmp;
}

static DICT *insert_dict(DICT *dict, double n)
{
	if (!dict->head) {
		NODE *tmp = create_node(n);
		dict->head = tmp;
		dict->size = 1;
		return dict;
	}
	NODE *tmp = dict->head;
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
	NODE *tmp = dict->head;
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
	double ans;
	int mx = -1;
	if (!dict->head) {
		return 0;
	}
	NODE *tmp = dict->head;
	while (tmp) {
		if (mx < tmp->cnt) {
			ans = tmp->key;
			mx = tmp->cnt;
		}
		tmp = tmp->next;
	}
	return ans;
}

static void free_dict(DICT *dict)
{
	NODE *cur = dict->head;
	while (cur->next) {
		NODE *tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(dict);
}
