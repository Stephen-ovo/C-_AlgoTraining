#include<iostream>

using namespace std;

int n;
const int N=15;
int arr[N][N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
    cin>>n;
    int a=1;
    int b=1;
    int x=0;
    int y=0;
    for(int i=1;i<=n*n;i++)
    {
        arr[a][b]=i;
        a=a+dx[x%4];
        b=b+dy[y%4];
        if(a>n||b>n||a<1||b<1||arr[a][b])
        {
            a=a-dx[x%4];
            b=b-dy[y%4];
            x++;
            y++;
            a=a+dx[x%4];
            b=b+dy[y%4];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%3d",arr[i][j]);
        }
        cout<<endl;
    }
    return 0;
}