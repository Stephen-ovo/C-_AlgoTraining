#include<iostream>
#include<cmath>

using namespace std;

int n;

int main()
{
    cin>>n;
    for(int i=n;i>=0;i--)
    {
        int m;
        cin>>m;
        int t=abs(m);
        if(m==0)
        continue;
        if(m<0)
        {
            cout<<'-';
        }
        else 
        {
            if(i!=n)
            cout<<'+';
        }
        if(t!=1||(t==1&&i==0))
        cout<<t;
        if(i==0)
        continue;
        else if(i==1)
        cout<<'x';
        else
        cout<<"x^"<<i;
    }
    return 0;
}