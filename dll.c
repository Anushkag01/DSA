#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}NODE;

void display(struct node *head)
{
   if(head!=NULL)
    {
        struct node *ptr=head;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

struct node* insert_at_beg(struct node * head,int data);
struct node* add_at_end(struct node * head,int data);
NODE* add_after_pos(struct node *head,int data,int pos);
NODE* add_at_pos(NODE* head,int data,int pos);
NODE* delete_at_end(struct node *head);
NODE* delete_at_beg(struct node *head);
NODE* del_pos(NODE* head,int pos1);
NODE* create_list(NODE* head);

// you can make seperate sstructure for head but we are not doing
int main()
{
    NODE *head=NULL;

    head=create_list(head);

    head=insert_at_beg(head,34);
    display(head);
    printf("\n--------------\n");

    head=create_list(head);

    head=add_at_end(head,45);
    display(head);
    printf("\n--------------\n");

    head=add_at_pos(head,9,2);
    display(head);
    printf("\n--------------\n");
    
    head=add_after_pos(head,89,1);
    display(head);
    printf("\n--------------\n");

    head=add_after_pos(head,67,2);
    display(head);
    printf("\n--------------\n");

    head=delete_at_beg(head);
    display(head);
    printf("\n--------------\n");

    head=delete_at_end(head);
    display(head);
    printf("\n--------------\n");

    head=del_pos(head,2);
    display(head);
    printf("\n--------------\n");

    return 0;
    
}

struct node* insert_at_beg(struct node * head,int data)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    head=temp;
    return head;
}

struct node* add_at_end(struct node * head,int data)
{
    NODE* temp=malloc(sizeof(NODE));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    if (head==NULL)
    {
        head=temp;
    }
    else
    {
        NODE *tp=head;
        while(tp->next!=NULL)
            tp=tp->next;
        tp->next=temp;
        temp->prev=tp;
    }  
    return head;  
}
NODE* add_at_pos(NODE* head,int data,int pos)
{
    NODE* newp=malloc(sizeof(NODE));
    newp->prev=NULL;
    newp->data=data;
    newp->next=NULL;

    if (head == NULL || pos == 1)
    {
        newp->next = head;
        if (head != NULL)
            head->prev = newp;
        head = newp;
    }   
    else
    {
        NODE* temp=head;
        NODE* temp2=NULL;
        while(pos!=1)
        {
            temp2=temp;
            temp=temp->next;
            pos--;
        }
        newp->next=temp;
        temp->prev=newp;
        temp2->next=newp;
        newp->prev=temp2;
    }
    return head;
}
//u can use 1 pointer as well which points to temp->next->next
NODE* add_after_pos(struct node *head,int data,int pos)
{
    NODE* newp=malloc(sizeof(NODE));
    newp->prev=NULL;
    newp->data=data;
    newp->next=NULL;

    NODE* temp=head;
    NODE* temp2=NULL;

    while(pos!=1)
    {
        temp=temp->next;
        pos--;
    }
    if (temp->next==NULL)
    {
        temp->next=newp;
        newp->prev=temp;
    }
    else
    {
        temp2=temp->next;
        temp->next=newp;
        newp->prev=temp;
        temp2->prev=newp;
        newp->next=temp2;

        /*
        or anything is fine because temp and temp are not running
        they will be always where they are  
        but i prefer this :
        temp2=temp->next;
        temp2->prev=newp;
        newp->next=temp2;
        temp->next=newp;
        newp->prev=temp;
        */
    }
    return head;
}

NODE* create_list(NODE* head)
{
    int n,data,i;
    printf("enter n : ");
    scanf("%d",&n);

    if(n==0)
        return head;
    for(i=1;i<=n;i++)
    {
        printf("enter data you want to add");
        scanf("%d",&data);
        head=add_at_end(head,data);
    }
    return head;
}

NODE* delete_at_beg(struct node *head)
{
    if (head==NULL)
    {
        printf("EMPTY LIST");
        return head;
    }
    else
    {
        NODE* temp = head;
        head = head->next;
    
        // If the list becomes empty after deletion
        if (head != NULL)
            head->prev = NULL;
        free(temp); // Free the memory of the original head
        temp=NULL;
    return head;
    }
}
/*
NODE* delete_at_end(struct node *head)
{
    NODE* temp=head;
    NODE* temp2=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    temp=NULL;
    return head;
}
*/

NODE* delete_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("Empty is head");
        return head;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    NODE* temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}

NODE* del_pos(NODE* head,int pos)
{
    NODE* temp=head;
    NODE* temp2=NULL;
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    temp2=temp->prev;
    if(temp->next == NULL)
    {
        free(temp);
        temp=NULL;
        //temp2->next=NULL; redundant?
        return head;
    }
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;

    return head;
}




