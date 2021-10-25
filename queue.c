#include<stdio.h>
#define N 5
int f=-1,r=-1,q[N];

void queue_ins(int x)
{
    if(x>=N)
    {
        printf("queue overflow");
        return;
    }
    r++;
    q[r]=x;
    if(f==-1)
    {
        f=0;
    }
    return;
}

int queue_del()
{
    int y;
    if(f==-1)
    {
        printf("queue underflow");
        return 0;
    }
    y=q[f];
    if(f==r)
    {
        f=r=-1;
    }
    else
    {
        f++;
    }
    return y;
}

void display()
{
    for(int i=f;i<=r;i++)
    {
        printf("%d |",q[i]);
    }
    printf("\b");
    return;
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
            queue_ins(x);
            break;

        case 2:
            x=queue_del();
            if(x!=0)
            {
                printf("dequeued value is %d\n",x);
            }
            break;
        case 3:
            display();
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