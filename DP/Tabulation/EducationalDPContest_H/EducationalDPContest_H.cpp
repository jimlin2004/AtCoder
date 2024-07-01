#include <iostream>
using namespace std;

/*
    一般的推表格統計走法
*/

#define maxn 1005
#define MOD 1000000007

char grid[maxn][maxn];
long long dp[maxn][maxn];

int main()
{
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            cin >> grid[i][j];
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= h; ++i)
    {

        for (int j = 1; j <= w; ++j)
        {
            if (grid[i - 1][j] != '#')
                dp[i][j] += dp[i - 1][j];
            if (grid[i][j - 1] != '#')
                dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[h][w] % MOD << '\n';
    return 0;
}
