#include<stdio.h>
#define n 5
#define m 3
int fin=0;
int allocation[n][m]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int max[n][m]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int available[m]={3,3,2};
int work[m]={3,3,2};
int finish[n]={0,0,0,0,0};
int need[n][m];
int request[m];
int rq;
void calcneed()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			need[i][j]=max[i][j] - allocation[i][j];
		}
	}
}
void updatework(int i)
{
	for(int j=0;j<m;j++)
	{
		work[j]=work[j] + allocation[i][j];		
	}
	finish[i]=1;
	fin++;

}
int check()
{
	calcneed();
	int i,j,ctr=0,flag=0;
	while(fin<5)
	{
	
	for(i=0;i<n;i++)
	{
		ctr=0;
		if(finish[i]==0)
		{
			for(j=0;j<m;j++)
			{
				if(need[i][j] > work[j])
					ctr++;
			}
			if(ctr==0)
				updatework(i);
		}
	}
	flag++;
	if(flag>5) break;
	}
	if(fin!=5) {printf("SYSTEM is NOT SAFE !\n"); return 0;}
	else	{printf("SYSTEM IS SAFE !\n"); return 1;}
}
//Safety finished
//resource request
void update(int i)
{
	for(int j=0;j<m;j++)
	{
		available[j]-=request[j];
		allocation[i][j]+=request[j];
		need[i][j]-=request[j];
	}
}
int rsrq()
{
	int j,ctr=0;
	for(j=0;j<m;j++)
	{
		if(request[j]>need[rq][j]) ctr++;
	}
	if(ctr!=0) {printf("\nProcess request exceeds its max demand!\n");	return 0;}
	ctr=0;
	for(j=0;j<m;j++)
	{
		if(request[j]>available[j]) ctr++;
	}
	if(ctr!=0) {printf("\nProcess must wait as resources are not available !\n");	return 0;}
	update(rq);
	int ch1=check();
}
int main() 
{
	//initialize();
	int i,j,ch;
	top:
	ch=check();
	if(ch=0) return 0;	
	printf("Enter Requested process:");scanf("%d",&rq);
	printf("Enter the request:");
	for(j=0;j<m;j++)
	{
		scanf("%d",&request[j]);
	}
	rsrq();
	printf("\nReq more: 1/0\n");
	int ans;	
	scanf("%d",&ans);
	if(ans==1) goto top;	
	return 0;
}
