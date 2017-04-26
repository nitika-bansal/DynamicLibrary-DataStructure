#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* next;
}*last;
struct node* cllcreate()
{
    int x;
    struct node *t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&x);
    t->data=x;
    t->next=NULL;
    return t;
}
void cllinsertb()
{
    struct node* t=cllcreate();
    if(last==NULL)
    {
        last=t;
        last->next=last;
        return;
    }
    struct node *p=last->next;
    t->next=p;
    last->next=t;
}
void cllinserte()
{
    struct node* t=cllcreate();
    t->next=last->next;
    last->next=t;
    last=t;
}
void cllinsertn()
{
    int n,i;
    struct node* t=cllcreate();
    struct node* p=last->next;
    printf("Enter the position: ");
    scanf("%d",&n);
    if(n==1)
	{
		t->next=last;
		last=t;
		return;
	}
    for(i=0;i<n-2;i++)
		p=p->next;
    t->next=p->next;
    p->next=t;
}
void clldelete()
{
    int item;
    struct node *t;
    printf("Enter the data you want to delete: ");
    SetColor(11);
    scanf("%d",&item);
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(last->next==last && last->data==item)
    {
        t=last;
        last=NULL;
        free(t);
        printf("Element deleted successfully...\n");
        return;
    }
    struct node *p=last->next;
    if(p->data==item)
    {
        struct node *t=p;
        last->next=t->next;
        free(t);
        printf("Element deleted successfully...\n");
        return;
    }
    while(p->next!=last)
    {
        if(p->next->data==item)
        {
            struct node *t=p->next;
            p->next=t->next;
            free(t);
            printf("Element deleted successfully...\n");
            return;
        }
        p=p->next;
    }
    if(last->data==item)
    {
        struct node *t=last;
        p->next=last->next;
        last=p;
        free(t);
        printf("Element deleted successfully...\n");
        return;
    }
    printf("Element not found\n");
}
void cllprint()
{
    SetColor(11);
    struct node *p=last->next;
    printf("\nCircular linked list: ");
    do
    {
        printf("%d-> ",p->data);
        p=p->next;
    }while(p!=last->next);
    printf("\n\n");
}
void circular_linked_list()
{
    int c,n;
    while(1)
    {
        int i=0;
        system("cls");
        SetColor(11);
        printf("\t\t\t******CIRCULAR LINKED LIST******\n\n\n");
        SetColor(7);
        printf("\t\t1.Insert in beginning\n");
        printf("\t\t2.Insert at end\n");
        printf("\t\t3.Insert in nth position\n");
        printf("\t\t4.Delete a node\n");
        printf("\t\t5.Display the list\n");
        printf("\t\t6.Go to main menu\n\n");
        printf("\t\tEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the no. of nodes: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        cllinsertb();
                        i++;
                    }
                    cllprint();
                    system("pause");
                    break;
            case 2: printf("\nEnter the no. of nodes: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        cllinserte();
                        i++;
                    }
                    cllprint();
                    system("pause");
                    break;
            case 3: cllinsertn();
                    cllprint();
                    system("pause");
                    break;
            case 4: clldelete();
                    system("pause");
                    break;
            case 5: cllprint();
                    system("pause");
                    break;
            case 6: return;
        }
    }
}

