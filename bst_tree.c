#include<stdio.h>
struct bst
{
    int data;
    struct bst* lchild;
    struct bst* rchild;
};
int height(struct bst* t)
{
    SetColor(11);
    int hleft,hright;
    if(t==NULL)
        return 0;
    hleft=height(t->lchild);
    hright=height(t->rchild);
    if(hleft>hright)
        return 1+hleft;
    else
        return 1+hright;
}
void successor(struct bst* t)
{
    SetColor(11);
    struct bst* p=t;
    t=t->rchild;
    while(t->lchild!=NULL)
        t=t->lchild;
    printf("Successor is %d",t->data);
    p=p->lchild;
    while(p->rchild!=NULL)
        p=p->rchild;
    printf("\nPredecessor is %d\n\n",p->data);
}
struct bst* inorder(struct bst* t)
{
    if(t==NULL)
        return t;
    t->lchild=inorder(t->lchild);
    printf("%d ",t->data);
    t->rchild=inorder(t->rchild);
}
struct bst* preorder(struct bst* t)
{
    if(t==NULL)
        return t;
    printf("%d ",t->data);
    t->lchild=preorder(t->lchild);
    t->rchild=preorder(t->rchild);
}
int findmin(struct bst* t)
{
    while(t->lchild!=NULL)
        t=t->lchild;
    return t->data;
}
struct bst* postorder(struct bst* t)
{
    if(t==NULL)
        return t;
    t->lchild=postorder(t->lchild);
    t->rchild=postorder(t->rchild);
    printf("%d ",t->data);
}
struct bst* create(int x)
{
    struct bst* temp=(struct bst*)malloc(sizeof(struct bst));
    temp->data=x;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
};
struct bst* insert(struct bst* t,int x)
{
    if(t==NULL)
    {
        t=create(x);
        return t;
    }
    if(x<t->data)
        t->lchild=insert(t->lchild,x);
    else if(x>t->data)
        t->rchild=insert(t->rchild,x);
    return t;
}
struct bst* search(struct bst* t,int x)
{
    SetColor(11);
    if(t==NULL)
        return NULL;
    else if(t->data==x)
        return t;
    else if(x<t->data)
        search(t->lchild,x);
    else if(x>t->data)
        search(t->rchild,x);
}
struct bst* delete(struct bst* t,int x)
{
    SetColor(11);
    int data;
    if(t==NULL)
        return;
    else if(x<t->data)
        t->lchild=delete(t->lchild,x);
    else if(x>t->data)
        t->rchild=delete(t->lchild,x);
    else
    {
        if(t->lchild==NULL&&t->rchild==NULL)
        {
            printf("Node deleted successfully\n\n");
            return NULL;
        }
        else if(t->lchild==NULL)
        {
            printf("Node deleted successfully\n\n");
            return t->rchild;
        }
        else if(t->rchild==NULL)
        {
            printf("Node deleted successfully\n\n");
            return t->lchild;
        }
        else
        {
            data=findmin(t->rchild);
            t->data=data;
            t->rchild=delete(t->rchild,t->data);
        }
    }
    return t;
}
void ancestor(int x,struct bst *t)
{
    SetColor(11);
    int flag=0;
    printf("Ancestors are ");
    if(t==NULL)
    {
        printf("No element in the tree");
        return;
    }
    while(x!=t->data)
    {
        printf("%d ",t->data);
        if(x<t->data)
            t=t->lchild;
        else if(x>t->data)
            t=t->rchild;
    }
    if(t->lchild!=NULL&&t->rchild!=NULL)
        printf("\nDescendants are %d and %d\n\n",t->lchild->data,t->rchild->data);
    else if(t->lchild==NULL&&t->rchild!=NULL)
        printf("\nDescendant is %d\n\n",t->rchild->data);
    else if(t->lchild!=NULL&&t->rchild==NULL)
        printf("\nDescendant is %d\n\n",t->lchild->data);
    else
        printf("\nNo descendants\n\n");
}
void bst_tree()
{
    struct bst *root=NULL;
    struct bst* t;
    int c,x;
    while(1)
    {
        int i=0,n;
        system("cls");
        SetColor(11);
        printf("\t\t\t******BINARY SEARCH TREE******\n\n\n");
        SetColor(7);
        printf("\t\t1.Insert a node\n");
        printf("\t\t2.Search a node\n");
        printf("\t\t3.Pre-order display\n");
        printf("\t\t4.In-order display\n");
        printf("\t\t5.Post-order display\n");
        printf("\t\t6.Delete a node\n");
        printf("\t\t7.Height of tree\n");
        printf("\t\t8.Ancestor and Descendant of a node\n");
        printf("\t\t9.Successor and Predecessor of a node\n");
        printf("\t\t10.Exit\n\n");
        printf("\t\tEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("\nEnter the no. of values: ");
                    scanf("%d",&n);
                    while(i<n)
                    {
                        printf("Enter the value: ");
                        scanf("%d",&x);
                        root=insert(root,x);
                        i++;
                    }
                    SetColor(11);
                    printf("\nIN-ORDER DISPLAY OF TREE:\n");
                    root=inorder(root);
                    printf("\n\n");
                    system("pause");
                    break;
            case 2:printf("\nEnter the value you want to search: ");
                    scanf("%d",&x);
                    t=search(root,x);
                    if(t==NULL)
                        printf("NOT FOUND\n\n");
                    else
                        printf("FOUND\n\n");
                    system("pause");
                    break;
            case 3:SetColor(11);
                    printf("\nPRE-ORDER DISPLAY OF TREE:\n");
                    root=preorder(root);
                    printf("\n\n");
                    system("pause");
                    break;
            case 4:SetColor(11);
                    printf("\nIN-ORDER DISPLAY OF TREE:\n");
                    root=inorder(root);
                    printf("\n\n");
                    system("pause");
                    break;
            case 5:SetColor(11);
                    printf("\nPOST-ORDER DISPLAY OF TREE:\n");
                    root=postorder(root);
                    printf("\n\n");
                    system("pause");
                    break;
            case 6:printf("\nEnter the value you want to delete: ");
                    scanf("%d",&x);
                    root=delete(root,x);
                    system("pause");
                    break;
            case 7: x=height(root);
                    printf("\n\nHeight of tree is %d\n\n",x);
                    system("pause");
                    break;
            case 8: printf("\nEnter the node value: ");
                    scanf("%d",&x);
                    ancestor(x,root);
                    system("pause");
                    break;
            case 9: printf("\nEnter the node value: ");
                    scanf("%d",&x);
                    t=search(root,x);
                    successor(t);
                    system("pause");
                    break;
            case 10: exit(1);
        }
    }
}
