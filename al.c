//open all array
#include<stdio.h>
#include<stdlib.h>
int a[100]; //arraysize
int i,j,n,x,option;
int pos;
int val,temp;

void create();
void display();
void insert();
void del();
void search();
void sort();


int main(){
	int option;
	do {
			printf("\n------------------------------\n");
			printf("Select an opertaion:\n");
			printf("\n1:create \n2:Display \n3:insert \n4:Delete \n5:Search \n6:Sorting \n7:Exit \n");
			printf("--------------------------------\n");

			printf("Enter your choice: ");
			scanf("%d",&option);
			switch(option)
			{
				case 1:
				       	create();
					break;
				case 2:
					display();
					break;
				case 3:
					insert();

					break;
				case 4:
					del();
					break;

				case 5:
					search();
					break;
				case 6:
					sort();

					break;
				case 7:
					exit(0);
					break;
				default :
					printf("invalid Choice");
				}
			}while(option!=7);
		printf("\n");

return 0;
}

//all other functions;


void create(){
		printf("Enter the number of elements you want in your array upto 100 elements:\n");
		scanf("%d",&n);
	for (int i=0;i<n;i++){
		printf("enter element %d at index %d: ",i+1,i);
		scanf("%d",&a[i]);
		//printf("\n");
	}
	printf("\n");
	display();

}
void display(){
		printf(" elements in the array are:\n");
		for (int i=0;i<n;i++){
			printf("%d \t",a[i]);

		}
}
void insert(){
	printf("enter the position of the element you want to insert from 0 to %d:",n-1);
	scanf("%d",&pos);
	if(pos>n)
	{
		printf("\nInvalid Operator pick from 0 to %d:",n-1);
		printf("\nEnter again:\n");
		insert();
	}
	else{
			if(pos<n)
			{
				printf("Enter the the element you want to insert in position A[%d]:",pos);
				scanf("%d",&val);				
				for(i=n;i>pos;--i)
				{
					a[i]=a[i-1];
				}
			} 
				//if should be close here
			a[pos]=val;
			n=n+1;
			printf("\n The elements of the array after insertion are:\n");
			 	//sir one
				for(int i=0;i<n;i++){
						printf("%d\t",a[i]);
					}//or it should be closed here
	}	
}
void del()
{
    printf("\n Enter the position from where element has to be deleted from 0 to %d:",n-1);
    scanf("%d",&pos);
    if(pos>n)
    {
        printf("\n Invalid choice of position");
	printf("enter again:\n");
	//del();
    }
    else
    {
	    if(pos<n)
        {
            for(i=pos;i<n-1;i++)
            {
                a[i]=a[i+1];
            }

       // a[pos]=val;
        n=n-1;
        printf("\n The elements of the array after deletion are:");
      // 	display(); 
	for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }
}
	}
}
void search()
{
    printf("\n Enter the element you want to search:");
    scanf("%d",&x);
	pos=-1;
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
            pos=i;
	   	 display();
            printf("\n Element found at position %d",pos);
            break;
        }
    }
    if(pos==-1)
	{
		
        printf("\n %d  Not found in array",x);
		}
}
void sort()
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
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
}
