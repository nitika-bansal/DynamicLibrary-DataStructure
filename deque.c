#define MAX 20
int front2=-1;
int rear2=-1;
int queue[MAX];
int DequeisFull()
{
    if(front2==rear2+1||front2==0&&rear2==MAX-1)
        return 1;
    else
        return 0;
}
int DequeisEmpty()
{
    if(front2==-1)
        return 1;
    else
        return 0;
}
void enqueue_from_rear2(int x)
{
    if(DequeisFull())
    {
        SetColor(11);
        printf("Queue is Full\n");
        return;
    }
    if(front2==-1)
        front2=0;
    queue[++rear2]=x;
}
void enqueue_from_front2(int x)
{
    if(DequeisFull())
    {
        SetColor(11);
        printf("Queue is Full\n");
        return;
    }
    if(front2==-1)
	{
		rear2++;
		queue[++front2]=x;
	}
	else if(front2==0)
	{
		front2=MAX-1;
		queue[front2]=x;
	}
	else
		queue[--front2]=x;
}
int dequeue_from_front2()
{
    int item;
    if(DequeisEmpty())
    {
        SetColor(11);
        printf("Queue is empty\n");
        return;
    }
    if(front2==rear2)
    {
        item=queue[front2];
        front2=-1;
        rear2=-1;
        return item;
    }
    item=queue[front2];
    front2++;
    return item;
}
int dequeue_from_rear2()
{
    int item;
    if(DequeisEmpty())
    {
        SetColor(11);
        printf("Queue is empty\n");
        return;
    }
    if(front2==rear2)
    {
        item=queue[front2];
        front2=-1;
        rear2=-1;
        return item;
    }
    item=queue[rear2];
    rear2--;
    return item;
}
void deque_display()
{
    SetColor(11);
    int i=0;
    printf("\nDeque: ");
	if(front2>rear2)
	{
		for(i=front2;i<MAX;i++)
			printf("%d ",queue[i]);
		for(i=0;i<rear2+1;i++)
			printf("%d ",queue[i]);
	}
	else
	{
		for(i=front2;i<rear2+1;i++)
			printf("%d ",queue[i]);
	}
    printf("\n\n");
}
void deque()
{
    int c,x,n;
    while(1)
    {
        int i=0;
        system("cls");
        SetColor(11);
        printf("\t\t\t******DEQUEUE******\n\n\n");
        SetColor(7);
        printf("\t\t1.Insert item from front end\n");
        printf("\t\t2.Insert item from rear end\n");
        printf("\t\t3.Delete item from front end\n");
        printf("\t\t4.Delete item from rear end\n");
        printf("\t\t5.Display the queue\n");
        printf("\t\t6.Go to main menu\n\n");
        printf("\t\tEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the no. of values: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        printf("Enter the value: ");
                        scanf("%d",&x);
                        enqueue_from_front2(x);
                        i++;
                    }
                    deque_display();
                    system("pause");
                    break;
            case 2: printf("\nEnter the no. of values: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        printf("Enter the value: ");
                        scanf("%d",&x);
                        enqueue_from_rear2(x);
                        i++;
                    }
                    deque_display();
                    system("pause");
                    break;
            case 3: x=dequeue_from_front2();
                    SetColor(11);
                    printf("%d deleted successfully\n",x);
                    system("pause");
                    break;
            case 4: x=dequeue_from_rear2();
                    SetColor(11);
                    printf("%d deleted successfully\n",x);
                    system("pause");
                    break;
            case 5: deque_display();
                    system("pause");
                    break;
            case 6: return;
        }
    }
}
