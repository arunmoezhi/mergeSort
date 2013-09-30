#include"sortAlgorithms.h"

void getInput()
{
	int i=0;
	char fname[30];
	sprintf(fname,"../input/input%d.txt",PROBLEM_SIZE);
	FILE *fr= fopen(fname,"r");
	while(!feof(fr))
	{
		fscanf(fr,"%d",(unsortedArr+i));
		i++;
	}
	fclose(fr);
}

void printResults(char *algorithm)
{
	printf("Algorithm		:%s\n",algorithm);
	printf("Problem Size		:%d\n",PROBLEM_SIZE);
	printf("Runtime			:%lf\n",(double) (end-start)/CLOCKS_PER_SEC);
}

void printArr()
{
	int i;
	for(i=0;i<PROBLEM_SIZE;i++)
	{
		printf("%d\t",unsortedArr[i]);
	}
	printf("\n");
}
