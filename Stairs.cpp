#include <iostream>
using namespace std;
int main()
{
	cout<<"Enter the number of stairs\t";
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
			cout<<"_ _";
		cout<<"\n";
	}
}
