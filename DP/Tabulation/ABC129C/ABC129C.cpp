#include <cstdio>

int dp[100005];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    dp[0] = 1;
    int broken;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &broken);
        dp[broken] = -1;
    }
    if (dp[1] != -1)
        dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (dp[i] == -1)
            continue;
        if (dp[i - 2] != -1)
        {
            dp[i] += dp[i - 2];
            dp[i] %= 1000000007;
        }
        if (dp[i - 1] != -1)
        {
            dp[i] += dp[i - 1]; 
            dp[i] %= 1000000007;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}