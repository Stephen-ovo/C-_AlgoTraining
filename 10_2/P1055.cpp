#include<iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int k=1;
    int a[15];
    for(int i=0;i<n-2;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[k]=s[i]-'0';
            k++;
        }
    }
    k--;
    int ret=0;
    for(int i=1;i<=k;i++)
    {
        ret+=a[i]*i;
    }
    k++;
    if(s[n-1]=='X')
        a[k]=10;
    else 
        a[k]=s[n-1]-'0';
    if(ret%11==a[k])
        cout<<"Right"<<endl;
    else 
    {
        for(int i=1;i<=k-1;i++)
        {
            cout<<a[i];
            if(i==1||i==4||i==9)
                cout<<'-';
        }
        if(ret%11==10)
            cout<<'X';
        else cout<<ret%11;
    }
    return 0;
}