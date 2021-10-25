#include<stdio.h>
#define N 5
int f=-1,r=-1,q[N];

void cqueue_ins(int x)
{
    if(r==N-1)
    {
        r=0;
    }
    else
    {
        r=r+1;
    }
    if(f==r)
    {
        printf("Overflow");
        return;
    }
    q[r]=x;
    if(f==-1)
    {
        f=0;
    }
    return;
}

int cqueue_del()
{
    int y;
    if(f==-1)
    {
        printf("Underflow");
        return 0;
    }
    y=q[f];
    if(f==r)
    {
        f=r=-1;
        return y;
    }
    if(f==N-1)
    {
        f=0;
    }
    else
    {
        f=f+1;
    }
    return y;
}

cdisplay()
{
    int i,j;
    if(f==-1&&r==-1)
    {
        printf("Queue Underflow");
    }
    if(f>r)
    {
        for(i=f;i<N;i++)
        {
            printf("\t%d",q[i]);
        }
        for(j=0;j<=r;j++)
        {
            printf("\t%d",q[j]);
        }
    }
    else
    {
        for(i=f;i<=r;i++)
        {
            printf("\t%d",q[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice,i,x;
    do{
        printf("ENTER 1 FOR ENQUEUE\n");
        printf("ENTER 2 FOR DEQUEUE\n");
        printf("ENTER 3 FOR DISPALAY\n");
        printf("ENTER 0 FOR EXIT\n");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("ENTER THE VALUE FOR ENQUEUE  ");
            scanf("%d",&x);
            cqueue_ins(x);
            break;

        case 2:
            x=cqueue_del();
            if(x!=0)
            {
                printf("dequeued value is %d\n",x);
            }
            break;
        case 3:
            cdisplay();
            break;
        case 0:
            break;
        default:
            printf("\nWRONG CHOICE TRY AGAIN\n");
            break;
        }
    }while(choice!=0);
return 0;
}