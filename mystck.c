#include<stdio.h>
#include<stdlib.h>

#define max 5
int stack[max];
int top=-1;
int i,val,temp;

void push();
void pop();
void display();
void call();

int main(){
    int option=1;
    while(option){
        call();
        printf("\n-------------\n");
        printf("\nTo continue enter 1 else to exit enter 0:");
        scanf("%d",&option);
        printf("\n---------------\n");

    }


    return 0;
}
void call(){
    
        int c;
        printf("\nchoose an option:\n1:push\t2:pop\t3:display\t4:exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
                push();
            break;
        case 2:
                pop();
                break;
        case 3:
                display();
                break;
        case 4:
                exit(0);
                break;
        default:
                printf("inavlid operator enter again:\n");
                call();
            break;
        }

}
void push(){
    if (top==max-1){
        printf("Overflow\n");
    }else{
        printf("enter your value: ");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
        printf(" %d is stored \n There are %d total values in stack",val,top+1);
    }

}
void pop()
{
if(top==-1){
        printf("Under flow\n");
}else{
    temp=stack[top];
    top=top-1;
    printf("%d is removed from stack\n",temp);
    printf("there is only %d values left\n",top+1);


}
}
void display(){

    if (top==-1){
        printf("stack is empty there is %d values",top+1);

    }else{
            printf("Stack elements are:\n");
        for(i=0;i<=top;i++){
            printf("%d \t",stack[i]);
        }
    }

}
