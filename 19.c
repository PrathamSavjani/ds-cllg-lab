#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

int main()
{
    struct node *new=NULL;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Please enter the data into the new node: ");
    scanf("%d",&new->info);
    new->link=NULL;
    printf("The new node is: %d -> %d",new->info,new->link);
return 0;
}