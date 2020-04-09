#include <iostream>
using namespace std;
int main()
{
    int a[3][3]={{9,6,1},{144,70,50},{10,12,78}},*p=NULL,r=0,c=0,m=0,s=0,i;
    p=&a[0][0];
    for(r=0;r<3;++r)
        for(c=0;c<3;++c)
            cout<<"a["<<r<<"]["<<c<<"]="<<*(p+(r*3)+c)<<"\n";
    for(i=0;i<a;i++)
    {
        p=&a[i];
        s+=*(p+m);
        m++;
    }
}
