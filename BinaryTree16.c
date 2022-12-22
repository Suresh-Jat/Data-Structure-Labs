// Create a binary tree and display Inorder, Preorder and Postorder traversal.
#include <stdio.h>
#include <stdlib.h>
void insert(int);

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;

void insert(int item)
{
    struct node *ptr, *parentptr, *nodeptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Can't insert");
    }
    else
    {
        ptr->data = item;
        ptr->left = NULL;
        ptr->right = NULL;
        if (root == NULL)
        {
            root = ptr;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            parentptr = NULL;
            nodeptr = root;
            while (nodeptr != NULL)
            {
                parentptr = nodeptr;
                if (item < nodeptr->data)
                {
                    nodeptr = nodeptr->left;
                }
                else
                {
                    nodeptr = nodeptr->right;
                }
            }
            if (item < parentptr->data)
            {
                parentptr->left = ptr;
            }
            else
            {
                parentptr->right = ptr;
            }
        }
        printf("\n%d Inserted ",item);
    }
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    int n, item, delitem;
    while (1)
    {
        printf("\n\n+++++++++++++++++++++++++++++++++++");
        printf("\n1: Insert \n2: Display \n3: Exit\nEnter Your Option:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter the Item to Insert : ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            printf("\n++++++++++++DISPLAY++++++++++++\n");
            printf("\n\nIn Order: ");
            inOrder(root);
            printf("\n\nPre Order: ");
            preOrder(root);
            printf("\n\nPost Order: ");
            postOrder(root);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}
