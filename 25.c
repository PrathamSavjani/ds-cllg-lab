/* Write a menu driven program to implement following operations on doubly linked list
a. Insert a node at the front of the linked list
b. Delete a node from the specified position 
c. Insert a node at the end of the linked list
d. Display all nodes
19/11/2021 by Pratham Savjani*/

#include<stdio.h>
#include<stdlib.h>

struct node //creating node
{
    struct node *lptr;
    int info;
    struct node *rptr;
};

struct node *l=NULL,*r=NULL;

void dou_ins_first(int x) //Insert node at first position
{
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;
    if(r==NULL)
    {
        new->lptr=NULL;
        new->rptr=NULL;
        l=r=new;
        return;
    }

    new->rptr=l;
    l->lptr=new;
    new->lptr=NULL;
    l=new;
    return;
}

void dou_ins_last(int x) //Insert at node last position
{
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;
    if(r==NULL)
    {
        new->lptr=NULL;
        new->rptr=NULL;
        l=r=new;
        return;
    }

    new->lptr=r;
    r->rptr=new;
    new->rptr=NULL;
    r=new;
    return;
}

void dou_del_spe(int pos) //Deleting node from specific position
{
    struct node *save,*pred,*temp;
    save=l;
    int count=1;
    if(pos==1)
    {
        l=l->rptr;
        l->lptr=NULL;
        free(save);
        return;
    }
    while(save->rptr!=NULL&&count!=pos)
    {
        pred=save;
        save=save->rptr;
        count++;
    }
    pred->rptr=save->rptr;
    if(save==r)
    {
        r=pred;
        free(save);
        return;
    }
    else
    {
        temp=save->rptr;
        temp->lptr=pred;
        free(save);
        return;
    }
}

void dou_display() //Display all the node in the list
{
    struct node *save;
    save=l;
    if(l==NULL)
    {
        printf("List is empty.");
        return;
    }
    while(save!=NULL)
    {
        printf("Data= %d\n",save->info);
        save=save->rptr;
    }
    return;
}

int main()
{
    int pos;
    do{
        printf("\n\nEnter:\n1 to insert at first\n2 to insert at last\n3 to delete\n4 to display\n0 to exit\n");
        int x;
        scanf("%d" , &x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                dou_ins_first(x);
                break;
            case 2:
                printf("\nEnter the value to be inserted : ");
                scanf("%d",&x);
                dou_ins_last(x);
                break;
            case 3:
                printf("Please enter the position: ");
                scanf("%d",&pos);
                dou_del_spe(pos);
                break;
            case 4:
                dou_display();    
                break;
            case 0:
                exit(EXIT_FAILURE);
            default:
                printf("\nPlease enter valid number for operation\n");  
        }
    }while(1);
return 0;
}