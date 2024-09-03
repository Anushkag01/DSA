#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;

}NODE;
struct node* add_at_Beg(struct node* tail,int data) ;
struct node* add_to_end(struct node* tail,int data);
struct node* add_after_pos(struct node* tail,int data,int pos);
struct node* add_at_pos(struct node* tail,int data,int pos);
struct node* del_at_first(struct node* tail);
struct node* del_at_last(NODE* tail);
struct node* del_at_pos(NODE* tail,int pos);
struct node* add_to_empty(int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;

    return temp;
}

void display(struct node* tail)
{
    if(tail ==NULL )
        printf("no data");
    else
    {
        struct node * temp=tail->next;
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        } while (temp!=tail->next);
    } 
    printf("\n");   
}

int main()
{
    NODE *tail;
    tail=add_to_empty(23);
    display(tail);
    printf("-----------------\n");

    tail=add_at_Beg(tail,56);
    display(tail);
    printf("-----------------\n");

    tail=add_to_end(tail,98);
    display(tail);
    printf("-----------------\n");

    tail=add_after_pos(tail,64,2);
    display(tail);
    printf("-----------------\n");

    tail=add_at_pos(tail,55,2);
    display(tail);
    printf("-----------------\n");

    tail=add_at_pos(tail,81,1);
    display(tail);
    printf("-----------------\n");

    tail=add_after_pos(tail,9,4);
    display(tail);
    printf("-----------------\n");

    tail=del_at_first(tail);
    display(tail);
    printf("-----------------\n");

    tail=del_at_last(tail);
    display(tail);
    printf("-----------------\n");

    tail=del_at_pos(tail,3);
    display(tail);
    printf("-----------------\n");

    tail=del_at_pos(tail,4);
    display(tail);
    printf("-----------------\n");

    tail=del_at_pos(tail,1);
    display(tail);
    printf("-----------------\n");

    tail=del_at_pos(tail,1);
    display(tail);
    printf("-----------------\n");

    tail=del_at_pos(tail,1);
    display(tail);
    printf("-----------------\n");

    tail=del_at_last(tail);
    display(tail);
    printf("-----------------\n");

    tail=add_at_pos(tail,81,1);
    display(tail);
    printf("-----------------\n");  
    return 0;
}


//i did by tail but we can use temp
struct node* add_at_Beg(struct node* tail,int data) 
{
    NODE* newp=add_to_empty(data);//or malloc(sizeof(struct node)); both fine
    if(tail==NULL) //means if empty
        return newp;
    newp->prev=tail;
    newp->next=tail->next;
    tail->next->prev=newp;
    tail->next=newp;

    return tail;
}

//i did by tail but we can use temp
/*
truct node* add_at_Beg(struct node* tail,int data) 
{
    NODE* newp=add_to_empty(data);//or malloc(sizeof(struct node)); both fine
    if(tail==NULL) //means if empty
        return newp;
    else
    {
        struct node *temp=tail->next;
        newp->prev=tail;
        newp->next=temp;
        tail->next=newp;
        temp->prev=newp;
        return tail;
    }   
}

struct node* add_to_end(struct node* tail,int data)
{
    struct node* newp=add_to_empty(data);
    if(tail==NULL)
        return newp;
    else
    {
        struct node* temp=tail->next;
        newp->next=temp;
        newp->prev=tail;
        tail->next=newp;
        temp->prev=newp;
        tail=newp;

        return tail;
    }    
    
}
*/
struct node* add_to_end(struct node* tail,int data)
{
    struct node* newp=add_to_empty(data);
    if(tail==NULL)
        return newp;
    else
    {
        newp->next=tail->next;
        newp->prev=tail;
        tail->next=newp;
        tail->next->prev=newp;
        tail=newp;

        return tail;
    }    
    
}

struct node* add_after_pos(struct node* tail,int data,int pos)
{
    struct node* newp=add_to_empty(data);

    if(tail==NULL)
        return newp;
    else
    {
        struct node* temp=tail->next;
        while(pos>1)
        {
            temp=temp->next;
            pos--;
        }
        newp->prev=temp;
        newp->next=temp->next;
        temp->next->prev=newp;
        temp->next=newp;

        if(temp==tail) //so temp is one position behind newnode so if new node inserted at last then tail should be the next node 
            tail=tail->next;
        return tail;    
    }    
}
struct node* add_at_pos(struct node* tail,int data,int pos)
{
    struct node* newp=add_to_empty(data);

    if(tail==NULL)
        return newp;

    if(pos ==1)
    {
        newp->next=tail->next;
        newp->prev=tail;
        tail->next->prev=newp;
        tail->next=newp;
        return tail;
    }    
    else
    {
        struct node* temp=tail->next;
        struct node* temp2=NULL;
        while(pos>1)
        {
            temp2=temp;
            temp=temp->next;
            pos--;
        }
        newp->prev=temp2;
        newp->next=temp;
        temp->prev=newp;
        temp2->next=newp;

        return tail;    
    }    
}

//delete from first node without temp
struct node* del_at_first(struct node* tail)
{
    if(tail==NULL)
        return tail;

    if(tail->next == tail)
    {
        free(tail);
        tail=NULL;
        return NULL;
    } 
    tail->next=tail->next->next;
    tail->next->prev=tail; //so the first node just simply gets ignored at no more in linked to list
    return tail;
}    
/*
del at first with temp
struct node* del_at_first(struct node* tail)
{
    if(tail==NULL)
        return tail;
    struct node* temp=tail->next;
    if(temp==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    } 
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    temp=NULL;
    return tail;
}
*/

struct node* del_at_last(NODE* tail)
{
    if(tail==NULL)
    {
         printf("Empty node\n");
        return tail;
    }    
    struct node* temp=tail->prev;

    if(temp==tail)
    {
        printf("last node\n");
        free(tail);
        tail=NULL;
        return NULL;
    } 

    temp->next=tail->next;
    tail->next->prev=temp;
    free(tail);
    tail=NULL;

    tail=temp;
    return tail;
}

struct node* del_at_pos(NODE* tail,int pos)
{
     if(tail==NULL)
    {
         printf("Empty node\n");
        return tail;
    }    
    struct node* temp=tail->next;
    if (pos==1)
    {
        //only last node and that to delte 
        if(temp == tail)
        {
            free(tail);
            return NULL;
        }
        tail->next=tail->next->next;
        tail->next->prev=tail;
        return tail;
    }
    struct node* temp2=tail->next;
    while(pos>1)
    {
        temp2=temp;
        temp=temp->next;
        pos--;
    }
    temp2->next=temp->next;
    temp->next->prev=temp2;
    if(temp == tail)
        tail=temp2;
    free(temp);
    temp=NULL;
    return tail;
}
