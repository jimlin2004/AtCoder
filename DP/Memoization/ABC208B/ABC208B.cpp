#include <cstdio>
#include <cstring>

int coins[] = {
    1, 2, 6, 24, 120, 720, 
    5040, 40320, 362880, 3628800
};

int dp[10000005];

int solve(int p)
{
    if (dp[p] != -1)
        return dp[p];
    for (int i = 9; i >= 0; --i)
    {
        if (coins[i] <= p)
        {
            dp[p] = solve(p - coins[i]) + 1;
            break;
        }
    }
    return dp[p];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int p;
    scanf("%d", &p);
    printf("%d\n", solve(p));
    return 0;
}