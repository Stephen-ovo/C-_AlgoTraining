#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e6+10;
struct node{
    int l;
    int r;
}a[N];
int n;

bool cmp(node& x,node& y)
{
    return x.l<y.l;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+n,cmp);
    int ret=1;
    int r=a[1].r;
    for(int i=2;i<=n;i++)
    {
        if(a[i].l>=r)
        {
            ret++;
            r=a[i].r;
        }
        else 
        {
            if(a[i].r<r)
                r=a[i].r;
        }
    }
    cout<<ret<<endl;
    return 0;
}