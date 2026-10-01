#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;
int n;
struct node
{
    int t;
    int d;
}a[N];

bool cmp(node& x,node& y)
{
    return y.d*x.t<x.d*y.t;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].t>>a[i].d;
    sort(a+1,a+1+n,cmp);
    int time=0;
    long long ret=0;
    for(int i=1;i<=n;i++)
    {
        ret+=time*a[i].d;
        time+=2*a[i].t;
    }
    cout<<ret<<endl;
    return 0;
}