
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100
#define STACK_INCREMENT 20
#define ERROR -1
#define MAX 100

int array[MAX];

typedef struct stack {
    int *base;
    int *top;
    int size;
}*sqStack;

sqStack init(void)
{
    //note that to malloc memory for s variable firstly before init s.
    sqStack s = (sqStack)malloc(sizeof(sqStack));
    s->base = (int *)malloc(STACK_SIZE * sizeof(int));
    if(s->base == NULL)
    {
        printf("memory allocated failure!\n");
        return;
    }
    s->top = s->base;
    s->size = STACK_SIZE;
    return s;
}

int top(sqStack s)
{
    if(s->top == s->base)
        return ERROR;
    return *(s->top-1);//do not use *(--s->top), as it will decrease s top point.
}

int pop(sqStack s)
{
    if(s->top == s->base)
        return ERROR;
    return *(--s->top);
}

int push(sqStack s, int value)
{
    if(s->top - s->base >= s->size)
    {
        s->base = (int *)realloc(s->base, (s->size + STACK_INCREMENT)*sizeof(int));
        if(s->base == NULL)
            return ERROR;
        s->top = s->base + s->size;
        s->size += STACK_INCREMENT;
    }
    *(s->top++) = value;
}

int getSize(sqStack s)
{
    return s->top - s->base;
}

int stackTest(void)
{
    sqStack s = init();
    int i=0, n=0, value=0, size=0, len=0;
    printf("please input the number to init the stack\n");
    scanf("%d", &n);
    printf("please input the elements:\n");
    while(n-->0)
    {
        scanf("%d", &value);
        push(s, value);
    }
    len = size = getSize(s);
    printf("size is:%d\n", size);
    while(size-- > 0)
    {
        array[size] = pop(s);
    }
    printf("the stack you input are:\n");
    for(i=0; i<len; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(void)
{
    stackTest();
    return 0;
}
