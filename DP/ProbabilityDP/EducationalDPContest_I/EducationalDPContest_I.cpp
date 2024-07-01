#include <cstdio>
using namespace std;

/*
    機率DP
    先湊湊看dp
    dp[i][j][k]代表到第i個coin後有j個正面，k個反面
    觀察一下發現j + k == n
    所以可以省一維變
    dp[i][j]代表到第i個coin後有j個正面
    轉移式:
        dp[i + 1][j + 1] += dp[i][j] * p[i + 1]
        也就是第i + 1那個coin結束後 來自於dp[i][j](i個coin結束且有j個正面) * 再多一個正面的機率
        dp[i + 1][j] += dp[i][j] * p[i + 1]
        就是多一個反面的機率

        最後答案要dp[n][n / 2 + 1] + dp[n][n / 2 + 2] + dp[n][n / 2 + 3] + ...
*/

#define maxn 3005

double p[maxn];
//dp[到第幾個coin][正面有幾個]
double dp[maxn][maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", &p[i]);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            dp[i + 1][j + 1] += dp[i][j] * p[i + 1];
            dp[i + 1][j] += dp[i][j] * (1.0 - p[i + 1]);
        }
    }

    double res = 0.0;
    //因為正面要比反面多，所以從(n / 2) + 1個正面開始
    for (int j = (n / 2) + 1; j <= n; ++j)
    {
        res += dp[n][j];
    }
    printf("%.10lf\n", res);
    return 0;
}