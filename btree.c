#include <stdio.h>
#include <stdlib.h>

enum boolean
{
    false,
    true
};

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;

Node *createnode(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void infix(Node* r)
{
    if(r==NULL)
    {
        return;
    }
    infix(r->left);
    printf("%d ",r->data);
    infix(r->right);
}
void postfix(Node* r)
{
    if(r==NULL)
    {
        return;
    }
    infix(r->left);
    infix(r->right);
    printf("%d ",r->data);
}
void prefix(Node* r)
{
    if(r==NULL)
    {
        return;
    }
    printf("%d ",r->data);
    infix(r->left);
    infix(r->right);
}

void insert(int data)
{
    Node* newnode=createnode(data);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    Node* temp= root;
    while(temp!=NULL)
    {
        if(data<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=newnode;
                return;
            }
            else
            {
                temp=temp->left;
            }
        }
        else
        {
            if(temp->right==NULL)
            {
                temp->right=newnode;
                return;
            }
            else
            {
                temp=temp->right;
            }
        }
    }
}

int main()
{   int choice,val;
    while(true)
    {
        printf("Menu\n1. Insert\n2. Display Prefix\n3. Display Infix\n4. Display Postfix\n5. Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter value to insert : ");
            scanf("%d",&val);
            insert(val);
            break;
            case 2:
            prefix(root);
            printf("\n");
            break;
            case 3:
            infix(root);
            printf("\n");
            break;
            case 4:
            postfix(root);
            printf("\n");
            break;
            case 5:
            printf("End of Program\n");
            return 0;
            default:
            printf("Invalid input");
        }
    }
    return 0;
}