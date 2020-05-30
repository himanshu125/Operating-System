#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define frames 3
int queue[frames]={0,0,0};
int hit=0,miss=0;
int search(int num)
{

	for(int i=0;i<frames;i++)
	{
		if(queue[i]==num)
		return i;
	}

	return 99;
}
void display()
{
	for(int i=0;i<frames;i++)
	{
		printf("%d\t",queue[i] );
	}
	printf("\n");
}
int main()
{
	int arr[20];
	int i,j,k;
	for(i=0;i<20;i++)
	{
		arr[i]=rand();
		arr[i]%=20;
	}
	printf("Reference Tree:\n");
	for(i=0;i<20;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nStacks are:\n");
	k=0,i=0;
	while(k<20)
	{
		int ref=search(arr[k]);
		if(ref != 99)
		{
			hit++;
			printf("PH\n");
		}
		else
		{
			miss++;
			queue[i]=arr[k];
			i++;
			i=i%frames;
		}
		display();
		k++;
	}
	printf("\nHit= %d\nMiss=%d",hit,miss);
	return 0;
}
