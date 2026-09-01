#include<iostream>

using namespace std;

const int N=1e5+10;
int n,m;
long long f[N];

int main()
{
    cin>>n>>m;
    int x;
    cin>>x;
    for(int i=2;i<=m;i++)
    {
        int y;
        cin>>y;
        if(x>y)
        {
            f[y]++;
            f[x]--;
        }
        else 
        {
            f[x]++;
            f[y]--;
        }
        x=y;
    }
    for(int i=1;i<=n;i++)
    {
        f[i]+=f[i-1];
    }
    long long ret=0;
    for(int i=1;i<n;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        ret+=min(a*f[i],c+b*f[i]);
    }
    cout<<ret<<endl;
    return 0;
}