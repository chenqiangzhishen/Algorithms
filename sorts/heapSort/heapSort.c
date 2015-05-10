#include <stdio.h>

void adjustHeap(int data[], int beg, int end)
{
    if(data==NULL || beg>=end)
        return;
    int i=0;
    int temp = data[beg];
    for(i=2*beg+1; i<=end; i*=2)//note the index
    {
        if(i+1<=end && data[i]<data[i+1])//if right child bigger than left, then point to right child.
            ++i;
        if(temp >= data[i])//if parent bigger than childen, keep bigger.
            break;
        data[beg] = data[i];//exchange value for child and parent.
        beg = i;
    }
    data[beg] = temp;//insert the original parent data
}

void heapSort(int data[], int length)
{
    if(data==NULL || length<=0)
        return;
    int i=0;
    for(i=length/2-1; i>=0; --i)
    {
        adjustHeap(data, i, length-1);
    }
    for(i=length-1; i>0; --i)
    {
        data[i] ^= data[0];
        data[0] ^= data[i];
        data[i] ^= data[0];
        adjustHeap(data, 0, i-1);
    }
}

int main(void)
{
    int i = 0;
	int data[] = {1,7, 4, 6, 3, 5, 2};
    int length = sizeof(data)/sizeof(data[0]);
    printf("before sorting the data is :");
    for(i=0; i<length; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("after sorting the data is  :");
    heapSort(data, length);
    for(i=0; i<length; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}


