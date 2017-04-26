#include<stdio.h>
#define MAX 20
int top=-1;
int stack[MAX];
int StackisFull()
{
    if(top==MAX)
        return 1;
    else
        return 0;
}
int StackisEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int x)
{
    if(StackisFull())
    {
        SetColor(11);
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=x;
}
int pop()
{
    int item;
    if(StackisEmpty())
    {
        SetColor(11);
        printf("Stack underflow\n");
        return 0;
    }
    item=stack[top];
    top--;
    return item;
}
void display()
{
    SetColor(11);
    int i;
    printf("\nStack: \n");
    for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
    printf("\n");
}
void Stack()
{
    int c,x,n;
    while(1)
    {
        int i=0;
        system("cls");
        SetColor(11);
        printf("\t\t\t******STACK******\n\n\n");
        SetColor(7);
        printf("\t\t1.Push an item\n");
        printf("\t\t2.Pop an item\n");
        printf("\t\t3.Display the stack\n");
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
                        push(x);
                        i++;
                    }
                    display();
                    system("pause");
                    break;
            case 2: x=pop();
                    SetColor(11);
                    printf("%d deleted successfully\n",x);
                    system("pause");
                    break;
            case 3: display();
                    system("pause");
                    break;
            case 4: return;
        }
    }
}

