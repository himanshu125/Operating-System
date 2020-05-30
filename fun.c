#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
long int fact;
void *factorial(void *param)
{
	int i, abc = atoi(param);
	fact=1;
	for (i = 1; i<=abc; i++)
	{
	fact=fact*i;
	}
	pthread_exit(0);
}
void *fibonacci(void *param)
{
        int abc= atoi(param);
        int arr[abc];
        for(int i=0;i<abc;i++)
        {
                if(i==0)
                        arr[i]=0;
                else if(i==1)
                        arr[i]=1;
                else arr[i]=arr[i-1]+arr[i-2];
        }
        printf("\nNth Fibonacci Series is:");
        for(int i=0;i<abc;i++)
                printf("%d  ",arr[i]);
        printf("\n");

}
void *palindrome(void *param)
{
	int a=atoi(param);
	int temp=a,remainder,reverse=0;
   	while(temp != 0)
   	{
       	remainder = temp % 10;
       	reverse = reverse * 10 + remainder;
       	temp = temp / 10;
   	}
	if (a == reverse)
      	printf("\n%d is a palindrome.", a);
   	else
      	printf("\n%d is not a palindrome.", a);
}
int main(int argc, char *argv[])
{
	pthread_t tid1,tid2,tid3;
	pthread_attr_t attr1,attr2,attr3; 
	if (argc != 2) {
	printf("please provide a value!!!!");
	return -1;
	}
	pthread_attr_init(&attr1);
	pthread_create(&tid1,&attr1,factorial,argv[1]);
	pthread_join(tid1,NULL);
	printf("\nfactorial = %ld \n",fact);
	pthread_attr_init(&attr2);
	pthread_create(&tid2,&attr2,fibonacci,argv[1]);
	pthread_join(tid2,NULL);
	pthread_attr_init(&attr3);
	pthread_create(&tid3,&attr3,palindrome,argv[1]);
	pthread_join(tid3,NULL);
}
