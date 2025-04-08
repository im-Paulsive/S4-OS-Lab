#include<stdio.h>

struct process
{
    int id,at,bt,bt_remaining,priority,ct,wt,tat,completed;
};
void printtable(struct process p[],int n)
{
    int tot_tat=0,tot_wt=0;
    printf("PID     AT      BT      Prio        TAT     WT    \n");
    
    for(int i=0;i<n;++i)
    {
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        tot_tat+=p[i].tat;
        tot_wt+=p[i].wt;
        
        printf("%d  %d  %d  %d  %d  %d\n",p[i].id,p[i].at,p[i].bt,p[i].priority,p[i].ct,p[i].tat,p[i].wt);
       
    }
        printf("average turnaround time:%f",(float)tot_tat/n);
        printf("average waiting time:%f",(float)tot_wt/n);
}
void sort(struct process p[],int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n-i-1;++j)
        {
            if(p[j].at>p[j+1].at)
            {
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
void fcfs(struct process p[],int n)
{
    int time=0;
    printf("\ngantt chart");
    for(int i=0;i<n;++i)
    {
        if(time<p[i].at)
            time=p[i].at;
        printf("|p%d",p[i].id);
        p[i].ct=time+p[i].bt;
        time=p[i].ct;
    }
    printf("|\n");
    printtable(p,n);
}
void sjf(struct process p[],int n)
{
    int time=0,completed=0;
    printf("\n gantt chart");
    while(completed<n)
    {
        int min_bt=9999,idx=-1;
        for(int i=0;i<n;++i)
        {
            if(!p[i].completed&&p[i].at<=time&&p[i].bt<min_bt)
            {
                min_bt=p[i].bt;
                idx=i;
            }
        }
        if(idx==-1)
        {
            time++;
            continue;
        }
        printf("|p%d",p[idx].id);
        time+=p[idx].bt;
        p[idx].ct=time;
        p[idx].completed=1;
        completed++;
    }
    printtable(p,n);
}

int main()
{
    
    int n,quantum;
    printf("enter no.of process\n");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;++i)
    {
        printf("enter at,bt,prio of process %d:",i+1);
        scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].priority);
        p[i].id=i+1;
        p[i].bt_remaining=p[i].bt;
        p[i].completed=0;
    }
    sort(p,n);
    sjf(p,n);
    return 0;
}
