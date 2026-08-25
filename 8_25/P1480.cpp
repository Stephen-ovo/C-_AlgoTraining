#include<iostream>

using namespace std;

const int N=1e6+10;
int a[N],c[N];
long long b;
int la,lc;

void div(int a[],long long b,int c[])
{
    long long t=0;
    for(int i=la-1;i>=0;i--)
    {
        t=t*10+a[i];
        c[i]=t/b;
        t%=b;
    }
    while(lc>1&&c[lc-1]==0)
    lc--;
}

int main()
{
    string x;
    cin>>x;
    cin>>b;
    la=x.size();
    lc=la;
    for(int i=0;i<la;i++)
    {
        a[i]=x[la-1-i]-'0';
    }
    div(a,b,c);
    for(int i=lc-1;i>=0;i--)
    {
        cout<<c[i];
    }
    return 0;
}