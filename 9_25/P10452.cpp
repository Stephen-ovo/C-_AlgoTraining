#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=1e5+10;
typedef long long LL;
LL a[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    LL ret=0;
    int k=n/2;
    for(int i=1;i<=n;i++)
    {
        ret+=abs(a[i]-a[k]);
    }
    cout<<ret<<endl;
    return 0;
}