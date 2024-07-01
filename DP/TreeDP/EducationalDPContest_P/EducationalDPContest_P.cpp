#include <cstdio>
#include <vector>
using namespace std;

/*
    經典樹上覆蓋 樹dp
    求有幾種塗色法
    不能相鄰兩點塗色
    定義dp[u][0]是u不塗，dp[u][1]是u塗
    所以轉移式:
    init dp[u][0] = dp[u][1] = 1
    dp[u][0] *= dp[v][0] + dp[v][1];
    dp[u][1] *= dp[v][0];
    v is u的child
*/

#define maxn 100005

const long long MOD = 1e9 + 7;

long long dp[maxn][2];
vector<vector<int>> G;

void dfs(int u, int p)
{
    dp[u][0] = dp[u][1] = 1;
    for (int v: G[u])
    {
        if (v != p)
        {
            dfs(v, u);
            dp[u][0] *= dp[v][0] + dp[v][1];
            dp[u][0] %= MOD;
            dp[u][1] *= dp[v][0];
            dp[u][1] %= MOD;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    G.assign(n + 5, vector<int>());
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1, -1);
    printf("%lld\n", (dp[1][0] + dp[1][1]) % MOD);
    return 0;
}