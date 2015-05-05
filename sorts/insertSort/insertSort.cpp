#include <iostream>
using namespace std;

void insertSort(int data[], int n)
{
    for(int i=1; i<n; ++i)
    {
        int temp = data[i];
        int j = i;
        while(temp < data[j-1] && j>0)//attation that index should be out of the arrange of an Array.
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
    int data[10] = {4, 1, 3, 6, 8, 9, 12, 2, 5, 22};
    cout << "before sorting the data is :";
    for(int i=0; i<10; ++i)
    {
        cout<<data[i]<<(i != 9? "," : "\n");
    }

    cout << "after sorting the data is  :";
    insertSort(data, 10);
    for(int i=0; i<10; ++i)
    {
        cout<<data[i]<<(i != 9? "," : "\n");
    }

    return 0;
}


