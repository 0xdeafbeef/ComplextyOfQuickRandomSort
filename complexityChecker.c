#include "quickRandomSort.h"


//
// Created by root on 22.10.18.
//

int *createArray(int size)
{
	int i;
	int *arr = malloc(sizeof(int) * size);

	i = 0;
	while (i < size)
	{
		arr[i] = i;
		i++;
	}
	return arr;
}


void fisherYates(int *arr, int n)
{ //implementation of Fisher
	int i, j, tmp; // create local variables to hold values for shuffle

	for (i = n - 1; i > 0; i--)
	{ // for loop to shuffle
		j = PMrand() % (i + 1); //randomise j for shuffle with Fisher Yates
		tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}
}

int **createRshuffledArrays(int size, int count)
{
	int **shArr = malloc(sizeof(int) * count * size);
	int i = 0;

	while (i < count)
	{
		int *tmpArr;
		tmpArr = createArray(size);
		fisherYates(tmpArr, size);
		shArr[i] = tmpArr;
		i++;
	}
	return shArr;
}

void itterationsToSize(int size, int count, double *sum, double avg)
{
	int i = 0;
	int **ar;
	ar = createRshuffledArrays(size, count);
	while (i < count)
	{
		quickSortEnvoke(ar[i], 0, size - 1, sum);
		i++;
	}
	avg = (*sum / count)/size;
	printf("%f, ", avg);
	*sum = 0;
	free(*ar);
}

void calcComplexity()
{
	double *sum = malloc(sizeof(double));
	double avg;

	itterationsToSize(10, 100, sum, avg);
	itterationsToSize(100, 100, sum, avg);
	itterationsToSize(1000, 100, sum, avg);
	itterationsToSize(10000, 100, sum, avg);
	itterationsToSize(100000, 100, sum, avg);
	itterationsToSize(1000000, 100, sum, avg);
	//itterationsToSize(10000000, 10, sum, avg);
	//itterationsToSize(100000000, 1, sum, avg);


}

int main()
{
	printf( "Process started, please, wait\n");
	calcComplexity();
}