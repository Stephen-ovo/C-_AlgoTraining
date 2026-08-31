#include<iostream>

using namespace std;

int n,m;
const int N=5e3+10;
int a[N][N],f[N][N];

int main()
{
    cin>>n>>m;
    int xm=-1,ym=-1;
    while(n--)
    {
        int x,y,v;
        cin>>x>>y>>v;
        x+=1;
        y+=1;
        a[x][y]+=v;
        xm=max(x,xm);
        ym=max(y,ym);
    }
    xm=max(m,xm);
    ym=max(m,ym);
    for(int i=1;i<=xm;i++)
    {
        for(int j=1;j<=ym;j++)
        {
            f[i][j]=a[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    int ret=-1;
    for(int i=m;i<=xm;i++)
    {
        for(int j=m;j<=ym;j++)
        {
            int tmp=f[i][j]-f[i-m][j]-f[i][j-m]+f[i-m][j-m];
            ret=max(ret,tmp);
        }
    }
    cout<<ret<<endl;
    return 0;
}