#include<iostream>
#include<cstring>

using namespace std;

const int N=20;
int a[N],t[N];
int T,n;

int calc(int x,int y)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if((((x>>i)&1)==0)&&(((y>>i)&1)==1))
        sum++;
        if((((x>>i)&1)==1)&&(((y>>i)&1)==0))
        return -1;
    }
    return sum;
}

int solve()
{\
    int ret=0x3f3f3f3f;
    for(int st=0;st<(1<<n);st++)
    {
        memcpy(t,a,sizeof(a));
        int cnt=0;
        int change=st;
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            int c=calc(t[i],change);
            if(c==-1)
            {
                flag=0;
                break;
            }
            cnt+=c;
            t[i]=change;
            change=t[i-1]^(t[i]<<1)^(t[i]>>1);
            change&=(1<<n)-1;
        }
        if(flag)
        ret=min(ret,cnt);
    }
    if(ret==0x3f3f3f3f)
    return -1;
    else return ret;
}

int main()
{
    
    cin>>T;
    for(int k=1;k<=T;k++)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x;
                cin>>x;
                if(x)
                a[i]|=(1<<j);
            }
        }
        printf("Case %d: %d\n",k,solve());
    }
    return 0;
}