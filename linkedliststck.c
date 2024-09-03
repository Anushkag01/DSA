#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE; //or we can write }*top=NULL;
struct node *top=NULL;

void push(int data)
{
    NODE* newp=malloc(sizeof(NODE));
    if(newp==NULL)
    {
        printf("stack overflow");
        exit(1);
    }
    newp->data=data;
    newp->next=NULL;

    newp->next=top;
    top=newp;
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack underflow");
        printf("\n----------------\n");
        exit(1);
    }
    NODE* temp=top;
    top=top->next;
    printf("the element that deleted is %d\n",temp->data);
    free(temp);
    temp=NULL;

}

void display()
{
    if(top!=NULL)
    {
        struct node *ptr=top;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    else
        printf("Underflow\n");
    printf("\n----------------\n");     
}


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