#include<stdio.h>
struct node
{
    int data;
    struct node* next;
}*head;
void llinsertb()
{
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
	struct node* temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
    {
        printf("Insufficient space");
        return;
    }
	temp->data=x;
	temp->next=head;
	head=temp;
}
void llinserte()
{
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        struct node*t=head;
        while(t->next!=NULL)
              t=t->next;
        t->next=temp;
    }
}
void llinsertn()
{
	int p,i;
	int x;
    printf("Enter data: ");
    scanf("%d",&x);
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	printf("Enter the position: ");
	scanf("%d",&p);
	if(p==1)
	{
		temp->next=head;
		head=temp;
		return;
	}
	struct node* temp1=head;
	for(i=0;i<p-2;i++)
	{
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}
struct node* llelemsearch(int x)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}
void lldelete()
{
    int x;
    printf("Enter data you want to delete: ");
    scanf("%d",&x);
	struct node* t=head;
    struct node* temp=llelemsearch(x);
    SetColor(11);
    if(temp==NULL)
        printf("Element not found\n");
    else
    {
        free(temp);
        printf("Element deleted successfully...\n");
    }
}
void llsearch()
{
	int i=1,flag=0;
	int x;
    printf("Enter data you want to search: ");
    scanf("%d",&x);
	struct node *temp=head;
	SetColor(11);
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			flag=1;
			printf("Position of the element is %d\n",i);
		}
		temp=temp->next;
		i++;
	}
	if(flag==0)
		printf("Element does not exist\n");
}
void llreverse()
{
	struct node* prev,*current,*next;
	prev=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
void llsort()
{
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data>temp->next->data)
        {

        }
    }
}
void llprint()
{
    SetColor(11);
	struct node* temp=head;
	printf("\nLinked list: ");
	while(temp!=NULL)
	{
	    printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n\n");
}
void linked_list()
{
    int c,n;
    while(1)
    {
        int i=0;
        system("cls");
        SetColor(11);
        printf("\t\t\t******LINKED LIST******\n\n\n");
        SetColor(7);
        printf("\t\t1.Insert in beginning\n");
        printf("\t\t2.Insert at end\n");
        printf("\t\t3.Insert in nth position\n");
        printf("\t\t4.Delete a node\n");
        printf("\t\t5.Reverse the links\n");
        printf("\t\t6.Search an element\n");
        printf("\t\t7.Display the list\n");
        printf("\t\t8.Sort the elements of list\n");
        printf("\t\t9.Go to main menu\n\n");
        printf("\t\tEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the no. of nodes: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        llinsertb();
                        i++;
                    }
                    llprint();
                    system("pause");
                    break;
            case 2: printf("\nEnter the no. of nodes: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        llinserte();
                        i++;
                    }
                    llprint();
                    system("pause");
                    break;
            case 3: llinsertn();
                    llprint();
                    system("pause");
                    break;
            case 4: lldelete();
                    system("pause");
                    break;
            case 5: llreverse();
                    llprint();
                    system("pause");
                    break;
            case 6: llsearch();
                    system("pause");
                    break;
            case 7: llprint();
                    system("pause");
                    break;
            case 8:
            case 9: return;
        }
    }
}

