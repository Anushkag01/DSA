#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void push(int data);
void pop();
void display();
int top=-1;
int stack_arr[MAX];
int value;

int main()
{
    int flag=1;
    while(flag)
    {
        int choice;
        printf("1.Do u want to add element\n2.Do u want to delete element\n3. To display element:\n4.To exit\n ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            printf("Enter the element to add:\t");
            scanf("%d",&data);
            push(data);
            break;
        }    
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            exit(1);
            break;
        }
    }
    return 0;
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stackunderflow");
        exit(1);
    }
    for(i=top ;i>=0 ; i--)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n------------------\n");
}

void push(int data)
{
    if(top==MAX-1)
    {
        printf("stack overflow ");
        printf("\n------------------\n");
        return;
    }  
    else
    {  
        top+=1;
        stack_arr[top]=data;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("stack underflow");
        printf("\n------------------\n");
        exit(1);
    }
        value=stack_arr[top];
        printf("The deleted element is %d\n",stack_arr[top]);
        top-=1;
}
