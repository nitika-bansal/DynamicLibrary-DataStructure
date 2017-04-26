#include"header.h"
#include<windows.h>
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
int main()
{
    int c=9;
    while(1)
    {
        system("cls");
        SetColor(11);
        printf("\t\t\t******DATA STRUCTURES******\n\n\n");
        SetColor(7);
        printf("\t\t1.Linked list\n");
        printf("\t\t2.Doubly Linked List\n");
        printf("\t\t3.Circular Linked List\n");
        printf("\t\t4.Stack\n");
        printf("\t\t5.Queue\n");
        printf("\t\t6.Deque\n");
        printf("\t\t7.Circular Queue\n");
        printf("\t\t8.Priority Queue\n");
        printf("\t\t9.Binary Search Tree\n");
        printf("\t\t10.Exit\n\n");
        printf("\t\tEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:linked_list();
                    break;
            case 2:double_linked_list();
                    break;
            case 3:circular_linked_list();
                    break;
            case 4:Stack();
                    break;
            case 5:Queue();
                    break;
            case 6:deque();
                    break;
            case 7:circular_queue();
                    break;
            case 8:priority_queue();
                    break;
            case 9:bst_tree();
                    break;
            case 10:exit(1);
        }
    }
    return 0;
}

