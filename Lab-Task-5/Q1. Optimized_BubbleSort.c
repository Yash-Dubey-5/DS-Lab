#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return;
}

void BubbleSort(int arr[],int size)
{
    int swaps;
    for(int i=0;i<size-1;i++)
    {
        swaps=0;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swaps++;
            }
        }
        if(swaps==0)
        break;
    }
    return;
}

int main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    BubbleSort(arr,n);
    printf("Sorted array:");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
