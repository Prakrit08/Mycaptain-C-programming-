#include <iostream>
using namespace std;
int i=2,no;
int PRIME(int n)
{
	if(i==n)
		return 1;
	else if(n%i==0)
		return 0;
	else
	{
		i+=1;
		return PRIME;
	}
}
int main()
{
	cout<<"Enter the number\t";
	cin>>no;
	if(PRIME(no)==1)
		cout<<"It is a prime number.";
	else
		cout<<"It is not a prime number.";
}
