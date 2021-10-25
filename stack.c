                /*STACK IMPLEMENTATION USING ARRAY*/
#include<stdio.h>
int top=-1;
#define N 5
int s[N];
                /*PUSH ALGORITHM*/
void push(int x)
{
    if(top>=N-1)
    {
        printf("STACK OVERFLOW");
        exit(0);
    }
    top++;
    s[top]=x;
}
                /*POP ALGORITHM*/
int pop()
{
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        exit(0);
    }
    top--;
    return s[top+1];
}
                /*PEEP ALGORITHM*/
int peep(int i)
{
    if(top-i+1<=-1)
    {
        printf("STACK UNDERFLOW");
        return 0;
    }
    return (s[top-i+1]);
}
                /* CHANGE ALGORITHM*/
void change(int i,int x)
{
    if(top-i+1<=-1)
    {
        printf("STACK UNDERFLOW");
        return;
    }
    s[top-i+1]=x;
    return;
}
                /*DISPLAY ALGORITHM*/
void display()
{
    int i;
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        return;
    }
    for(i=top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
    return;
}
                    /* MAIN FUNCTION*/
void main()
{
    int choice,i,x;
    do{
        printf("ENTER 1 FOR PUSH\n");
        printf("ENTER 2 FOR POP\n");
        printf("ENTER 3 FOR PEEP\n");
        printf("ENTER 4 FOR CHANGE\n");
        printf("ENTER 5 FOR DISPLAY\n");
        printf("ENTER 0 FOR EXIT");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("ENTER THE VALUE FOR PUSH");
            scanf("%d",&x);
            push(x);
            break;

        case 2:
            x=pop();
            if(x!=0)
            {
                printf("poped value is %d\n",x);
            }
            break;

        case 3:
            printf("ENTER POSITION:");
            scanf("%d",&i);
            x=peep(i);
            if(x!=0)
            {
                printf("PEEPED VALUE IS %d\n",x);
            }
            break;
        
        case 4:
            printf("ENTER THE POSITION FROM TOP");
            scanf("%d",&i);
            printf("ENTER NEW VALUE:");
            scanf("%d",&x);
            change(i,x);
            break;

        case 5:
            display();
            break;
        case 0:
            break;
        default:
            printf("\nWRONG CHOICE TRY AGAIN\n");
            break;
        }
    }while(choice!=0);
}