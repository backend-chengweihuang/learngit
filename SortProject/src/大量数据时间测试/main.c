#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.h"

void randNum( int* a, int count);
void timeTest(int *a,int size);

int main()
{

    int a1[10000],a2[50000],a3[200000];
    puts("10000�������Ĳ������£�");
    timeTest(a1,10000);
    puts("");
    puts("50000�������Ĳ������£�");
    timeTest(a2,50000);
    puts("");
    puts("200000�������Ĳ������£�");
    timeTest(a3,200000);
    puts("��������˳�������");
    getchar();
}


void randNum( int* a, int count )
{

    int i = 0;

    while( i < count )
    {

        a[i++] = rand() % (count+1);

    }

}

void timeTest(int *a,int size)
{
    int t[200000];
    clock_t start, finish;

    randNum(a,size);
	start = clock();
	insertSort(a,size);
	finish = clock();
	printf("����������ʱ%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	MergeSort(a,0,size-1,t);
	finish = clock();
	printf("�鲢������ʱ%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	QuickSort_Recursion(a, 0,size-1);
	finish = clock();
	printf("��������(�ݹ��)��ʱ%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	QuickSort(a,size);
	finish = clock();
	printf("��������(�ǵݹ��)��ʱ%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	Partition(a, 0, size-1);
	finish = clock();
	printf("��������(������)��ʱ%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	RadixCountSort(a,size);
	finish = clock();
	printf("����������ʱ%ld ms\n",finish-start);
}









































