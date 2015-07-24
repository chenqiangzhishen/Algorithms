#include <stdio.h>
#include <stdlib.h>

typedef struct linkList {
    int data;
    struct linkList *next;
} Node;

Node* create(void)
{
    int data = 0;
    int n=0;
    Node* pre = NULL;
    printf("please input the numbers of nodes\n");
    scanf("%d", &n);
    while(n <= 0)
    {
        printf("please input the numbers > 0\n");
        scanf("%d", &n);
    }

    printf("please input the data\n");
    scanf("%d", &data);
    Node* head = (Node* )malloc(sizeof(struct linkList));
    head->data = data;
    pre = head;
    --n;
    while(n--)
    {
        printf("please input the data\n");
        scanf("%d", &data);
        Node* next = (Node* )malloc(sizeof(struct linkList));
        next->data = data;
        pre->next = next;
        pre = next;
    }
    return head;
}
/*
 * method 1.
Node* reverse(Node* head)
{
	if(head == NULL)
		return NULL;
	Node* pNode = head;
	Node* pPre  = NULL;
	Node* pNext = NULL;
	while(pNode->next)
	{
		pNext = pNode->next;
		pNode->next = pPre;
		pPre = pNode;
		pNode = pNext;
	}
	pNode->next = pPre;
	return pNode;
}
*/

//method 2.
Node* reverse(Node* head)
{
    if(head == NULL)
        return NULL;
    Node* pNode = head;
    Node* pPre  = NULL;
    Node* pNext = NULL;
    while(pNode)
    {
        pNext = pNode->next;
        pNode->next = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return pPre;
}

void print(Node* head)
{
    if(head == NULL)
        return;
    Node* node = head;
    while(node)
    {
        if(node->next)
        {
            printf("%d->", node->data);
        }
        else
        {
            printf("%d\n", node->data);
        }
        node = node->next;
    }
}

int main(void)
{
    Node* head = create();
    printf("the order is \n");
    print(head);
    head = reverse(head);
    printf("the reverse order is \n");
    print(head);

    return 0;
}


















