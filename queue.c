#define MAX 20
int queue[MAX];
int Front=-1;
int Rear=-1;
int QueueisFull()
{
    if(Rear==MAX-1)
        return 1;
    else
        return 0;
}
int QueueisEmpty()
{
    if(Front==-1)
        return 1;
    else
        return 0;
}
void enqueue_queue(int x)
{
    if(QueueisFull())
    {
        SetColor(11);
        printf("Queue is Full\n");
        return;
    }
    if(Front==-1)
        Front=0;
    queue[++Rear]=x;
}
int dequeue_queue()
{
    int item;
    if(QueueisEmpty())
    {
        SetColor(11);
        printf("Queue is empty\n");
        return;
    }
    item=queue[Front];
    Front++;
    return item;
}
void queue_display()
{
    SetColor(11);
	int i=0;
	printf("\nQueue: ");
	for(i=Front;i<=Rear;i++)
		printf("%d ",queue[i]);
    printf("\n\n");
}
void Queue()
{
    int c,x,n;
    while(1)
    {
        int i=0;
        SetColor(11);
        system("cls");
        SetColor(7);
        printf("\t\t\t******QUEUE******\n\n\n");
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
                        enqueue_queue(x);
                        i++;
                    }
                    queue_display();
                    system("pause");
                    break;
            case 2: x=dequeue_queue();
                    SetColor(11);
                    printf("%d deleted successfully\n",x);
                    system("pause");
                    break;
            case 3: queue_display();
                    system("pause");
                    break;
            case 4: return;
        }
    }
}

