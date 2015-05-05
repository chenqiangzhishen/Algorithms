#include<iostream>
using namespace std;

int partition(int *data, int low, int high)
{
    if(data==NULL || low>=high)
        return -1;
    int pivotKey = data[low];//attion that the index of data should be low, not 0;
    while(low < high) {
        while(pivotKey<data[high] && low<high)// don't forget to add the requirment "low<high"
            --high;
        data[low] = data[high];

        while(pivotKey > data[low]&& low<high)// don't forget to add the requirment "low<high"
            ++low;
        data[high] = data[low];
    }
    data[low] = pivotKey;

    return low;
}

void quickSort(int *data, int low, int high)
{
    if(data==NULL || low>=high)
        return;
    int mid = partition(data, low, high);
    quickSort(data, low, mid-1);
    quickSort(data, mid+1, high);
}

int main(void)
{
    int data[10] = {4, 1, 3, 6, 8, 9, 12, 2, 5, 22};
    quickSort(data, 0, 10);
    for(int i=0; i<10; ++i)
    {
        cout<<data[i]<<(i != 9? "," : "\n");
    }
    return 0;
}


