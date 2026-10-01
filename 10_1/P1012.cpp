#include<iostream>
#include<algorithm>

using namespace std;

const int N=25;
string a[N];

bool cmp(string x,string y)
{
    return x+y>y+x;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}