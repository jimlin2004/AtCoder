#include <cstdio>
#include <cstring>

//不能開太大，乾脆砍到10^8以下用dp
//用題目的10^12開不了
long long dp[100000005];

long long solve(long long h)
{
    if (h >= 100000005)
    {
        return 2 * solve(h / 2) + 1;
    }
    else
    {
        if (dp[h] != -1)
            return dp[h];
        dp[h] = 2 * solve(h / 2) + 1;
        return dp[h];
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    long long h;
    scanf("%lld", &h);
    printf("%lld\n", solve(h));
    return 0;
}