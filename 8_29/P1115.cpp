#include<iostream>

using namespace std;

const int N=2e5+10;
typedef long long LL;
LL f[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        LL x;
        cin>>x;
        f[i]=f[i-1]+x;   
    }
    LL ret=-1e8;
    LL prevmin=0;
    for(int i=1;i<=n;i++)
    {
        ret=max(ret,f[i]-prevmin);
        prevmin=min(prevmin,f[i]);
    }    
    cout<<ret<<endl;
    return 0;
}