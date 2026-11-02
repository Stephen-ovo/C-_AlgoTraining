#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N=2e4+10;
int a[N],b[N],dis[2*N],f[2*N];
unordered_map<int,int> id;
int n;

int main()
{
    cin>>n;
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        dis[++pos]=a[i];
        dis[++pos]=b[i];
    }
    sort(dis+1,dis+1+pos);
    pos=unique(dis+1,dis+1+pos)-(dis+1);
    for(int i=1;i<=pos;i++)
    {
        int x=dis[i];
        id[x]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int l=id[a[i]];
        int r=id[b[i]];
        f[l]++;
        f[r]--;
    }
    for(int i=1;i<=pos;i++)
    {
        f[i]+=f[i-1];
    }
    int ret=0;
    for(int i=1;i<=pos;i++)
    {
        int j=i;
        while(j<=pos&&f[j]>0)
            j++;
        ret+=dis[j]-dis[i];
        i=j;
    }
    cout<<ret<<endl;
    return 0;
}