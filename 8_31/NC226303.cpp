#include<iostream>

using namespace std;

const int N=1e5+10;
typedef long long LL;
LL a[N],f[N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=a[i]-a[i-1];
    }
    while(m--)
    {
        int l,r;
        LL k;
        cin>>l>>r>>k;
        f[l]+=k;
        f[r+1]-=k;
    }
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=f[i];
        cout<<sum<<" ";
    }
    return 0;
}