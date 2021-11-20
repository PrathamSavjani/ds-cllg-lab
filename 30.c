#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr, temp, n, k=0;
    printf("Please enter the size of an array: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("\nPlease enter element  %d ", i + 1);
        scanf("%d", &arr[i]);
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j])
                {
                    k=j+1;
                }
            }
            for(int l=i;l>k;l--)
            {
                temp=arr[l];
                arr[l]=arr[l-1];
                arr[l-1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
}