#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "algoritmalar.h"

int cmpfunc (const void *a, const void *b)
{
	if ((*(double *)a) > (*(double *)b))
		return 1;
	else if (*(double *)a < *(double *)b)
		return -1;
	return 0;
}

double d_abs(double a)
{
	return (a >= 0)? a: -a;
}

double d_factorial(double n)
{
	double ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
	}
	return ans;
}

double d_max(double a, double b) {
	return (a > b)? a: b;
}

double d_min(double a, double b) {
	return (a < b)? a: b;
}

double d_max_arr(int size, double *arr)
{
	double ans = INT_MIN;
	for (int i = 0; i < size; i++) {
		ans = d_max(ans, arr[i]);
	}
	return ans;
}

double d_min_arr(int size, double *arr)
{
	double ans = INT_MAX;
	for (int i = 0; i < size; i++) {
		ans = d_min(ans, arr[i]);
	}
	return ans;
}

// stupid dictionary implementation
DICT *create_dict()
{
	DICT *tmp = (DICT *)malloc(sizeof(DICT));
	if (!tmp) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	for (int i = 0; i < HASH_RATE; i++) {
		tmp->head[i] = NULL;
	}
	tmp->size = 0;
	return tmp;
}

NODE *create_node(double key)
{
	NODE *tmp = (NODE *)malloc(sizeof(NODE));
	if (!tmp) {
		fprintf(stderr, "Bellek yetersiz!\n");
		exit(1);
	}
	tmp->key = key;
	tmp->cnt = 1;
	tmp->next = NULL;
	return tmp;
}

DICT *insert_dict(DICT *dict, double n)
{
	int i_key = (int)n % HASH_RATE;
	if (!dict->head[i_key]) {
		NODE *tmp = create_node(n);
		dict->head[i_key] = tmp;
		dict->size++;
		return dict;
	}
	NODE *tmp = dict->head[i_key];
	while (1) {
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

int val_dict(DICT *dict, double key)
{
	if (!dict) {
		return 0;
	}
	int i_key = (int)key % HASH_RATE;
	NODE *tmp = dict->head[i_key];
	while (tmp) {
		if (tmp->key == key) {
			return tmp->cnt;
		}
		tmp = tmp->next;
	}
	return 0;
}

int dict_size(DICT *dict)
{
	return dict->size;
}

double mx_key(DICT *dict)
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

void free_dict(DICT *dict)
{
	for (int i = 0; i < HASH_RATE; i++) {
		NODE *cur = dict->head[i];
		NODE *tmp = NULL;
		while (cur) {
			tmp = cur->next;
			free(cur);
			cur = tmp;
		}
		dict->head[i] = NULL;
	}
	free(dict);
	dict = NULL;
}
