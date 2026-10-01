#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N=5e4+10;
struct node{
    LL w;
    LL s;
}a[N];

bool cmp(node& x,node& y)
{
    return y.w-x.s<x.w-y.s;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].w>>a[i].s;
    LL ret=-1e10;
    sort(a+1,a+1+n,cmp);
    LL wei=0;
    for(int i=1;i<=n;i++)
    {
        wei+=a[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        ret=max(ret,wei-a[i].w-a[i].s);
        wei-=a[i].w;
    }
    cout<<ret<<endl;
    return 0;
}