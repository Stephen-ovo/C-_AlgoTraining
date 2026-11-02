#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;
int a[N];
int disc[N];
int pos,n;

int find(int t)
{
    int left=1;
    int right=pos;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(disc[mid]<t)
            left=mid+1;
        else right=mid;
    }
    return left;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        disc[++pos]=a[i];
    }
    sort(disc+1,disc+1+pos);
    pos=unique(disc+1,disc+1+pos)-(disc+1);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" 离散化之后为: "<<find(a[i])<<endl;;
    }
    return 0;
}