#include <iostream>
using namespace std;
class process
{
    public:
    int arrival, waiting, burst,p_no;
    void operator=(process* a);
};
void process::operator=(process a)
{
    arrival = a.arrival;
    waiting = a.waiting;
    burst = a.burst;
    p_no = a.arrival;
}
process* entry(process* o, int i)
{
        o->p_no = i;
        cout<<"Enter the burst time of process "<<i<<":"<<endl;
        cin>>o->burst;
        cout<<"Enter the arrival time of process "<<i<<":"<<endl;
        cin>>o->arrival;
        return o;      
}
inline void swap(process* i, process* j)
{
    process temp;
    if(i->arrival<j->arrival)
            {
                temp=*j;
                *j=*i;
                *i=temp;
            }
}
int main()
{
    int n,wait=0;
    cout<<"Enter the number of processes: "<<endl;
    cin>>n;
    process ob[n], *t;
    ob[0].waiting=0;
    for(int i=0;i<n;i++)
    {
        ob[i] = *(entry(&ob[i],i));
    }
    for(int j = 0;j<n-1;j++)
    {
        for(int i = j+1; i<n; i++)
        {
            swap(&ob[i],&ob[j]);
        }
    }
    for(int i=1,j=0;i<n;i++,j++)
    {
        wait = wait+ob[j].burst;
        ob[i].waiting = wait;    
    }
    cout<<"The processes are:"<<endl;
    cout<<"p\t\tat\t\tbt\t\twt"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {        
    //        if(i==ob[j].p_no)
    //       {
    //         *t = ob[i];
    //         ob[i]=ob[j];
    //         ob[j]=*t;
    //        }
    //     }
    // }
    for(int i=0;i<n;i++)
    {
        cout<<ob[i].p_no<<"\t\t"<<ob[i].arrival<<"\t\t"<<ob[i].burst<<"\t\t"<<ob[i].waiting<<endl;
    }
}