#include<iostream>
using namespace std;
class process{
	public:
	int at, bt,bt1, ct, tat, wt;
	char name[10];
	void input()
	{
	cout<<"enter name\n";
	cin>>name;
	cout<<"enter at and bt\n";
	cin>>at>>bt;
	bt1=bt;
	}
	void fcfs()
	{
	tat=ct-at;
	wt=ct-at-bt;
	}
};
int main()
{
	process temp;
	int i,j,n,ct=0,max=0,min=0;
	float avgwt=0, avgtat=0;
	cout<<"enter number of process:- ";
	cin>>n;
	process p[n];
	for(i=0;i<n;i++)
	p[i].input();

	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
		if(p[i].at>p[j].at)
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		}
	}
	max=p[i].at;
	}
	min=p[0].at
	
	for(i=1;i<n;i++)
	for(j=i+1;j<n;j++)
	{
		if(p[i].bt>p[j].bt)
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		}
	}
	for(i=0;i<n;i++)
	for(j=min;j<max;j++)
	{
	if(i==0)
	{
	p[i].ct=p[i].at+1;
	p[i].bt1=p[i].bt1-1;
	}
	

	}
	for(i=0;i<n;i++)
	{
	if(i==0)
	p[i].ct=p[i].at;
	else
	p[i].ct=ct;
	p[i].ct+=p[i].bt;
	p[i].fcfs();
	ct=p[i].ct;
	}
	for(i=0;i<n;i++)
	{
		avgwt+=p[i].wt;
		avgtat+=p[i].tat;
	}
	avgwt=avgwt/n;
	avgtat=avgtat/n;
	cout<<"name\tat\tbt\tct\ttat\twt\t\n";
	for(i=0;i<n;i++)
	{
	cout<<p[i].name<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n";
	}
	cout<<"avg wt="<<avgwt<<"\n";
	cout<<"avg tat="<<avgtat<<"\n";
	return 0;
}