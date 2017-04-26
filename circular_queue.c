#define MAX 20
int front1=-1;
int rear1=-1;
int queue[MAX];
int CQueueisFull()
{
    if(front1==rear1+1||front1==0&&rear1==MAX-1)
        return 1;
    else
        return 0;
}
int CQueueisEmpty()
{
    if(front1==-1)
        return 1;
    else
        return 0;
}
void Cenqueue(int x)
{
    if(CQueueisFull())
    {
        SetColor(11);
        printf("Queue is Full\n");
        return;
    }
    if(front1==-1)
        front1=0;
    if(rear1==MAX-1)
        rear1=-1;
    queue[++rear1]=x;
}
int Cdequeue()
{
    int item;
    if(CQueueisEmpty())
    {
        SetColor(11);
        printf("Queue is empty\n");
        return;
    }
    item=queue[front1];
    if(front1==rear1)
    {
        front1=-1;
        rear1=-1;
        return item;
    }
    if(front1==MAX-1)
        front1=-1;
    front1++;
    return item;
}
void Cdisplay()
{
    SetColor(11);
    int i=0;
    printf("\nCircular queue: ");
	for(i=front1;i<=rear1;i++)
		printf("%d ",queue[i]);
	if(front1>rear1)
	{
		for(i=0;i<rear1+1;i++)
			printf("%d ",queue[i]);
		for(i=front1;i<MAX;i++)
			printf("%d ",queue[i]);
	}
    printf("\n\n");
}
void circular_queue()
{
    int c,x,n;
    while(1)
    {
        int i=0;
        system("cls");
        SetColor(11);
        printf("\t\t\t******CIRCULAR QUEUE******\n\n\n");
        SetColor(7);
        printf("\t\t1.Insert an item\n");
        printf("\t\t2.Delete an item\n");
        printf("\t\t3.Display the queue\n");
        printf("\t\t4.Go to main menu\n\n");
        printf("\t\tEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the no. of values: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        printf("Enter the value: ");
                        scanf("%d",&x);
                        Cenqueue(x);
                        i++;
                    }
                    Cdisplay();
                    system("pause");
                    break;
            case 2: x=Cdequeue();
                    SetColor(11);
                    printf("%d deleted successfully\n",x);
                    system("pause");
                    break;
            case 3: Cdisplay();
                    system("pause");
                    break;
            case 4: return;
        }
    }
}

