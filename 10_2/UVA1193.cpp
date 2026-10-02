#include<iostream>
#include<algorithm>
#include<cmath>

using  namespace std;

const int N=1010;
struct node{
    double l;
    double r;
}a[N];
int n;
double d;

double calc(double y)
{
    return sqrt(d*d-y*y);
}

bool cmp(node& x,node& y)
{
    return x.l<y.l;
}

int main()
{
    int k=0;
    while(cin>>n>>d,n&&d)
    {
        k++;
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            double x, y;
            cin>>x>>y;
            if(y>d)
            {
                flag=0;
                break;
            }
            double len=calc(y);
            a[i].l=x-len;
            a[i].r=x+len;
        }
        if(flag==0)
        {
            printf("Case %d: -1\n",k);
            continue;
        }
        sort(a+1,a+1+n,cmp);
        int ret=1;
        double r=a[1].r;
        for(int i=2;i<=n;i++)
        {
            if(a[i].l>r)
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
        printf("Case %d: %d\n",k,ret);
    }
    return 0;
}