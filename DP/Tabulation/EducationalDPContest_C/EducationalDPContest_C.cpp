#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100005

/*
    就是dp[i][j]第i天做j時
    第i - 1天就不能做j
    一路推表格取最大值可
*/

//dp[i][j] 代表第i天做j這件事
long long dp[maxn][3];
long long a[maxn][3];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld %lld %lld", &a[i][0], &a[i][1], &a[i][2]);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (j != k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
                }
            }
        }
    }
    printf("%lld\n", max({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}