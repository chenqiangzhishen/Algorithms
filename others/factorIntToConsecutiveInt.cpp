#include <iostream>
using namespace std;

/*
 *
 *
 * 经典题：一个整数分解为连续正整数之和
 *

题目是将一个整数分解为连续正整数之和，如15可以分解为：

15 = 1 + 2 + 3 + 4 + 5

15 = 4 + 5 + 6

15 = 7 + 8

*/

/*
 *
 *
 *
 * 我们计算从i开始连续k个数之和的计算公式如下：
 *
 * sum = k * (2 * i + k - 1) / 2;
 *
 * 现在题目要求sum == n 的所有可能情况，上面的解法是从起始位置开始循环，
 * 又根据连续个数循环，两重循环，那么从上面的公式逆向想想，如果sum==n时，
 * i与k直接满足什么关系呢？有 k * (2 * i + k - 1) = 2 * n。
 * 那么如果用k循环，计算出起始位置 i = ( 2*n / k - k + 1) / 2，
 * 岂不是时间复杂度降到线性的了。如下：
 *
 *
 */

void factorInt(int x)
{
	if(x<0)
		return;
	int maxK = x/2;
	cout << maxK << endl;
	int temp = 0;
	int i = 0;
	for(int k=1; k<=maxK; ++k)
	{
	cout << k << endl;
		if(2*x % k == 0)
		{
		cout << k;
			temp = 2*x/k -k + 1;
			cout << temp << endl;
			if(temp % 2 == 0)
			{
				i = temp/2;
				//for(int j=i; j<k; ++j)
				for(int j=0; j<k-1; ++j)
				{
				cout << j << endl;
				/*
					if(j==k)
					{
						cout << j << endl;
					}
					else
					{
						cout << j << " + ";
					}
					*/
				}
			}
		}

	}
}

int main(void)
{
	int x=0;
	while(1)
	{
		cout << " please input one number" << endl;
		cin >> x;
		factorInt(x);
	}
	return 0;
	
}
