#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *multiply(int mat1[][N],int mat2[][N],int mat3[][N]) 
{ 
    	int i, j, k; 
    	for (i=0; i < N; i++) 
    	{ 
        for (j = 0; j < N; j++) 
        { 
            	mat3[i][j] = 0; 
            	for (k = 0; k < N; k++) 
                mat3[i][j]+= mat1[i][k]*mat2[k][j]; 
        } 
    	} 
	pthread_exit(0);
} 
int main()
{
	int n;
	printf("enter the number:-");
	for(i=0;)
	scanf("%d",&n);
	pthread_t tid;
	pthread_attr_t attr; 
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,multiply,(void *)&n);
	pthread_join(tid1,NULL);
}
