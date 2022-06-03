#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int size = 50000;
int A[size]; // масив для швидкого сортування
int B[size]; // масив для сортування методом вибору
int first, last;

void Create()
	{
	srand(1);
	for (int i=0; i<size; i++)
		{
		A[i] = B[i] = (int)rand();
		}
	}

void FastSort(int first, int last)
	{

	int mid, temp;
	int f=first, l=last;
	mid=A[(f+l) / 2];
	do
		{
		while (A[f]<mid) f++;
		while (A[l]>mid) l--;
		if (f<=l)
			{
			temp=A[f];
			A[f]=A[l];
			A[l]=temp;
			f++;
			l--;
			}
		}
	while (f<l);
	if (first<l) FastSort(first, l);
	if (f<last) FastSort(f, last);
	}
	
void Sort()
	{
		int j;
	for (int i = 1; i< (size-1); i++)
		{
		j = i;
		while (B[j]<B[j-1])
			{
			swap (B[j], B[j-1]);
			if (--j == 0)
				break;
			}
		}
	}

int main  ()
	{
	Create();
	first=0;
	last=size-1;

	clock_t  begt1, endt1;
	begt1 = clock();
	FastSort(first, last);
	endt1 = clock();
	printf ("Time fast sort = %d\n",endt1-begt1);

	clock_t  begt2, endt2;
	begt2 = clock();
	Sort();
	endt2 = clock();
	printf ("Time sort = %d\n",endt2-begt2);
	}

