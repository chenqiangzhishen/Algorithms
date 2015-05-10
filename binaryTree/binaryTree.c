#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTNode* stack[MAX];

BiTree createBiTree(void)
{
    int data;
    BiTNode *root = NULL;
    scanf("%d", &data);

    if(data == -1)
    {
        root = NULL;
    }
    else
    {
        root = (BiTNode *)malloc(sizeof(BiTNode));
        root->data = data;
        root->lchild = createBiTree();
        root->rchild = createBiTree();
    }
    return root;
}

void preOrderTraverse(BiTree root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrderTraverse(root->lchild);
    preOrderTraverse(root->rchild);
}

void preOrderTraverse_none_recursive(BiTree root)
{
    if(root == NULL)
        return;
    int top = 0;
    while(root || top>0)
    {
        while(root)
        {
            printf("%d ", root->data);
            stack[top++] = root;
            root = root->lchild;
        }
        root = stack[--top];
        root = root->rchild;
    }
    printf("\n");
}

int main(void)
{
    printf("please input the data to create binary tree, input -1 to exit\n");
    BiTree root = createBiTree();
    printf("The binary tree is:\n");
    //preOrderTraverse(root);
    preOrderTraverse_none_recursive(root);
    return 0;
}
