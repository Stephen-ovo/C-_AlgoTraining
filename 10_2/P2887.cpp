#include<iostream>
#include<algorithm>

using namespace std;

const int N=2510;
struct node{
    int x;
    int y;
}a[N],b[N];
int n,m;

bool cmp(node& x,node& y)
{
    return x.x>y.x;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    for(int i=1;i<=m;i++)
        cin>>b[i].x>>b[i].y;
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        int l=a[i].x;
        int r=a[i].y;
        for(int j=1;j<=m;j++)
        {
            int w=b[j].x;
            int &cnt=b[j].y;
            if(cnt==0)
                continue;
            if(w>r)
                continue;
            if(w<l)
                break;
            ret++;
            cnt--;
            break;
        }
    }
    cout<<ret<<endl;
    return 0;
}