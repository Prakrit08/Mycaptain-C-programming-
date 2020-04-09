#include <iostream>
using namespace std;
int main()
{
  do
  {
    cout<< "Enter Marks";
    int m;
    cin>>m;
    if(m>=85 && m<=100)
      cout<<"Grade A";
    else if(m>=70 && m<85)
      cout<<"Grade B";
    else if(m>=55 && m<70)
      cout<<"Grade C";
    else if(m>=40 && m<55)
      cout<<"Grade D";
    else if(m<40 && m>=0)
      cout<<"Grade F";
    else
      cout<<"Please enter marks in range 0-100";
  }while(m>=0 && m<=100);
