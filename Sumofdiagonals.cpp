#include <iostream>
using namespace std;
int main()
{
    int a[3][3]={{9,6,1},{144,70,50},{10,12,78}};
    int *p=NULL,r=0,c=0;
    p=&a[0][0];
    for(r=0;r<3;++r)
        for(c=0;c<3;++r)
            cout<<"a["<<r<<"]["<<c<<"]="<<*(p+(r*3)+c))<<"\n";
}
