#include <iostream>
using namespace std;

const int N = 2e5 + 10;
typedef long long LL;

LL a[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    LL sum = 0;
    LL ret = -1e18;   // 注意这里！

    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum > ret)
            ret = sum;
        if (sum < 0)
            sum = 0;
    }

    cout << ret << endl;
    return 0;
}