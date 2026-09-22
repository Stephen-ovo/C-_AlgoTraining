#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N=1e5+10;
LL a[N];
int n,m;

int find(LL b)
{
    int l=1,r=m;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]>=b)
            r=mid;
        else l=mid+1;
    }
    return l;
}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    sort(a+1,a+m+1);
    a[0]=-1e8;
    LL ret=0;
    for(int i=1;i<=n;i++)
    {
        LL b;
        cin>>b;
        int pos=find(b);
        ret+=min(abs(a[pos]-b),abs(a[pos-1]-b));
    }
    cout<<ret<<endl;
    return 0;
}