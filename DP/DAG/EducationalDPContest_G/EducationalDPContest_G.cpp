#include <cstdio>
#include <vector>
using namespace std;

/*
    考DAG的性質

    dp[u]代表已u作為path最長能有多長

    轉移式:
        if (v沒走過)
            dfs(v)
        dp[u] = max(dp[u], dp[v] + 1)
*/

#define maxn 100005

vector<vector<int>> G;
bool vis[maxn];
long long dp[maxn];
int indegree[maxn];
long long res = -1;

void dfs(int u)
{
    vis[u] = true;
    for (int v: G[u])
    {
        if (!vis[v])
            dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
        res = max(res, dp[u]);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    G.assign(n + 5, vector<int>());
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
        ++indegree[v];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
        {
            dfs(i);
        }
    }

    printf("%lld\n", res);
    return 0;
}
