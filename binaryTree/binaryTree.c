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


void inOrderTraverse(BiTree root)
{
    if(root == NULL)
        return;
    inOrderTraverse(root->lchild);
    printf("%d ", root->data);
    inOrderTraverse(root->rchild);
}

void postOrderTraverse(BiTree root)
{
    if(root == NULL)
        return;
    postOrderTraverse(root->lchild);
    postOrderTraverse(root->rchild);
    printf("%d ", root->data);
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

void inOrderTraverse_none_recursive(BiTree root)
{
    if(root == NULL)
        return;
    int top = 0;
    while(root || top>0)
    {
        while(root)
        {
            stack[top++] = root;
            root = root->lchild;
        }
        root = stack[--top];
        printf("%d ", root->data);
        root = root->rchild;
    }
    printf("\n");
}

void postOrderTraverse_none_recursive(BiTree root)
{
    if(root == NULL)
        return;
    BiTNode *visited = NULL;
    int top = 0;
    while(root || top>0)
    {
        while(root)
        {
            stack[top++] = root;
            root = root->lchild;
        }
        root = stack[top -1];
        //if do not have right child or the right child is visited, then visit the parent(root) node.
        if(root->rchild==NULL || visited==root->rchild)
        {
            printf("%d ", root->data);
            visited = root;
            --top;
            root = NULL;//note that: let the node become NULL
        }
        else
        {
            root = root->rchild;
        }
    }
    printf("\n");
}

void levelTraverse(BiTree root)
{
    if(root == NULL)
        return;
    BiTNode* p = NULL;
    int top = 0;
    int beg = 0;
    int end = 0;
    stack[top++] = root;
    while(top > beg)
    {
        beg = top - beg - 1;
        end = top;
        while(beg < end)
        {
            p = stack[beg++];
            printf("%d ", p->data);
            if(p->lchild)
                stack[top++] = p->lchild;
            if(p->rchild)
                stack[top++] = p->rchild;
        }
		beg = top;
    }
}

int main(void)
{

    printf("please input the data to create binary tree, input -1 to exit\n");
    BiTree root = createBiTree();
    printf("The binary tree is:\n");

    printf("The preOrderTraverse is:\n");
    preOrderTraverse(root);
    printf("\n");
    printf("The inOrderTraverse is:\n");
    inOrderTraverse(root);
    printf("\n");
    printf("The postOrderTraverse is:\n");
    postOrderTraverse(root);
    printf("\n");
    printf("The preOrderTraverse with none recursive is:\n");
    preOrderTraverse_none_recursive(root);
    printf("The inOrderTraverse with none recursive is:\n");
    inOrderTraverse_none_recursive(root);
    printf("The postOrderTraverse with none recursive is:\n");
    postOrderTraverse_none_recursive(root);
    printf("The level traverse for binary tree is:\n");
    levelTraverse(root);
    printf("\n");
    return 0;
}
