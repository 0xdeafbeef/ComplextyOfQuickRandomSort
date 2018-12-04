
/* C++ implementation QuickSort using Lomuto's partition
   Scheme.*/
#include "quickRandomSort.h"

static long int seed = 1;
int g_count = 0;

/* this function swaps two elements */
void swap(int *first, int *second)
{
	int t;

	t = *second;
	*second = *first;
	*first = t;
	g_count++;
}

long int PMrand()
{
	long int hi = seed / q;
	long int lo = seed % q;
	long int test = a * lo - r * hi;
	if (test > 0)
		seed = test;
	else seed = test + m;
	return seed;
}

/* This function takes last element as pivot, places
  the pivot element at its correct position in sorted
  array, and places all smaller (smaller than pivot)
  to left of pivot and all greater elements to right
  of pivot */
int partition(int arr[], int low, int high)
{

	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{

			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
	// Generate first random number in between
	// low .. high
	rand();
	int random = low + PMrand() % (high - low);

	// Swap A[random] with A[high]
	swap(&arr[random], &arr[high]);

	return partition(arr, low, high);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition_r(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void quickSortEnvoke(int arr[], int low, int high, double *sum)
{
	quickSort(arr, low, high);
	*sum += g_count;
}


/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

