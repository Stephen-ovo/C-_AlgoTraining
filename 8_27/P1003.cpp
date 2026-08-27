#include<iostream>

using namespace std;

const int N=1e5+10;
int a[N],b[N],g[N],k[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    }
    int x,y;
    cin>>x>>y;
    int flag=0;
    int ret;
    for(int i=n;i>=1;i--)
    {
        int u=a[i]+g[i];
        int v=b[i]+k[i];
        if(x>=a[i]&&x<=u&&y>=b[i]&&y<=v)
        {
            flag=1;
            ret=i;
            break;
        }
    }
    if(flag)
    cout<<ret<<endl;
    else
    cout<<"-1"<<endl;
    return 0;
}