#include<iostream>
#include<cstring>

using namespace std;

int a[10];
int t[10];
int n;

int cal(int push)
{
    int count=0;
    while(push)
    {
        count++;
        push&=(push-1);
    }
    return count;
}

int main()
{
    cin>>n;
    while(n--)
    {
        memset(a,0,sizeof(a));//每次循环开始时，要先清上次的数据
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                char ch;
                cin>>ch;
                if(ch=='0')
                a[i]|=1<<j;/*a[i]中每个元素默认为零，为了将输入的01串
                取反并存成一个数，输入为1，可以不管（此时对应位上是0）；
                输入为0，则对应位置上或上1，即可改为1*/
            }
        }
        int ret=0x3f3f3f3f;//设置一个大数
        for(int st=0;st<(1<<5);st++)//二进制枚举
        {
            memcpy(t,a,sizeof(a));//将a[N]中的元素复制到t[N]中
            int push=st;
            int cnt=0;
            for(int i=0;i<5;i++)
            {
                cnt+=cal(push);
                t[i]=t[i]^push^(push>>1)^(push<<1);
                t[i+1]^=push;
                t[i]&=((1<<5)-1);
                push=t[i];
            }
            if(t[4]==0)
            ret=min(ret,cnt);
        }//已经枚举了所有的情况 
        if(ret>6)
        cout<<-1<<endl;
        else cout<<ret<<endl;
    }
    return 0;
}