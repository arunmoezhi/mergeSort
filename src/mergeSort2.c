#include"sortAlgorithms.h"
int auxArr[PROBLEM_SIZE];
	
void printAux()
{
	int i;
	for(i=0;i<PROBLEM_SIZE;i++)
	{
		printf("%d\t",auxArr[i]);
	}
	printf("\n");
}

void mergeA2B(int p,int q,int r)
{
	int i=p;
	int j=p;
	int k=q+1;
	int m;
	while(true)
	{
		if(unsortedArr[j] <= unsortedArr[k])
		{
			auxArr[i++] = unsortedArr[j++];
		}
		else
		{
			auxArr[i++] = unsortedArr[k++];
		}

		if(j>q)
		{
			for(m=k;m<=r;m++)
			{
				auxArr[i++] = unsortedArr[k++];
			}	
			break;
		}
		if(k>r)
		{
			for(m=j;m<=q;m++)
			{
				auxArr[i++] = unsortedArr[j++];
			}
			break;	
		}

	}
	
}

void mergeB2A(int p,int q,int r)
{
	int i=p;
	int j=p;
	int k=q+1;
	int m;
	while(true)
	{
		if(auxArr[j] <= auxArr[k])
		{
			unsortedArr[i++] = auxArr[j++];
		}
		else
		{
			unsortedArr[i++] = auxArr[k++];
		}

		if(j>q)
		{
			for(m=k;m<=r;m++)
			{
				unsortedArr[i++] = auxArr[k++];
			}	
			break;
		}
		if(k>r)
		{
			for(m=j;m<=q;m++)
			{
				unsortedArr[i++] = auxArr[j++];
			}
			break;	
		}

	}
	
}

void mergeSort(int p,int r,int d)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergeSort(p,q,d+1);
		mergeSort(q+1,r,d+1);
		if(d%2==1)
		{
			mergeA2B(p,q,r);
		}
		else
		{
			mergeB2A(p,q,r);
		}
	}
}

int main()
{
	int i;
	getInput();
	#ifdef DEBUG_ON
	printArr();
	#endif
	start=clock();
	if( (int) (log10(PROBLEM_SIZE)/log10(2) ) % 2 == 1 )
	{
		mergeSort(0,PROBLEM_SIZE-1,1);
		for(i=0;i<PROBLEM_SIZE;i++)
		{
			unsortedArr[i] = auxArr[i];
		}		
	}
	else
	{
		mergeSort(0,PROBLEM_SIZE-1,0);
	}
	end=clock();
	#ifdef DEBUG_ON
	printArr();
	#endif
	printResults("MergeSort");
}
