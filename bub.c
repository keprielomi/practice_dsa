
#include<stdio.h>

int main()
{
    int a[100],i,j,n,temp;
    printf("\n Enter the number of elements you want to enter:");
    scanf("%d",&n);
    printf("\n Enter the elements:");
    for(i=0;i<n;i++)
    {
        printf("\nindex %d:",i);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
     printf("\n The elements after sorting are:");
    for(i=0;i<n;i++)
    {
       printf("%d\t",a[i]);
    }
    printf("\n");
}
