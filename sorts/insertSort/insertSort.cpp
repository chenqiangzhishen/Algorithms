#include <iostream>
using namespace std;

void insertSort(int *data, int n)
{
    if(data == NULL || n<=1)
        return;
    for(int i=1; i<n; ++i)
    {
        int temp = data[i];
        int j = i;
        while(temp < data[j-1] && j-1>=0)//attation that index should be out of the arrange of an Array.
        {
            data[j] = data[j-1];
            --j;
        }
        if(j < i)//if no smaller than pre-elem, then don't re-assign.
        {
            data[j]=temp;
        }
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
    insertSort(data, length);
    for(int i=0; i<length; ++i)
    {
        cout<<data[i]<<" ";
    }
    cout << endl;

    return 0;
}

