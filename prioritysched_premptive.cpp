#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct process
{
int arrivaltime,bursttime,pr,pno;
};
process proc[50];

bool comp(process a,process b)
{
if(a.arrivaltime == b.arrivaltime)
{
return a.pr<b.pr;
}
else
{
	return a.arrivaltime<b.arrivaltime;
}

}


void waiting(int waitingtime[], int totalprocess)
{
int service[50];
service[0] = proc[0].arrivaltime;
waitingtime[0]=0;
for(int i=1;i<totalprocess;i++)
{
service[i]=proc[i-1].bursttime+service[i-1];
waitingtime[i]=service[i]-proc[i].arrivaltime;
	if(waitingtime[i]<0)
	{
	waitingtime[i]=0;
	}
}
}


void turnaround(int tat[],int waitingtime[],int totalprocess)
{
for(int i=0;i<totalprocess;i++)
{
	tat[i]=proc[i].bursttime+waitingtime[i];
}	
}
void findganttchart(int totalprocess)
{
int waitingtime[50],tat[50];
double wavg=0,tavg=0;
waiting(waitingtime,totalprocess);
turnaround(tat,waitingtime,totalprocess);	

int stime[50],ctime[50];
stime[0] = proc[0].arrivaltime;
ctime[0]=stime[0]+tat[0];

for(int i=1;i<totalprocess;i++)
	{
		stime[i]=ctime[i-1];
		ctime[i]=stime[i]+tat[i]-waitingtime[i];
	}	

cout<<"Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time"<<endl;
for(int i=0;i<totalprocess;i++)
	{
		wavg += waitingtime[i];
		tavg += tat[i];
		
		cout<<proc[i].pno<<"\t\t"<<
			stime[i]<<"\t\t"<<ctime[i]<<"\t\t"<<
			tat[i]<<"\t\t\t"<<waitingtime[i]<<endl;
	}
	cout<<"Average waiting time is : "<<wavg/(float)totalprocess;
	cout<<"and average turnaround time is : "<<tavg/(float)totalprocess<<endl;
}
int main()
{
int arrivaltime[] = { 1, 2, 3, 4, 5 };
int bursttime[] = { 3, 5, 1, 7, 4 };
int priority[] = { 3, 4, 1, 7, 8 };
int totalprocess;
cin>>totalprocess;	
for(int i=0;i<totalprocess;i++)
{
	proc[i].arrivaltime=arrivaltime[i];
	proc[i].bursttime=bursttime[i];
	proc[i].pr=priority[i];
	proc[i].pno=i+1;
	}
	sort(proc,proc+totalprocess,comp);
    findganttchart(totalprocess);
	return 0;
}