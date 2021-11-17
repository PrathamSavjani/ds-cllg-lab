#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *FIRST=NULL;

struct node *push(int x)
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;
    new->link=FIRST;
    return(new);
}

void pop()
{
    struct node *toDelete;

    if(FIRST == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = FIRST;
        FIRST = FIRST->link;

        printf("\nData deleted = %d\n", toDelete->info);
        free(toDelete);
    }
}

void displayList()
{
    struct node *temp;

    if(FIRST == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = FIRST;
        while(temp != NULL)
        {
            printf("Data = %d Link = %d\n", temp->info,temp->link);
            temp = temp->link;
        }
    }
}

int main()
{
    int x;
    do{
        printf("\n\nEnter:\n1 to push first\n2 to pop last\n3 to display all nodes\n0 to exit\n\n");
        int x;
        scanf("%d" , &x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                FIRST = push(x);
                break;
            
            case 2:
                pop();
                printf("Popped sucessfully");
                break;

            case 3:
                displayList();    
                break;

            case 0:
                exit(EXIT_FAILURE);

            default:
                printf("\nPlease enter valid number for operation\n");  
        }
    }while(x);
return 0;
}