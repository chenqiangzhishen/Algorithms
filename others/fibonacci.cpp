#include <iostream>
using namespace std;


long fun(long a, long b, long n)
{
	return n>1 ? fun(b, a+b, n-1) : a; 
}

long fibonacci(long n)
{
	return fun(1, 2, n);
}

int main(void)
{
	long n;
	cout << "please input the number" << endl;
	cin >> n;
	cout << "the fibonacci is:" << endl;
	cout << fibonacci(n) << endl;
	
	return 0;
}
