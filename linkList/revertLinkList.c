#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList {
    int data;
    struct LinkList *next;
} Node;

Node* createLinkList(int n)
{
    if(n <= 0)
    {
        printf("Please input the number of Node bigger than 0\n");
        return;
    }
    Node *head=NULL, *pre=NULL, *behind=NULL;
    head=(Node *)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("Allocated memory error\n");
        return;
    }
    head->next = NULL;
    pre = head;
    printf("Please input the data\n");
    while(n-- >0)
    {
        behind = (Node*)malloc(sizeof(Node));
        if(behind != NULL)
        {
            scanf("%d", &behind->data);
            pre->next = behind;
            pre = behind;
        }
    }
    behind->next=NULL;
    return head;
}

void printLinkList(Node *head)
{
    if(head == NULL)
        return;
    Node *temp = head->next;
    while(temp)
    {
        if(temp->next)
        {
            printf("%d->",temp->data);
        } else {
            printf("%d\n", temp->data);
        }
        temp = temp->next;
    }
}
//LinkList with head node.
Node* reverseLinkList(Node *head)
{
    if(!head || !head->next)
        return;
    Node *p=NULL, *q=NULL, *r=NULL;
    p = head->next;
    q = p->next;
    p->next = NULL;//the last node ends with NULL
    while(q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next = p;
    return head;
}

int main(void)
{
    int n=0;

    printf("Input the number of Node you want to create\n");
    scanf("%d", &n);
    Node * linkList = createLinkList(n);
    printf("The origin LinkList is:\n");
    printLinkList(linkList);
    printf("The LinkList after reversing is:\n");
    printLinkList(reverseLinkList(linkList));

    return 0;
}
