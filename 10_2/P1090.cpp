#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N=1e4+10;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll>> heap;
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        heap.push(x);
    }
    ll ret=0;
    while(heap.size()>1)
    {
        ll x=heap.top();
        heap.pop();
        ll y=heap.top();
        heap.pop();
        ret+=x+y;
        heap.push(x+y);
    }
    cout<<ret<<endl;
    return 0;
}