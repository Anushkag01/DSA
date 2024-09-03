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
    // while(flag)
    // {
        // int choice;
        // printf("1.Do u want to add element\n 2.Do u want to delete element\n 3. To display element : ");
        // scanf("%d ",&choice);
        push(50);
        display();
        push(10);
        display();
        push(30);
        display();
        push(40);
        display();
        push(60);
        display();
        push(20);
        display();
        pop();
        display();
        pop();
        display();
        pop();
        display();
        pop();
        display();
        pop();
        display();

        // switch (choice)
        // {
        // case /* constant-expression :
        //     /* code */
        //     //  break;
        
        // default:
        //     break;
        // }
    }    

//}

void push(int data)
{
    if(top==MAX-1)
    {
        printf("stack overflow \n");
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
        printf("stack underflow\n");
        exit(1);
    }
        value=stack_arr[top];
        printf("The deleted element is %d\n",stack_arr[top]);
        top-=1;
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