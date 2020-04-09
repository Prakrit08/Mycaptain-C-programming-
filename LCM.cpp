#include <iostream>
using namespace std;
int LCM(int a, int b)
{ 
    static int c=1;
 	if (c%a==0 && c%b==0)
        return c;
    c++;
    LCM(a, b);
    return c;
}
int main()
{
	int a,b;
	cout<<"Enter first number\t";
	cin>>a;
	cout<<"Enter Second number\t";
	cin>>b;
	cout<<"The LCM of "<<a<<" and "<<b<<" is "<<LCM(a,b);
}
