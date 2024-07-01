#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

/*
    就爬樓梯
    每次走1 or 2步
    且一定從1早到n
*/

#define maxn 100005

long long dp[maxn];
long long a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    dp[0] = 0x3f3f3f3f3f3f3f3f;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    printf("%lld\n", dp[n]);
    return 0;
}