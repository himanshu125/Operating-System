#include<stdio.h>
#include<stdlib.h>
int i,j,n,cpu=0,start=-1,end=-1,k,l=0,tq;
float atat=0,awt=0;
int time=0;
struct data {
	int at,rt,bt,ct,tat,wt,p;
		int p_no;
	//	float ntat;
}temp1,rq[35];
int main()
{
	printf("enter the no of process: ");
	scanf("%d",&n);
	struct data aa[n];
	i=0;
	while(i<n)
	{
		printf("enter the name of process %d,at,bt\n",i+1);
				scanf("%d",&aa[i].p_no);
		scanf("%d",&aa[i].at); scanf("%d",&aa[i].bt);
		aa[i].p=0;
		aa[i].rt = aa[i].bt;
		i++;
	}
	printf("enter time quantum:");
	scanf("%d",&tq);
//	int tq=2;
//	printf("1");
//sorting
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(aa[j].at > aa[j+1].at)
			{
				temp1=aa[j];
				aa[j]=aa[j+1];
				aa[j+1]=temp1;
			}
		}
	}
	//	printf("%d",aa[0].p_no);
		cpu=aa[0].at;
		rq[0]=aa[0];
		rq[0].p=1;
		start++;
		end++;
//		int z=0;
	while(l!=n)
	{
		time=0;
		for(i=0;i<tq;i++)
		{	
			rq[start].rt--;
			cpu++;
		 		for(k=1;k<n;k++)
			                                         
				{
					if(aa[k].at==cpu && aa[k].p==0)
					{//	printf("hi%d",rq[start].p_no);
						rq[++end]=aa[k];
						aa[k].p=1;
					}
				
				}
			if(rq[start].rt==0){
				l++;
			//	printf("%d\n",rq[start].p_no);
				rq[start].ct=cpu;
				//printf("%d\n",cpu);
				for(int j=0;j<n;j++)
				{
					if(rq[start].p_no == aa[j].p_no)
					{
						aa[j]=rq[start];
					//	break;
					}
				}
				break;
			}	
			else
				time++;
		}
			//	rq[++end]=rq[start];	
		if(time==tq){
			rq[++end]=rq[start];
	//	printf("hi%d",rq[start].p_no);
		}
		
		start++;
	}
	for(i=0;i<n;i++){
		aa[i].tat=aa[i].ct-aa[i].at;
		aa[i].wt=aa[i].tat-aa[i].bt;
	}
	for(i=0;i<n;i++){
		atat+=aa[i].tat;
		awt+=aa[i].wt;
	}
	atat=atat/n;
	awt=awt/n;
	printf("p_no\tAT\tBT\tCT\tTAT\tWT\n");

	for(i=0;i<n;i++){
//	printf("%d",aa[i].ct);
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",aa[i].p_no,aa[i].at,aa[i].bt,aa[i].ct,aa[i].tat,aa[i].wt);
	}
	printf("avg tat=%f\navg wt=%f",atat,awt);
}


