#include"sortAlgorithms.h"
int auxArr[PROBLEM_SIZE+2];
void printAux()
{
	int i;
	for(i=0;i<PROBLEM_SIZE;i++)
	{
		printf("%d\t",auxArr[i]);
	}
	printf("\n");
}

void merge(int p,int q,int r)
{
	int i,j=0,k=0,m=0;
	int leftArrEnd  = q+1;
	int rightArrEnd = r+2;
	int index,size;
	size=r-p+1;
	for(i=0;i<q-p+1;i++)
	{
		auxArr[p+i] = unsortedArr[p+i];
	}
	auxArr[leftArrEnd]  = 1<<24;
	for(i=0;i<r-q;i++)
	{
		auxArr[leftArrEnd+1+i] = unsortedArr[q+1+i];
	}
	auxArr[rightArrEnd]= 1<<24; 
	i=p;
	j=p;
	k=leftArrEnd+1;
	for(index=0;index<size;index++)
	{
		if(auxArr[j] <= auxArr[k])
		{
			unsortedArr[i++] = auxArr[j++];
		}
		else
		{
			unsortedArr[i++] = auxArr[k++];
		}
	}
	
}

void mergeSort(int p,int r)
{
	int q;
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
