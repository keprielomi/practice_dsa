#include<stdio.h>

void main()
{
    int a[100],n,i,pos, val;
    printf("\n Enter the number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter element at position A[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("Your array before insertion is:\t");
    for(i=0;i<n;i++)
    {
        printf("%d,\t",a[i]);
    }

    printf("\n Enter the position where element has to be inserted:");
    scanf("%d",&pos);
    printf("\n Enter the element to be inserted:");
    scanf("%d",&val);
    if(pos>n)
    {
        printf("\n Invalid choice of position");
    }
    else
    {   if(pos<n)
        {   
            for(i=n;i>=pos;i--)
            {
                a[i]=a[i-1];
            }
        }
        a[pos]=val;
        n=n+1;
        printf("\n The elements of the array after insertion are:");
        for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }
    }
    printf("\n");
 }
