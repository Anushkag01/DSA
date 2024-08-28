#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
    int coeff;
    int pow;
    struct node* next;
}node;

void display(struct node *head)
{
   if(head!=NULL)
    {
        struct node *ptr=head;
        while(ptr!=NULL)
        {
            printf("%d %d\t",ptr->coeff,ptr->pow);
            ptr=ptr->next;
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }
}

void input(node** head,node** tail,int n);
node* sum(node* head1,node* head2);
int eval(node* head,int x);
void destroy(node **head);

int main()
{
    int m=0;
    int n=0;
    node* head1=NULL;
    node* head2=NULL;
    node* tail1=NULL;
    node* tail2=NULL;
    int x=0;//value of the variable for evaluation
    scanf("%d %d",&m,&n);
    scanf("%d",&x);
    input(&head1,&tail1,m);
    //display(head1);
    input(&head2,&tail2,n);
    //display(head2);
    node *headres=sum(head1,head2);
    display(headres);
    int res=eval(headres,x);
    printf("%d",res);
  	destroy(&head1);
 	 destroy(&head2);
    destroy(&headres);
    return 0;
}

void input(node** head,node** tail,int n)
{
    //Your Code
        for(int i=0;i<n;i++){
        node* temp=malloc(sizeof(node));
        scanf("%d %d",&(temp->coeff),&(temp->pow));
        temp->next=*head;
        *head=temp;
    }
}
node* sum(node* head1,node* head2)
{
    //Your Code
    /*
    node* temp=NULL;
    node *ptr1=head1;
    node *ptr2=head2;
    node* headres=malloc(sizeof(node));
    headres->coeff=head1->coeff;
    headres->pow=head1->pow;
    headres->next=NULL;
    while(ptr1!=NULL)
    {
        temp=malloc(sizeof(node));
        if(ptr1!=NULL)
        {
            ptr1=ptr1->next;
            temp->coeff=ptr1->coeff;
            temp->pow=ptr1->pow;
            temp->next=headres;
            headres=temp;
        }
        display(headres);
    }
    display(headres);
    while(ptr2!=NULL)
    {
        if(ptr2->pow==temp->pow)
        {
            temp->coeff=(ptr2->coeff)+(temp->coeff);
            temp=temp->next;
        }
        ptr2=ptr2->next;
        display(temp);
    }
    return 0;*/
    node* result = NULL;
    node** lastPtrRef = &result;

    // Copy the first node from head1 to headres
    if (head1 != NULL)
    {
        result = malloc(sizeof(node));
        result->coeff = head1->coeff;
        result->pow = head1->pow;
        result->next = NULL;
        lastPtrRef = &result->next;
        head1 = head1->next;
    }

    // Process the rest of the nodes from head1
    while (head1 != NULL)
    {
        node* temp = malloc(sizeof(node));
        temp->coeff = head1->coeff;
        temp->pow = head1->pow;
        temp->next = NULL;

        *lastPtrRef = temp;
        lastPtrRef = &temp->next;

        head1 = head1->next;
    }

    // Process the nodes from head2 (similar to the corrected code I provided earlier)
    while (head2 != NULL)
    {
        node* temp = result;
        node* prev = NULL;

        // Find if a node with the same power exists in result
        while (temp != NULL && temp->pow > head2->pow)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL && temp->pow == head2->pow)
        {
            // If a node with the same power exists, add the coefficients
            temp->coeff += head2->coeff;
        }
        else
        {
            // Otherwise, create a new node and insert it in the correct position
            node* newNode = malloc(sizeof(node));
            newNode->coeff = head2->coeff;
            newNode->pow = head2->pow;
            newNode->next = temp;

            if (prev == NULL)
            {
                // Insert at the beginning
                result = newNode;
            }
            else
            {
                prev->next = newNode;
            }
        }

        head2 = head2->next;
    }

    return result;
}

int eval(node* head,int x)
{
    //Your Code
    return 0;
}
void destroy(node **head)
{
    //Your Code
    node *p=*head;
    node *q=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        free(q);
    }
    *head=NULL;
}
    