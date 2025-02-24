#include <stdio.h>
struct process
{
    int pid;
    int size;
}p[100];
struct memory
{
    int size;
    int is_allocated;
    int remaining;
}m[10];
void firstfit(int n,int m);
void bestfit(int n,int m);
void worstcase(int n,int m);
void display(int m); //to display remaining memory size
void reset(int m); //To reset each memory block 
int main() {
    
    int n;//to store no.of process
    int m; //to store no.of memory blocks
    int ch;
    printf("enter number of processes");
    scanf("%d",&n);
    printf("enter process id and size\n");
    for(int i=0;i<n;++i)
    {
        printf("enter pid of process %d:",i+1);
        scanf("%d",&p[i].pid);
         printf("enter size of process %d\:",i+1);
        scanf("%d",&p[i].size);
    }
    printf("\n\nenter number of memory blocks");
    scanf("%d",&m);
    for(int i=0;i<m++i)
    {
        printf("enter size of memory block %d:",i+1);
        scanf("%d",&m[i].size);
        m[i].is_allocated=0;
        m[i].remaining=m[i].size;
    }
    do
    {
        printf("enter choice\n");
        printf("1.First Fit\t2.Best Fit\t3.Worst Fit\t4.Remaining Memory\t5.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: reset(m);
                    firstfit(n,m);
                    break;
                    
            case 2: reset(m);
                    bestfit(n,m);
                    break;
                    
            case 3: reset(m);
                    worstfit(n,m);
                    break;
            case 4: display(m);
                    break;
            case 5: break;
            
            default: printf("invalid choice\n");
        }
    }
   

    return 0;
}
void reset(int m)
{
  for(int i=0;i<m++i)
    {
        m[i].is_allocated=0;
        m[i].remaining=m[i].size;
    }  
}
 void firstfit(int n,int m)
    {
        printf("\nFirst fit memory Allocation:\n");
        for(int i=0;i<n;++i)
        {
            int allocated=0;
            for(int j=0;j<m;++j)
            {
                if(m[j].remaing>=p[i].size||m[j].is_allocated==0)
                {
                    
                }
            }
        }
    }
