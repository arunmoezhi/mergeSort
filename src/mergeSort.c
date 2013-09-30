#include"sortAlgorithms.h"

void merge(int p,int q,int r)
{
	int i,j=0,k=0,m=0;
	int leftArrSize  = q - p +1;
	int rightArrSize = r-q;
	int index,size;
	int *leftArr  = (int *) malloc((leftArrSize+1)  * sizeof(int));
	int *rightArr = (int *) malloc((rightArrSize+1) * sizeof(int));
	for(i=0;i<leftArrSize;i++)
	{
		leftArr[i] = unsortedArr[p+i];
	}
	for(i=0;i<rightArrSize;i++)
	{
		rightArr[i] = unsortedArr[q+1+i];
	}
	leftArr[leftArrSize]  = 1<<24;
	rightArr[rightArrSize]= 1<<24; 
	i=p;
	size=r-p+1;
	for(index=0;index<size;index++)
	{
		if(leftArr[j] <= rightArr[k])
		{
			unsortedArr[i++] = leftArr[j++];
		}
		else
		{
			unsortedArr[i++] = rightArr[k++];
		}
	}
	free(leftArr);
	free(rightArr);
	
}

void mergeSort(int p,int r)
{
	int q;
	//printf("mergeSort(%d,%d)\n",p,r);
	if(p<r)
	{
		q=(p+r)/2;
		mergeSort(p,q);
		mergeSort(q+1,r);
		merge(p,q,r);
	}
}

int main()
{
	getInput();
	#ifdef DEBUG_ON
	printArr();
	#endif
	start=clock();
	mergeSort(0,PROBLEM_SIZE-1);
	end=clock();
	#ifdef DEBUG_ON
	printArr();
	#endif
	printResults("MergeSort");
}
