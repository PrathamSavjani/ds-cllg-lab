#include<stdio.h>
#include<stdlib.h>

int Linear_search(int e,int n,int *arr)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==e)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int *arr,n,index,e;
    printf("Please enter the size of an array: ");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("\nPlease enter element %d ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Please enter the element you want to search: ");
    scanf("%d",&e);
    index=Linear_search(e,n,arr);
    printf("The element is at index: %d",index);
return 0;
}