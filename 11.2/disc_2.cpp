#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N=1e5+10;
int a[N],disc[N],id[N];
int n;
unordered_map<int,int> mp;

int main()
{
    cin>>n;
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        disc[++pos]=a[i];
    }
    sort(disc+1,disc+1+pos);
    int cnt=0;
    for(int i=1;i<=pos;i++)
    {
        if(mp.count(disc[i]))
            continue;
        cnt++;
        id[disc[i]]=cnt;
        mp[disc[i]]=1;
    }
    for(int i=1;i<=pos;i++)
    {
        cout<<disc[i]<<" 离散化之后是: "<<id[disc[i]]<<endl;
    }
    return 0;
}