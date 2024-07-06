#include <stdio.h>
#include <conio.h>

int bubble_sort(int arr[25],int num)
{
 int i,j,count,temp;
 count=0;
 for (i=0;i<num-1;i++)
 {
  for(j=0;j<num-1-i;j++)
  {
   if(arr[j]>arr[j+1])
   {
      temp=arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp;
      count++;
   }

  }
 }
    printf("\nThe sorted array:\n");

    for(i=0;i<num;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\nNumber of swaps: %d",count);
}

int main() {
 int arr[25],n,i;
    printf("Enter the number of elements to be swapped (Maximum 25):\n ");
    scanf("%d",&n);

    if (n>25)
    {
        printf("Maximum number exceeded!\n");
    }
    else
    {
     printf("\nEnter the elements\n");

     for(i=0;i<n;i++){
         printf("Enter the element at index %d ",i);
         scanf("%d",&arr[i]);
     }
        printf("\n Your numbers to be sorted:\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);

        }

        getch;

        bubble_sort(arr,n);


    }
    return 0;
}
