#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *FIRST=NULL;

struct node *insert_frnt(int x)
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;
    new->link=FIRST;
    return(new);
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

void deleteOrderNode(struct node *x)
{
    struct node *save,*pred;
    if(FIRST==NULL)
    {
        printf("Underflow");
        return;
    }
    save=FIRST;
    while(save!=x&&save->link!=NULL)
    {
        pred=save;
        save=save->link;
    }
    if(save!=x)
    {
        printf("node not found");
        return;
    }
    if(x=FIRST)
    {
        FIRST=FIRST->link;
    }
    else
    {
        pred->link=x->link;
    }
    free(x);
}

int main()
{
    int x;
    do{
        printf("\n\nEnter:\n1 to insert first\n2 to insert last\n3 to delete first\n4 to delete last\n5 to delete at given position\n6 to display all nodes\n0 to exit\n\n");
        int x;
        struct node *pos;
        scanf("%d" , &x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                FIRST = insert_frnt(x);
                break;
            
            case 2:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                FIRST = insert_end(x);
                break;

            case 3:
                deleteFirstNode();
                printf("\nFirst node deleted\n");
                break;

            case 4:
                deleteLastNode();
                printf("\nLast node deleted\n");
                break;
            case 5:
                printf("\nEnter the position to delete the node : ");
                scanf("%d",&pos->link);
                deleteOrderNode(pos);
                break;
            case 6:
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