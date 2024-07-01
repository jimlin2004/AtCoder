#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/*
    就爬樓梯
    每次走1~k步
    且一定從1早到n
*/

#define maxn 100005

long long dp[maxn];
long long a[maxn];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0x3f3f3f3f3f3f3f3f;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (i - j <= 0)
                break;
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}