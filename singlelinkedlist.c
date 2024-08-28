#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void display(struct node *head);
void count_of_nodes(struct node *head);
void add_at_end(struct node * head,int data);
struct node* insert_at_beg(struct node * head,int data);
void insert_at_pos(struct node *head,int data,int pos);
struct node* delete_at_beg(struct node *head);
struct node* delete_at_end(struct node *head);
void del_pos(struct node *head,int pos);
struct node* del_list(struct node* head);


int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=malloc(sizeof(struct node));
    head->link->data=98;
    head->link->link=malloc(sizeof(struct node));
    head->link->link->data=3;
    head->link->link->link=NULL;

    display(head);
    count_of_nodes(head);
    printf("------------------------------\n");

    add_at_end(head,67);
    display(head);
    count_of_nodes(head);
    printf("------------------------------\n");

    head=insert_at_beg(head,40);
    display(head);
    count_of_nodes(head);
    printf("------------------------------\n");

    insert_at_pos(head,52,3);
    display(head);
    count_of_nodes(head);
    printf("------------------------------\n");

    head=delete_at_beg(head);
    display(head);
    count_of_nodes(head);
    printf("------------------------------\n");

    head=delete_at_end(head);
    display(head);
    count_of_nodes(head);
    printf("------------------------------\n");

    del_pos(head,2);
    display(head);
    count_of_nodes(head);
    printf("------------------------------\n");

    head=del_list(head);
    display(head);
    count_of_nodes(head);
    printf("------------------------------\n");
    return 0;
}

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

void count_of_nodes(struct node *head)
{
    int count=0;
    if(head!=NULL)
    {
        struct node *ptr=head;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->link;
        }
        printf("\ncount is: %d\n",count);
    }
    else
        printf("\nEmpty list\n");
}

void add_at_end(struct node * head,int data)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }

    ptr->link=temp;

}

struct node* insert_at_beg(struct node * head,int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=head;
    head=ptr;
    return head;
}

void insert_at_pos(struct node *head,int data,int pos)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;
}

struct node* delete_at_beg(struct node *head)
{
    if(head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node *temp=head;
        head=head->link;
        printf("element to be deleted %d\n",temp->data);
        free(temp);
        temp=NULL;
    }    
    return head;
}

struct node* delete_at_end(struct node *head)
{
    struct node *temp1=head;
    struct node *temp2=head;
    while(temp1->link!=NULL)
    {
        temp2=temp1;
        temp1=temp1->link;
    }
        printf("deleted elemnt %d \n",temp1->data);
        temp2->link=NULL;
        free(temp1);
        temp1=NULL;
        return head;
}  

void del_pos(struct node *head,int pos)
{
	struct node *current=head;
	struct node *previous=head;
	if(head==NULL)
		printf("list is already empty");
	else if(pos==1)
	{
		head=current->link;
		free(current);
		current=NULL;
	}
	else
	{
		while(pos!=1)
		{
			previous=current;
			current=current->link;
			pos--;
		}
		printf("\nThe node which is deleted is :%d\n",current->data);
		previous->link=current->link;
		free(current);
		current=NULL;
	}
}

// to delete entire linked list traverse every time at a node an delete and show the delted one
struct node* del_list(struct node* head)
{
	if(head==NULL)
		printf("NO nodes delete List\n");
	struct node *temp=head;
	while(temp!=NULL)
	{
		temp=temp->link;
		printf("\ndeleted is :%d",head->data);
		free(head);
		head=temp;
	}
	return head;
}