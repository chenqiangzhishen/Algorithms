#include <iostream>
using namespace std;




/*
题目：输入一个整形数组，数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。求所有子数组的和的最大值。要求时间复杂度为O(n)。
*/
int getMaxSumOfSubArray(const int arr[], const int len)
{
    int maxVal = arr[0];
    int curMaxVal = 0;
    int i=0;
    for(i=0; i<len; ++i)
    {
        // if current max value less than 0, means that it should be clear to 0 in order to start new calculate.
        if(curMaxVal >= 0)
        {
            curMaxVal += arr[i];
        }
        else
        {
            curMaxVal = arr[i];
        }
        if(curMaxVal > maxVal)
        {
            maxVal = curMaxVal;
        }
    }

    return maxVal;
}


int main(void)
{
    //int arr[10] = {1, -1, 2, 3, -2, 4, 5, -1, 6, -1};
    int arr[10] = {-11, 1, -2, -3, -20, -4, 5, 21, -26, 21};
    int maxVal = getMaxSumOfSubArray(arr, 10);
    cout << maxVal << endl;

    return 0;
}
