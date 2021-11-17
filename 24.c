#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node*link;
};

struct node *first=NULL,*last=NULL;

void deleteFirstNode()
{
    struct node *toDelete;

    if(first == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = first;
        first = first->link;

        printf("\nData deleted = %d\n", toDelete->info);
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

void cir_ins_first(int x)
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;
    if(first==NULL)
    {
        new->link=new;
        first=last=new;
    }
    else
    {
        new->link=first;
        last->link=new; 
        first=new;
    }
    return;
}

void cir_ins_last(int x)
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;    
    if(first==NULL)
    {
        new->link=new;
        first=last=new;
    }
    else
    {
        new->link=first;
        last->link=new;
        last=new;
    }
    return;
}

void delete(int pos)
{
    struct node*save,*pred;
    int count=1;
    if(pos==1)
    {
        deleteFirstNode();
        return;
    }
    save=first;
    while(save!=last && count!=pos)
    {
        pred=save;
        save=save->link;
        count++;
    }
    pred->link=save->link;
    free(save);
}

void displayList()
{
    struct node *temp;

    if(first == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = first;
        while(temp != last)
        {
            printf("Data = %d Link = %d\n", temp->info,temp->link);
            temp = temp->link;
        }
    }
}

int main()
{
    do{
        printf("\n\nEnter:\n1 to insert front\n2 to insert last\n3 to delete from given position\n4 to display\n0 to exit\n");
        int x,pos;
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                cir_ins_first(x);
                break;
            case 2:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                cir_ins_last(x);
                break;
             case 3:
                printf("\nEnter the position to delete the node : ");
                scanf("%d",&pos);
                delete(pos);
                break;
            case 4:
                displayList();
                break;
            case 0:
                exit(EXIT_FAILURE);
            default:
                printf("\nPlease enter valid number for operation\n");
        }
    }while(1);
return 0;
}