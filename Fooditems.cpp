#include <iostream>
using namespace std;
int main()
{
    int c,p,i;
    string fi;
	do
    {
        i=0;
        cout<<"Please Enter Your Choice\t";
		cin>>c;
        switch(c)
        {
		case 1:
                fi="Pizza";
                p=239,i=1;
                break;
		case 2:
                fi="Pasta";
                p=179,i=1;
                break;
            	case 3:
                fi="Burger";
                p=129,i=1;
                break;
            	case 4:
                fi="Sandwich";
                p=149,i=1;
                break;
            	case 5:
                fi="French Fries";
                p=99,i=1;
                break;
            	default:
                cout<<"Please Enter A Valid Choice 1-5\n";
        }
		if(i==1)
            cout<<"Food item - "<<fi<<"\nPrice - Rs "<<p;
    }while(!(c>0 && c<6));
}             
