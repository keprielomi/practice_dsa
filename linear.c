#include<stdio.h>
void main()
{
    int a[100],i,n,x, pos=-1;
    printf("\n Enter the number of elements you want to enter:");
    scanf("%d",&n);
    printf("\n Enter the elements:");
    for(i=0;i<n;i++)
    {
        printf("\n Enter element at index A[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("Your array is:\t");
    for(i=0;i<n;i++)
    {
        printf("%d,\t",a[i]);
    }
    printf("\n Enter the element you want to search:");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
            pos=i;
            printf("\n Element found at position %d \n",pos);
            break;
        }
    }
    if(pos==-1){
        printf("\n Element Not found \n");
    }
    
}
