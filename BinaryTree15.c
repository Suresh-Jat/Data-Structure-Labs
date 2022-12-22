// Implement Binary Search Tree using linked list and perform following operations
// 1. Insert new element
// 2. Delete given element
// 3. Display Inorder

#include <stdio.h>
#include <malloc.h>

struct node
{
    int keyValue;
    struct node *left;
    struct node *right;
};

struct node *rootNode, *newnode, *parentNode, *nodePtr, *temp;

void insert(int num)
{
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Something went wrong!");
    }
    else
    {
        newnode->keyValue = num;
        newnode->left = NULL;
        newnode->right = NULL;
        if (rootNode == NULL)
        {
            rootNode = newnode;
            rootNode->left = NULL;
            rootNode->right = NULL;
        }
        else
        {
            parentNode = NULL;
            nodePtr = rootNode;
            while (nodePtr != NULL)
            {
                parentNode = nodePtr;
                if (num < nodePtr->keyValue)
                {
                    nodePtr = nodePtr->left;
                }
                else
                {
                    nodePtr = nodePtr->right;
                }
            }
            if (num < parentNode->keyValue)
            {
                parentNode->left = newnode;
            }
            else
            {
                parentNode->right = newnode;
            }
        }
        printf("\n%d Inserted ",num);
    }
}

void case_a(struct node *parentNode, struct node *delnode)
{
    if (parentNode == NULL)
    {
        rootNode = NULL;
    }
    else if (parentNode->left == delnode)
    {
        parentNode->left = NULL;
    }
    else
    {
        parentNode->right = NULL;
    }
    free(delnode);
}

void case_b(struct node *parentNode, struct node *delnode)
{
    struct node *child;
    if (delnode->left != NULL)
    {
        child = delnode->left;
    }
    else
    {
        child = delnode->right;
    }

    if (parentNode == NULL)
    {
        rootNode = child;
    }
    else if (parentNode->left == delnode)
    {
        parentNode->left = child;
    }
    else
    {
        parentNode->right = child;
    }
    free(delnode);
}

void case_c(struct node *parentNode, struct node *delnode)
{
    struct node *succ, *parsucc;
    parsucc = delnode;
    succ = delnode->right;
    while (succ->left != NULL)
    {
        parsucc = succ;
        succ = succ->left;
    }
    delnode->keyValue = succ->keyValue;

    if (succ->left == NULL && succ->right == NULL)
    {
        case_a(parsucc, succ);
    }
    else
    {
        case_b(parsucc, succ);
    }
}

void del(int value)
{
    temp = rootNode;
    parentNode = NULL;
    while (temp != NULL)
    {
        if (value == temp->keyValue)
        {
            break;
        }
        parentNode = temp;
        if (value < temp->keyValue)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        printf("Key is not Present in Tree\n");
    }
    else if (temp->left != NULL && temp->right != NULL)
    {
        case_c(parentNode, temp);
    }
    else if (temp->left != NULL)
    {
        case_b(parentNode, temp);
    }
    else if (temp->right != NULL)
    {
        case_b(parentNode, temp);
    }
    else
    {
        case_a(parentNode, temp);
    }
    printf("\n%d is Deleted \n",value);
}

void inOrder(struct node *rootNode)
{
    if (rootNode != NULL)
    {
        inOrder(rootNode->left);
        printf("%d ", rootNode->keyValue);
        inOrder(rootNode->right);
    }
}

int main()
{
    int n, item, delitem;
    while (1)
    {
        printf("\n\n++++++++++++++++++++++++++++++++++\n");
        printf("\n1: Insert \n2: Delete  \n3: Display \n4: Exit\nEnter Your Option:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter the Item to Insert : ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            printf("\nEnter the Item to Delete : ");
            scanf("%d", &delitem);
            del(delitem);
            break;
        case 3:
            printf("\n++++++++++++DISPLAY++++++++++++\n");
            printf("\nInOrder Representation: ");
            inOrder(rootNode);
            printf("\n");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}
