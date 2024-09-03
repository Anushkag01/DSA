#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;

struct node* add_to_empty(int data);
void display(struct node* tail);
struct node* addAtBeg(struct node* tail,int data);
struct node* addAtEnd(struct node* tail,int data);
struct node* addAfterPos(struct node* tail,int data,int pos);
struct node* add_At_Pos(struct node* tail,int data,int pos);
struct node* create_list(struct node* tail);
struct node* del_first(struct node* tail);
struct node* del_last(struct node* tail);
struct node* del_AT_pos(struct node* tail,int pos);

NODE* create_list(NODE* tail)
{
    int n,data,i;
    printf("enter n : ");
    scanf("%d",&n);

    if(n==0)
        return tail;
    for(i=1;i<=n;i++)
    {
        printf("enter data you want to add");
        scanf("%d",&data);
        tail=addAtEnd(tail,data);
    }
    return tail;
}

int main()
{
    struct node *tail;

    tail=add_to_empty(32);
    display(tail);
    printf("\n--------------\n");
    
    tail=create_list(tail);
    display(tail);
    printf("\n--------------\n");


    tail=addAtBeg(tail,56);
    display(tail);
    printf("\n--------------\n");

    tail=addAtEnd(tail,65);
    display(tail);
    printf("\n--------------\n");

    tail=addAfterPos(tail,89,2);
    display(tail);
    printf("\n--------------\n");

    tail=add_At_Pos(tail,99,1);
    display(tail);
    printf("\n--------------\n");

    tail=del_first(tail);
    display(tail);
    printf("\n--------------\n");

    tail=del_last(tail);
    display(tail);
    printf("\n--------------\n");

    tail=del_AT_pos(tail,2);
    display(tail);
    printf("\n--------------\n");

    tail=del_last(tail);
    display(tail);
    printf("\n--------------\n");

    tail=del_last(tail);
    display(tail);
    printf("\n--------------\n");

    tail=add_At_Pos(tail,99,1);
    display(tail);
    printf("\n--------------\n");

    return 0;
}

struct node* add_to_empty(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

void display(struct node* tail)
{
    if(tail == NULL)
        printf("\nEmpty list");
    else{    
    struct node* p=tail->next;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=tail->next);
    }

}

struct node* addAtBeg(struct node* tail,int data)
{
    struct node* newp=add_to_empty(data);//=malloc(sizeof(struct node));
                                         // if u assigning by malloc then newp->data=data;
    newp->next=tail->next;
    tail->next=newp;
    return tail;

}

struct node* addAtEnd(struct node* tail,int data)
{
    struct node* newp=add_to_empty(data);
    newp->next=tail->next;
    tail->next=newp;
    tail=newp;//or tail=tail->next both are fine better is tail of next

    return tail;
}    

struct node* addAfterPos(struct node* tail,int data,int pos)
{
    struct node* p=tail->next;//as tail->next pointing at beginning
    struct node* newp=add_to_empty(data);
    newp->data=data;
    newp->next=NULL;

    while(pos>1)
    {
        p=p->next;
        pos--;
    }
    newp->next=p->next;
    p->next=newp;

    return tail;
}

struct node* add_At_Pos(struct node* tail,int data,int pos)
{
    struct node* newp=add_to_empty(data);

    if (tail==NULL)
    {
        tail=newp;
        return tail;
    }
    if(pos==1)
    {
        newp->next=tail->next;
        tail->next=newp;
        return tail;
    }

    else
    {
        struct node *temp=tail->next;
        struct node *temp2=NULL;

        while(pos>1)
        {
            temp2=temp;
            temp=temp->next;
            pos--;
        }
        newp->next=temp;
        temp2->next=newp;
        
        if(newp->next ==tail->next)
            tail=newp;
        return tail;
    }
}

struct node* del_first(struct node* tail)
{
    if(tail==NULL)
    {
        printf("Empty list");
        return tail;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    
    struct node *temp=tail->next;
    tail->next=temp->next; //tail=temp->next both are fine
    free(temp);
    temp=NULL;
    return tail;
}

struct node* del_last(struct node* tail)
{
    if(tail==NULL)
    {
        printf("Empty list");
        return tail;
    }
    if(tail->next==tail)
    {
        printf("last node");
        free(tail);
        tail=NULL;
        return tail;
    }

    struct node *temp=tail->next;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=tail->next;
    printf("delted element is : %d \n",tail->data);
    free(tail);
    tail=temp;
    return tail;

}

struct node* del_AT_pos(struct node* tail,int pos)
{
    if(tail==NULL)
    {
        printf("Empty list");
        return tail;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }

    struct node* temp=tail->next;
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }
    struct node *temp2=temp->next;
    temp->next=temp2->next;
    
    printf("delted element is : %d \n",temp2->data);
    //used if position is last node
    if(temp2 == tail)
        tail=temp;
    free(temp2);
    temp2=NULL;
    return tail;
}

