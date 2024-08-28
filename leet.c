#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE* add_at_end(struct node * head,int data);
NODE* reorder(struct node* head);

void display(struct node *head)
{
   if(head!=NULL)
    {
        struct node *ptr=head;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
    }
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

NODE* add_at_end(struct node * head,int data)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    if(head==NULL)
        head=temp;
    else
    { 
        struct node *ptr=head;   
        while (ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
    return head;
}

int main()
{
    struct node *head=NULL;
    //head=malloc(sizeof(struct node));
    head=create_list(head);
    display(head);
    printf("\n---------------\n");

    head=reorder(head);
    display(head);

    return 0;
}    

NODE* reorder(struct node* head)
{
    struct node* temp=head->link;
    struct node* temp1=head;
    struct node* temp2=NULL;

    if(head==NULL || head->link==NULL)
        return head;

    else
    {
        while(temp1->link!=NULL)
        {
            temp2=temp1;
            temp1=temp1->link;
        }
        temp1->link=temp->link;
        temp2->link=temp;
        temp->link=NULL;
        head->link=temp1;

        return head;
    }
}