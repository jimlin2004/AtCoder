#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define maxn 200005

/*
    題目可以轉化為圖論問題
    用a[]，b[]進行建邊
    之後問題轉成檢察圖是不是二分圖
    跑dfs檢查即可(color檢查法)
*/

int a[maxn];
int b[maxn];
vector<vector<int>> G;
//color只有0 or 1，-1代表沒走過
int color[maxn];
bool isBipartite = true;

void dfs(int u, int c)
{
    color[u] = c;
    for (int v: G[u])
    {
        if (color[u] == color[v])
        {
            isBipartite = false;
        }
        else if (color[v] == -1)
        {
            dfs(v, 1 - c);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    G.assign(n + 5, vector<int>());
    memset(color, -1, sizeof(color));

    for (int i = 0; i < m; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    
    //建邊a[] <-> b[]
    for (int i = 0; i < m; ++i)
    {
        G[a[i]].emplace_back(b[i]);
        G[b[i]].emplace_back(a[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == -1)
            dfs(i, 0);
    }

    puts((isBipartite) ? "Yes" : "No");
    return 0;
}