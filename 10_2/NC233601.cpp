#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long LL;
priority_queue<LL,vector<LL>,greater<LL>> heap;

int main()
{
    int n;
    cin>>n;
    LL ret=0;
    for(int i=1;i<=n;i++)
    {
        LL t;
        cin>>t;
        heap.push(t);
    }
    while(heap.size()>1)
    {
        LL x=heap.top();
        heap.pop();
        LL y=heap.top();
        heap.pop();
        ret+=x+y;
        heap.push(x+y);
    }
    cout<<ret<<endl;
    return 0;
}