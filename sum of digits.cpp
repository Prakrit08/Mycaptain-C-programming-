#include <iostream>
using namespace std;
int no;
int SUM(int n)
{
	if(n==0)
		return 0;
	return(n%10 + SUM(n/10));
}
int main()
{
	cout<<"Enter the number\t";
	cin>>no;
	cout<<SUM(no);
}
