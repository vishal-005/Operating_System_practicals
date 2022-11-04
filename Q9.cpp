#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

struct Process
{
    int pid;
    int burst_time;
    
    int waiting_time;
    int response_time;
    int turnaround_time;
    int arrival_time;
    int completion_time;
    int starting_time;
    int priority;
};

class NPPS
{
    int n, total_tat;
    float avg_tat;
    Process *p;

    public:
        NPPS();
        void input();
        void arrival_sort();
        void sort(int, int);
        void sort2();
        void calc();
        void GC();
        void output();
};

NPPS :: NPPS()
{
    total_tat = 0;
    avg_tat = 0;
}

void NPPS :: input()
{    
    cout<<endl<<endl<<"Enter the total number of processes : ";
    cin>>n;
    
    p = new Process[n];

    cout<<endl<<endl<<"Enter the arrival time of each process : "<<endl;
    for(int i=0; i<n; i++)
    {
        p[i].pid = i+1;
        cout<<"[P"<<p[i].pid<<"] : ";
        cin>>p[i].arrival_time;
    }
    
    cout<<endl<<endl<<"Enter the burst time of each process : "<<endl;    
    for(int i=0; i<n; i++)
    {
        cout<<"[P"<<p[i].pid<<"] : ";
        cin>>p[i].burst_time;
    }
    
    cout<<endl<<endl<<"Enter the priority of each process : "<<endl;    
    for(int i=0; i<n; i++)
    {
        cout<<"[P"<<p[i].pid<<"] : ";
        cin>>p[i].priority;
    }
}

void NPPS :: sort2()
{    
    int i, j;
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(p[j].arrival_time > p[j+1].arrival_time)
            swap(p[j], p[j+1]);
        }
    }
    
    for(i=0; i<n; i++) 
    {    
        p[i].starting_time = (i==0)? p[i].arrival_time : max(p[i].arrival_time, p[i-1].completion_time);
        p[i].completion_time = p[i].burst_time + p[i].starting_time;
        
        for(j=i; j<n; j++) 
        {
            if(p[i].completion_time < p[j+1].arrival_time)
            break;
        }
        
        if(p[i].arrival_time == p[i+1].arrival_time)
        sort(i,j);
        
        else
        sort(i+1, j);
    }
}

void NPPS :: sort(int x, int y)
{
    Process *temp = new Process[y-x+1];
    
    int i, j;
    
    for(j=0,i=x; i<=y; i++)
    {
        temp[j] = p[i];
        j++;
    }

    for(i=0; i<y-x+1; i++)
    {
        for(j=0; j<y-x-i; j++)
        {  
            if(temp[j].priority > temp[j+1].priority)
            {
                swap(temp[j], temp[j+1]);
            }
        }
    }

    for(j=0,i=x; i<=y; i++)
    {
        p[i] = temp[j];
        j++;
    }

    delete temp;
}

void NPPS :: calc()
{
    for(int i=0; i<n; i++)
    {
        p[i].starting_time = (i == 0) ? p[i].arrival_time : max(p[i].arrival_time, p[i-1].completion_time);
        p[i].completion_time = p[i].starting_time + p[i].burst_time;
        
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        p[i].response_time = p[i].waiting_time;
    
        total_tat += p[i].turnaround_time;
    }
    
    avg_tat = total_tat/n;
}

void NPPS :: GC()
{
    int i;
    
    cout<<setw(40)<<"\n\n ~~~~~~~~~~~~~~~~~~~~~~~~ GANTT CHART ~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n";
    cout<<endl;
    
    
    cout<<"";
    for(i=0; i<n; i++)
    {
        cout<<"\t P"<<p[i].pid<<"\t";
    }
    cout<<""<<endl<<endl;
    
    cout<<p[0].arrival_time<<"\t\t";
    for(i=0; i<n; i++)
    {
        cout<<p[i].completion_time<<"\t\t";
    }
    
    cout<<endl<<endl;
}

void NPPS :: output()
{
    cout<<" Processes  "<<" Arrival time "<<" Burst time "<<" Completion time "<<" Waiting time  "<< " Response time  "<<" Turnaround time "<<endl;
     
    for (int i=0; i<n; i++)
    {
        cout<< "   "<<p[i].pid << "\t\t"<<p[i].arrival_time <<" \t     "<<p[i].burst_time<<" \t\t    "<<p[i].completion_time<<" \t\t    "<<p[i].waiting_time<<"     \t "<<p[i].response_time <<"\t          "    << p[i].turnaround_time << endl;
    }
    
    cout<<endl;

    cout<<"Total Turnaround time   :   "<<total_tat<<endl;
    cout<<"Total Average time   :   "<<avg_tat<<endl;
}

int main()
{
    NPPS ob;
    
    cout<<"\n ~~~~~~~~ Non-preemptive priority based scheduling algorithm ~~~~~~~~~ \n";
    ob.input();
    ob.sort2();
    ob.calc();
    ob.GC();
    ob.output();
    getch();
    return 0;
    
}