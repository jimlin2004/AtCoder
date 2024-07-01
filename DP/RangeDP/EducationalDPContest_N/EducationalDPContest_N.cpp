#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*
    range dp
    dp[l][r]代表l~r的最小合併成本
    l ~ r中一定有一個點m使dp[l][m]與dp[m + 1][r]合併成本最小
    其中 l <= m < r
    dp轉移式可寫作dp[l][r] = min{dp[l][r], dp[l][m] + dp[m + 1][r] + size[l][r]}
    其中size[][]可先用prefixSum計算
*/

#define maxn 405

long long dp[maxn][maxn];
long long prefixSum[maxn];

long long solve(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return 0;
    long long res = 0x3f3f3f3f3f3f3f3f;
    for (int m = i; m < j; ++m)
    {
        res = min(res, solve(i, m) + solve(m + 1, j) + (prefixSum[j] - prefixSum[i - 1]));
    }
    return dp[i][j] = res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &prefixSum[i]);
        prefixSum[i] += prefixSum[i - 1];
    }
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(1, n));
    return 0;
}