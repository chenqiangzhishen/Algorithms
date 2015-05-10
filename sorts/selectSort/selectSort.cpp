#include <iostream>
using namespace std;

void selectSort(int data[], int n)
{
	if(data==NULL || n<=0)
		return;
	int minIndex = 0, i=0, j=0;
	for(i=0; i<n-1; ++i)//need n-1 times loop
	{
		minIndex = i;//every time to set the first index as default min index
		for(j=i+1; j<n; ++j)//from the second index to start to compare to find the really min index 
		{
			if(data[j] < data[minIndex])
			{
				minIndex = j;
			}
		}
		if(minIndex != i)//if the default min index is not min, swap...
		{
			data[i] ^= data[minIndex];
			data[minIndex] ^= data[i];
			data[i] ^= data[minIndex];
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
    selectSort(data, length);
    for(int i=0; i<length; ++i)
    {
        cout<<data[i]<<" ";
    }
    cout << endl;

    return 0;
}


