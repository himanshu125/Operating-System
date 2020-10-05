#include<stdio.h>
#include<stdlib.h>

int arri[3][3][1000000];
int arrc[3][3][1000000];
int arrf[3][3];
int i,j,count=0,l=0,k=0,temp,m=0,ctr=0,u=0,v=0,t,flag=0,lvl=0,a[100000],str=0,g=0;

int expand()
{
	for(i=0; i<3; i++)
	{
		for(j=0; j<3;j++)
		{
			if(arri[i][j][m]==0)
			{
				if(i+1<3 && arri[i+1][j][lvl]!=0)
				{   
				    flag++;
					temp=arri[i+1][j][m];
					k++;
					for(u=0; u<3; u++)
					{
						for(v=0; v<3; v++)
						{
							arri[u][v][k]=arri[u][v][m];
						}
					}
					arri[i+1][j][k]=0;
					arri[i][j][k]=temp;
				}
				if(j+1<3 && arri[i][j+1][lvl]!=0)
				{
				    flag++;
					temp=arri[i][j+1][m];
					k++;
					for(u=0; u<3; u++)
					{
						for(v=0; v<3; v++)
						{
							arri[u][v][k]=arri[u][v][m];
						}
					}
					arri[i][j+1][k]=0;
					arri[i][j][k]=temp;
				}
				if(i-1>=0 && arri[i-1][j][lvl]!=0)
				{
				    flag++;
					temp=arri[i-1][j][m];
					k++;
					for(u=0; u<3; u++)
					{
						for(v=0; v<3; v++)
						{
							arri[u][v][k]=arri[u][v][m];
						}
					}
					arri[i-1][j][k]=0;
					arri[i][j][k]=temp;
				}
				if(j-1>=0 && arri[i][j-1][lvl]!=0)
				{
				    flag++;
					temp=arri[i][j-1][m];
					k++;
					for(u=0; u<3; u++)
					{
						for(v=0; v<3; v++)
						{
							arri[u][v][k]=arri[u][v][m];
						}
					}
					arri[i][j-1][k]=0;
					arri[i][j][k]=temp;
				}
			}
		}
	}
	m++;
}

int check()
{
	for(i=0; i<3; i++)
	{
		for(j=0; j<3;j++)
		{
			if(arri[i][j][m]==arrf[i][j])
			{
				count++;
				ctr=m;
			}
		}
	}
	if(count==9)
	{
		for(t=0; t<=ctr; t++)
		{
			if(t==ctr)
			{	
				printf("\n no. of steps : %d \n\n",t);
				printf(" Goal achieved\n\n");
				for(i=0; i<3; i++)
				{			
					for(j=0; j<3;j++)
					{
						printf(" %d ",arri[i][j][ctr]);
					}
					printf("\n");
				}
				exit(0);
			}
			else
			{
				printf(" no. of steps : %d \n\n",t);
				for(i=0; i<3; i++)
				{
					for(j=0; j<3;j++)
					{
						printf(" %d ",arri[i][j][t]);
					}
					printf("\n");
				}
				printf("\n\n");
			}
		}
	}
	else
	{
		count=0;
		expand();
	}
}

int main()
{
	printf("Enter the number in intial state \n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3;j++)
		{
			scanf("%d",&arri[i][j][k]);
		}
	}
	printf("Enter the number in final state \n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3;j++)
		{
			scanf("%d",&arrf[i][j]);
		}
	}
	check();
	while(1)
	{
	   a[str]=flag;
	   str++;
	   if(l<a[g])
	   {
	    l++;
	    flag=0;
	    check();
       }
       else
       {
	        g++;
	        flag=0;
	        l=0;
	        lvl++;
	        check();
       }
	}
}