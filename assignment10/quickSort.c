#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b) {
	if (a == b)
		return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int partition(int *arr, int l, int r) {
#ifdef MEDIAN_OF_THREE
	int mid = (l + r) >> 1;
	if ((arr[mid] - arr[l])*(arr[mid] - arr[r]) < 0) 
		swap(arr + l, arr + mid);
	else if ((arr[r] - arr[mid])*(arr[r] - arr[l]) < 0)
		swap(arr + l, arr + r);
#endif
	int pivot = arr[l];
	while (l < r) {
		while (l < r && arr[r] >= pivot) --r;
		if (l == r) break;
		arr[l++] = arr[r];
		while (l < r && arr[l] <= pivot) ++l;
		if (l == r) break;
		arr[r--] = arr[l];
	}
	arr[r] = pivot;
	return l;
}

void quickSort(int *arr, int l, int r) {
	int mid = partition(arr, l, r);
	int firL = l, firR = mid - 1, secL = mid + 1, secR = r;
#ifdef LONG
	// longer first
	if (firR - firL < secR - secL) {
		swap(&firL, &secL);
		swap(&firR, &secR);
	}
#elif defined SHORT
	// shorter first
	if (firR - firL > secR - secL) {
		swap(&firL, &secL);
		swap(&firR, &secR);
	}
#endif
	if (firR - firL > 1) quickSort(arr, firL, firR);
	if (secR - secL > 1) quickSort(arr, secL, secR);
}

int main() {

#ifdef DEBUG
	freopen("./testData.txt", "r", stdin);
#endif

	int n, *arr;
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	clock_t start, end;
	start = clock();
	quickSort(arr, 0, n - 1);
	end = clock();

	char output[1024] = "use ";

#ifdef MEDIAN_OF_THREE
	strcat(output, "median of three");
#else
	strcat(output, "leftmost");
#endif

	strcat(output, " and ");

#ifdef LONG
	strcat(output, "longer first");
#elif defined SHORT
	strcat(output, "shorter first");
#else
	strcat(output, "original");
#endif

	strcat(output, " execution time = %lf\n");

	printf(output, (double)(end - start)/CLOCKS_PER_SEC);

	free(arr);

	return 0;
}
