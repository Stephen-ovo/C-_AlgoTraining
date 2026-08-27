#include<iostream>

using namespace std;

int day[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int date1,date2;
    cin>>date1>>date2;
    int ret=0;
    for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=day[i];j++)
        {
            int k=i%10*10+i/10+j%10*1000+j/10*100;
            int num=k*10000+i*100+j;
            if(date1<=num&&date2>=num)
            ret++;
        }
    }
    cout<<ret<<endl;
    return 0;
}