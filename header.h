#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void llinsertb();
void llinserte();
void llinsertn();
struct node* llelemsearch(int x);
void lldelete();        //linked list
void llsearch();
void llreverse();
void llprint();
void linked_list();

void dllinsertb();
void dllinserte();
void dllinsertn();
void dlldelete();       //doubly linked list
void dllsearch();
void dllprint();
void double_linked_list();

struct node* cllcreate();
void cllinsertb();
void cllinserte();
void cllinsertn();      //circular linked list
void clldelete();
void cllprint();
void circular_linked_list();

int StackisFull();
int StackisEmpty();     //stack
int pop();
void push(int);
void Stack();

int QueueisFull();
int QueueisEmpty();
void enqueue_queue(int x);    //queue
int dequeue_queue();
void queue_display();
void Queue();

int DequeisFull();
int DequeisEmpty();
void enqueue_from_rear2(int x);      //deque
void enqueue_from_front2(int x);
int dequeue_from_front2();
int dequeue_from_rear2();
void deque();

int CQueueisFull();
int CQueueisEmpty();       //circular queue
void Cenqueue(int x);
int Cdequeue();
void circular_queue();

int pqisempty();
int pqisfull();
void pqenqueue(int x);     //priority queue
int pqdequeue();
void pqdisplay();
void priority_queue();

int height(struct bst*);
void successor(struct bst*);
struct bst* inorder(struct bst*);
struct bst* preorder(struct bst*);
struct bst* postorder(struct bst*);
int findmin(struct bst* );                  //bst tree
struct bst* create(int);
struct bst* insert(struct bst*,int);
struct bst* search(struct bst*,int);
struct bst* delete(struct bst*,int);
void ancestor(int,struct bst*);
void bst_tree();
