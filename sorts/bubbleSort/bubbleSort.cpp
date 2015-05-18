
#include <iostream>
using namespace std;

void bubbleSort(int data[], int n)
{
	if(data==NULL || n<=0)
		return;
	int i=0, j=0;
	bool bSwap = true;
	for(i=0; i<n-1 && bSwap; ++i)
	{
		bSwap = false;
		for(j=0; j<n-i-1; ++j)
		{
			if(data[j]>data[j+1])
			{
				//swap
				data[j+1] ^= data[j];
				data[j] ^= data[j+1];
				data[j+1] ^= data[j];
				bSwap = true;
			}
			
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
    bubbleSort(data, length);
    for(int i=0; i<length; ++i)
    {
        cout<<data[i]<<" ";
    }
    cout << endl;

    return 0;
}


