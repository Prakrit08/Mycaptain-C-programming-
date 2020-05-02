#include <iostream>
using namespace std;
template <class T>
class pro
{
	T a,b;
	public:
		void prod(T a,T b)
		{
			cout<<"Product = "<<a*b;
		}
};
int main()
{
	pro p;
	cin>>p.a>>p.b;
	prod(p.a,p.b);
}
