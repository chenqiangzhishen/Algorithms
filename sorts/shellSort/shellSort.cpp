#include <iostream>
using namespace std;

//一般的初次取序列的一半为增量，以后每次减半，直到增量为1
int dltaTable[]= {5, 3, 1};

void shellInsert(int *data, int n, int dt)
{
    if(data==NULL || n<=1)
        return;
    for(int i=dt; i<n; i+=dt)
    {
        int temp = data[i];
        int j = i;
        while(temp<data[j-dt] && j-dt>=0)//attation that index should be out of the arrange of an Array.
        {
            data[j] = data[j-dt];
            j -= dt;
        }
        if(j != i)//if no smaller than pre-elem, then don't re-assign.
        {
            data[j]=temp;
        }
    }

}

void shellSort(int *data, int n, int t)
{
    if(data==NULL || n<=1|| t<1)
        return;
    for(int i=0; i<t; ++i)
    {
        shellInsert(data, n, dltaTable[i]);
    }
}

int main(void)
{
    int data[] = {4, 1, 3, 6, 8, 9, 12, 2, 5, 22};

    int length = sizeof(data)/sizeof(data[0]);

    cout << "before sorting the data is :";
    for(int i=0; i<length; ++i)
    {
        cout<<data[i]<<" ";
    }
    cout << endl;

    cout << "after sorting the data is  :";
    shellSort(data, length , 3);
    for(int i=0; i<length; ++i)
    {
        cout<<data[i]<<" ";
    }
    cout << endl;

    return 0;
}


