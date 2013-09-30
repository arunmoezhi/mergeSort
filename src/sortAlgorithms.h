#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>

#define PROBLEM_SIZE (int) pow(2,23)
//#define DEBUG_ON

clock_t start,end;
int unsortedArr[PROBLEM_SIZE];
void getInput();
void printArr();
void printResults(char *); 
