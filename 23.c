#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *FIRST=NULL;

struct node *insord(int x)
{
    struct node *new,*save;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;
    if(FIRST==NULL)
    {
        new->link=NULL;
        return(new);
    }
    if(new->info<=FIRST->info)
    {
        new->link=FIRST;
        return(new);
    }
    save=FIRST;
    while(save->link!=NULL&&new->info>=(save->link)->info)
    {
        save=save->link;
    }
    new->link=save->link;
    save->link=new;
    return(FIRST);
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

void deleteLastNode()
{
    struct node *save, *pred;

    if(FIRST == NULL)
    {
        printf("List is already empty.");
    }
    save=FIRST;
    while(save->link!=NULL)
    {
        pred=save;
        save=save->link;
    }
    pred->link=NULL;
    free(save);
}

void deleteAtGivenPos(int pos)
{
    struct node*save,*pred;
    int count=1;
    if(pos==1)
    {
        deleteFirstNode();
        return;
    }
    save=FIRST;
    while(save->link!=NULL && count!=pos)
    {
        pred=save;
        save=save->link;
        count++;
    }
    pred->link=save->link;
    free(save);
}

int main()
{
    do{
        printf("\n\nEnter:\n1 to insert\n2 to display\n3 to delete from given position\n4 to delete first\n5 to delete last\n0 to exit\n");
        int x,pos;
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                FIRST = insord(x);
                break;
            case 2:
                displayList();    
                break;
             case 3:
                printf("\nEnter the position to delete the node : ");
                scanf("%d",&pos);
                deleteAtGivenPos(pos);
                break;
            case 4:
                deleteFirstNode();
                printf("\nFirst node deleted\n");
                break;
            case 5:
                deleteLastNode();
                printf("\nLast node deleted\n");
            case 0:
                exit(EXIT_FAILURE);
            default:
                printf("\nPlease enter valid number for operation\n");
        }
    }while(1);
return 0;
}