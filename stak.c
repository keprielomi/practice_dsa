/*C program to show working of a stack*/
#include <stdio.h>
#include <stdlib.h>

#define max 10 
int stack[100], i, n; 
int top=-1, val, temp, count=0; 
void push();
void pop();
void display();
void push()
{
    if(top==(max-1))        
    {
        printf("\n Stack Overflow");
    }
    else
    {
        printf("\n Enter the element to be pushed into the stack: ");
        scanf("%d",&val);
        
        top=top+1;                   
        stack[top]=val;             
        count++;                  
        printf("\n No of elements in the stack = %d",count);
    }
}

void pop()
{
    if(top==-1) 
    {
        printf("\n Stack underflow");
    }
    else
    {
        temp=stack[top]; 
        top=top-1;
        printf("\n The deleted element is %d",temp);
    }
}
void display()
{
    if(top==-1) 
    {
        printf("\nStack underflow");
    }
    else
    {
        printf("\nThe elements of the stack are: ");
        for(i=0;i<=top;i++) 
        {
            printf("%d\t",stack[i]);
        }
    }
}
void main()
{
    int option=1;
    while(option==1)
    {
        printf("\n----------------Operations on a stack----------");
        printf("\n 1: Push\t2: Pop\t3: Display \t4: Exit");
        printf("\n-----------------\n");
        printf("Enter your choice:  ");
        scanf("%d",&option);

        switch(option)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("INVALID CHOICE");
        }
        printf("\nDo you wish to continue (Type 0 or 1) 0 to end and 1 to continue: ");
        scanf("%d",&option);
        printf("\n");
    }
}
