#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N=2e5+10;
LL a[N];
int n,c;

int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    LL ret=0;
    for(int i=1;i<=n;i++)
    {
        LL tmp=a[i]-c;
        ret+=upper_bound(a+1,a+n+1,tmp)-lower_bound(a+1,a+n+1,tmp);
    }
    cout<<ret<<endl;
    return 0;
}