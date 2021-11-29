/*Binary Search
Pratham Savjani 20-11-2021*/
#include<stdio.h>
#include<stdlib.h>

int Binary_search(int e,int n,int *arr)
{
    int left=0,right=n-1,middle;
    while(left<=right)
    {
        middle=(left+right)/2;
        if(arr[middle]==e)
            return middle;
        else if(e<middle)
            right=middle-1;
        else
            left=middle+1;
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
        printf("\nPlease enter element  %d in sorted manner ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Please enter the element you want to search: ");
    scanf("%d",&e);
    index=Binary_search(e,n,arr);
    printf("The element is at index: %d",index);
return 0;
}
