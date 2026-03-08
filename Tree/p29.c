// cprogram to create a binary tree and perform inorder, preorder and postorder traversals
#include <stdio.h>
#define max 100
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}tree;
int main()
{
    int size;
    int arr[max];
    printf("This program is for binary tree implementation.\n");
    printf("Enter the size of the tree: ");
    scanf("%d", &size);
    printf("Enter the elements of the tree: ");
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    return 0;
}