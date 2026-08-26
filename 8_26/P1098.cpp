#include<iostream>
#include<algorithm>

using namespace std;

int p1,p2,p3;
string s,ret;

bool is_dig(char a)
{
    return '0'<=a&&a<='9';
}

bool is_let(char a)
{
    return 'a'<=a&&a<='z';
}

void extend(char ch1,char ch2)
{
    string t;
    for(char c=ch1+1;c<ch2;c++)
    {
        char tmp=c;
        if(p1==2&&is_let(tmp))
        tmp-=32;
        if(p1==3)
        tmp='*';
        for(int i=1;i<=p2;i++)
        {
            t+=tmp;
        }
    }
    if(p3==2)
    reverse(t.begin(),t.end());
    ret+=t;
}

int main()
{
    cin>>p1>>p2>>p3;
    cin>>s;
    int n=s.size();
    char ch;
    for(int i=0;i<n;i++)
    {
        ch=s[i];
        if(ch!='-'||i==0||i==n-1)
        {
            ret+=ch;
        }
        else
        {
            char ch1=s[i-1];
            char ch2=s[i+1];
            if((is_dig(ch1)&&is_dig(ch2)&&ch1<ch2)||(is_let(ch1)&&is_let(ch2)&&ch1<ch2))
            {
                extend(ch1,ch2);
            }
            else 
            {
                ret+=ch;
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}