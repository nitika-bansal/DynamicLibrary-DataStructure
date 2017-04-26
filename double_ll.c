#include<stdio.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
}*head;
void dllinsertb()
{
    int x;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&x);
    temp->data=x;
    if(head==NULL)
    {
        temp->prev=NULL;
        temp->next=head;
        head=temp;
    }
    else
    {
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
    }
}
void dllinserte()
{
    int x;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
        head=temp;
    else
    {
         struct node* t=head;
         while(t->next!=NULL)
            t=t->next;
         temp->prev=t;
         t->next=temp;
    }
}
void dllinsertn()
{
    int x,y;
    printf("Enter the element data after which you want to insert: ");
    scanf("%d",&y);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    struct node*t=head;
    while(t->next!=NULL)
    {
        if(t->next==NULL)
        {
            if(t->data==x)
            {
                temp->prev=t;
                temp->next=NULL;
                t->next=temp;
            }
        }
        else
        {
            if(t->data==y)
            {
                temp->prev=t;
                temp->next=t->next;
                t->next->prev=temp;
                t->next=temp;
            }
        }
        t=t->next;
    }
}
void dllprint()
{
    SetColor(11);
    struct node*t=head;
    printf("\nDoubly linked list: ");
    while(t!=NULL)
    {
        printf("%d-> ",t->data);
        t=t->next;
    }
    printf("\n\n");
}
void dlldelete()
{
    int x;
    printf("Enter the element value you want to delete: ");
    SetColor(11);
    scanf("%d",&x);
    struct node* t=head;
    while(t!=NULL)
    {
        if(t->prev==NULL)
        {
            if(t->data==x)
               {
                    head=t->next;
                    free(t);
                    printf("Element deleted successfully...\n");
                    return;
               }
        }
        else if(t->next==NULL)
        {
            if(t->data==x)
            {
                t->prev->next=NULL;
                free(t);
                printf("Element deleted successfully...\n");
                return;
            }
        }
        else
        {
             if(t->data==x)
            {
                t->prev->next=t->next;
                t->next->prev=t->prev;
                free(t);
                t=NULL;
                printf("Element deleted successfully...\n");
                return;
            }
        }
        t=t->next;
    }
    printf("Element not found\n");
}
void dllsearch()
{
    int x,i=1;
    printf("Enter the element value you want to search: ");
    scanf("%d",&x);
    struct node*t=head;
    SetColor(11);
    while(t!=NULL)
    {
        if(t->data==x)
            printf("The element position is %d\n",i);
        t=t->next;
        i++;
    }
}
void double_linked_list()
{
    int c,n;
    while(1)
    {
        int i=0;
        system("cls");
        SetColor(11);
        printf("\t\t\t******DOUBLY LINKED LIST******\n\n\n");
        SetColor(7);
        printf("\t\t1.Insert in beginning\n");
        printf("\t\t2.Insert at end\n");
        printf("\t\t3.Insert in nth position\n");
        printf("\t\t4.Delete a node\n");
        printf("\t\t5.Search an element\n");
        printf("\t\t6.Display the list\n");
        printf("\t\t7.Go to main menu\n\n");
        printf("\t\tEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the no. of nodes: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        dllinsertb();
                        i++;
                    }
                    dllprint();
                    system("pause");
                    break;
            case 2: printf("\nEnter the no. of nodes: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        dllinserte();
                        i++;
                    }
                    dllprint();
                    system("pause");
                    break;
            case 3: dllinsertn();
                    dllprint();
                    system("pause");
                    break;
            case 4: dlldelete();
                    system("pause");
                    break;
            case 5: dllsearch();
                    system("pause");
                    break;
            case 6: dllprint();
                    system("pause");
                    break;
            case 7: return;
        }
    }
}


