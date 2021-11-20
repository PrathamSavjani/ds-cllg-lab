#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr,min,n,ptr=0,temp,k=0;
    printf("Please enter the size of an array: ");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("\nPlease enter element  %d ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=ptr;i<n;i++)
    {
        min=arr[ptr];
        k=ptr;
        for(int j=ptr+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                k=j;
            }
        }
        temp=arr[ptr];
        arr[ptr]=arr[k];
        arr[k]=temp;
        ptr++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}