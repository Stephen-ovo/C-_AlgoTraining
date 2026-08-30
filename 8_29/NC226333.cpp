#include<iostream>

using namespace std;

int n,m,q;
typedef long long LL;
const int N=1e3+10;
LL f[N][N],a[N][N];

int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=a[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1]<<endl;
    }
    return 0;
}