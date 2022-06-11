#include<iostream>
using namespace std;


void waitingtime(int processes[], int n, int bursttime[], int weight[], int quantum)
{
    int* rembursttime = new int[n];
    for (int i = 0 ; i < n ; i++)
        rembursttime[i] = bursttime[i];
    int t = 0;
    while (1)
    {
        bool done = true;
        for (int i = 0 ; i < n; i++)
        {
            if (rembursttime[i] > 0)
            {
                done = false;
                if (rembursttime[i] > quantum)
                {
                    t += quantum;
                    rembursttime[i] -= quantum;
                }
                else
                {
                    t = t + rembursttime[i];
                    weight[i] = t - bursttime[i];
                    rembursttime[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}

void turnaround(int processes[], int n, int bursttime[], int weight[], int turnAroundTime[])
{
    for (int i = 0; i < n ; i++)
        turnAroundTime[i] = bursttime[i] + weight[i];

}

void averagetime(int processes[], int n, int bursttime[], int quantum)
{
    int total_weight = 0, total_turnAroundTime = 0;
    int* weight=new int[n];
    int* turnAroundTime=new int[n];
    waitingtime(processes, n, bursttime, weight, quantum);
    turnaround(processes, n, bursttime, weight, turnAroundTime);
    cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n";
    for (int i=0; i<n; i++)
    {
        total_weight = total_weight + weight[i];
        total_turnAroundTime = total_turnAroundTime + turnAroundTime[i];
        cout << " " << i+1 << "\t\t" << bursttime[i] <<"\t "<< weight[i] <<"\t\t " << turnAroundTime[i] <<endl;
    }
    cout << "Average waiting time is "<< (float)total_weight / (float)n;
    cout << " and average turn around time is "<< (float)total_turnAroundTime /
    (float)n;
}

int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int* processes= new int[n];
    int* bursttime= new int[n];
    cout<<"Enter the burst time of processes in (s): ";
    for(int i=0;i<n;i++)
    {
        cin>>bursttime[i];
    }
    int timequantum;
    cout<<"Enter the time quantum in (s): ";
    cin>>timequantum;

    averagetime(processes, n, bursttime, timequantum);
    return 0;
}