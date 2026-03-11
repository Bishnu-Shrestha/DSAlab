// cprogram to create a binary tree using dynamic memory allocation and perform inorder, preorder and postorder traversals
#include <stdio.h>
#include <stdlib.h> 
#define max 100
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}tree;
tree *root=NULL;
tree* createNode(int data)
{
    tree *newNode = (tree*)malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}   
int main()
{
    printf("This program is for binary tree implementation.\n");
        tree *root = NULL;
        int choice, value;
        while (1)
        {
            printf("1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    printf("Enter the value to insert: ");
                    scanf("%d", &value);
                    createNode(value);
                    break;
                case 2:

                    // Call the inorder traversal function here
                    break;
                case 3:
                    // Call the preorder traversal function here
                    break;
                case 4:
                    // Call the postorder traversal function here
                    break;
                case 5:
                    exit(0);
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
    return 0;
}
tree* insertNode(tree* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}
