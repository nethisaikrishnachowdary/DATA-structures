#include<stdio.h>
#include<stdlib.h>
struct slist
{
    int data;
    struct slist *next;
};
typedef struct slist node;
node* create(node *first)
{
    node *new,*prev;
    int x;
    printf("enter the value of data");
    scanf("%d",&x);
    while(x!=-1)
    {
        new=(node*) malloc (sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL)
        {
            first=new;
            prev=new;
        }
        else
        {
            prev->next=new;
            prev=new;
        }
        printf("\nenter the value of data(enter -1 to stop)\n");
        scanf("%d",&x);
    }
    return first;
}
void display(node *first)
{
    node *temp=first;
    if(temp==NULL)
    {
        printf("no list to print");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("|%d|->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
   
}
int count(node *first)
{
    node *temp=first;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
void search(node *first,int x)
{
    node *temp=first;
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            flag=1;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    if(flag==1)
    {
        printf("the element %d is found\n",x);
    }
    else
    {
        printf("the element %d is not found\n",x);
    }
}
node* insert_at_begin(node *first,int x)
{
    node *new=(node*) malloc (sizeof(node));
    new->data=x;
    new->next=NULL;
    if(first==NULL)
    {
        first=new;
    }
    else
    {
        new->next=first;
        first=new;
    }
    return first;
}
node* insert_at_end(node *first,int x)
{
    node *new=(node*) malloc (sizeof(node));
    node *temp=first;
    new->data=x;
    new->next=NULL;
    if(first==NULL)
    {
        first=new;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
    return first;
}
node* insert_at_pos(node *first,int x,int pos)
{
    node *temp=first,*new;
    int n=count(first),i;
    if(pos>1&&pos<n)
    {
        node *new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    return first;
}
node* delete(node *first,int x)
{
    node *temp,*temp1;
    int flag=0;
    temp=first;
    if(first->data==x)
    {
        first=first->next;
        free(temp);
    }
    else
    {
        temp1=first;
        temp=first->next;
        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                flag=1;
                break;
            }
            else
            {
                temp1=temp;
                temp=temp->next;
            }
        }
    }
    if(flag==1)
    {
        temp1->next=temp->next;
        free(temp);
        printf("ELEMENT IS DELETED SUCCESSFULLY");
    }
    else
    {
        printf("element is not found\n");
    }
    return first;
}
node* sort(node *first)
{
    node *temp1,*temp2;
    int x;
    for(temp1=first;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
        {
            if(temp1->data>temp2->data)
            {
                x=temp1->data;
                temp1->data=temp2->data;
                temp2->data=x;
            }
        }
    }
    printf("SUCCESSFULLY SORTED THE LIST");
    return first;
}
node* reverse(node *first)
{
    node *present=first,*prev=NULL,*save=NULL;
    while(present!=NULL)
    {
        save=present->next;
        present->next=prev;
        prev=present;
        present=save;
    }
    first=prev;
    printf("SUCCESSFULLY REVERSED THE LIST");
    return first;
}
void main()
{
    node *head=NULL;
    head=create(head);
    while(1)
    {   
        int choice,n,ele,pos,x,d;
        printf("\n1:display\n 2:count\n 3:search\n 4:insert\n 5:delete\n 6:sort\n 7:reverse\n 8:exit");
        printf("\nenter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: display(head);
                    break;
            case 2: 
                    n=count(head);
                    printf("the no. of nodes in the list are %d",n);
                    break;
            case 3: 
                    printf("enter the element to be searched");
                    scanf("%d",&ele);
                    search(head,ele);
                    break;
            case 4: 
                    printf("enter the element to be inserted ");
                    scanf("%d",&x);
                    printf("enter the positon to be inserted");
                    scanf("%d",&pos);
                    n=count(head);
                    if (pos==1){
                     head=insert_at_begin(head,x);
                    break;   
                    }
                    else if(pos>1&&pos<n){
                        head=insert_at_pos(head,x,pos);
                    
                    }
                    else if(pos==n){
                        head=insert_at_end(head,x);
                        
                    }
                    else{
                        printf("enter the correct position");
                    }
                    
                    break;
            case 5: 
                    printf("enter the value to be deleted");
                    scanf("%d",&d);
                    head=delete(head,d);
                    break;
            case 6: head=sort(head);
                    
                    break;
            case 7: head=reverse(head);
                    
                    break;
            case 8: printf("PROGRAM IS SUCCESSFULLY EXECUTED");
                    exit(0);
                    break;
            default:printf("invalid input");
                    break;
           
        }
    }
}
