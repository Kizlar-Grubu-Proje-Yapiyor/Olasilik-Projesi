// long double based sorting
static void ldsort(long double *arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				long double tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static long double max(long double a, long double b)
{
	return (a > b)? a: b;
}

static long double min(long double a, long double b)
{
	return (a < b)? a: b;
}
