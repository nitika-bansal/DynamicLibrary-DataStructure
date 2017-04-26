#define MAX 10
int front=-1;
int rear=-1;
int queue[MAX];
int pqisempty()
{
	if(front==-1||front==rear+1)
		return 1;
	else
		return 0;
}
int pqisfull()
{
	if(front==0&&rear==MAX-1)
		return 1;
	else
		return 0;
}
void pqenqueue(int x)
{
	if(pqisfull())
    {
        SetColor(11);
        printf("Queue Overflow\n");
        return;
    }
	if(front=-1)
        front++;
    queue[++rear]=x;
}
int pqdequeue()
{
    int i,temp,min=queue[front],j=front;
    if(pqisempty())
    {
        SetColor(11);
        printf("Queue Underflow\n");
        return;
    }
    for(i=(front+1);i<=rear;i++)
    {
        if(min>queue[i])
        {
             min=queue[i];
             j=i;
        }
    }
    temp=queue[j];
    queue[j]=queue[front];
    queue[front]=temp;
    front++;
    return min;
}
void pqdisplay()
{
    SetColor(11);
	int i=0;
	printf("\nPriority queue: ");
	for(i=front;i<=rear;i++)
		printf("%d ",queue[i]);
    printf("\n\n");
}

void priority_queue()
{
    int c,x,n;
    while(1)
    {
        int i=0;
        system("cls");
        SetColor(11);
        printf("\t\t\t******PRIORITY QUEUE******\n\n\n");
        SetColor(7);
        printf("\t\t1.Insert an item\n");
        printf("\t\t2.Delete an item\n");
        printf("\t\t3.Display the queue\n");
        printf("\t\t4.Go to main menu\n\n");
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
                        pqenqueue(x);
                        i++;
                    }
                    pqdisplay();
                    system("pause");
                    break;
            case 2: x=pqdequeue();
                    SetColor(11);
                    printf("\n%d deleted successfully\n\n",x);
                    system("pause");
                    break;
            case 3: pqdisplay();
                    system("pause");
                    break;
            case 4: return;
        }
    }
}

