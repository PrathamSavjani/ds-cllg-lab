#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node*link;
};

struct node *FIRST=NULL;

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

void deleteFirstNode()
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

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

struct node *insert_end(int x)
{
    struct node *new,*save;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;
    new->link=NULL;
    if(FIRST==NULL)
    {
        return(new);
    }
    save=FIRST;
    while(save->link!=NULL)
    {
        save=save->link;
    }
    save->link=new;
    return(FIRST);
}

int main()
{
    int x;
    do{
        printf("\n\nEnter:\n1 to insert\n2 to delete\n3 to display first\n4 to exit\n");
        int x;
        scanf("%d" , &x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                FIRST = insert_end(x);
                break;
            case 2:
                deleteFirstNode();
                printf("\nLast node deleted\n");
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