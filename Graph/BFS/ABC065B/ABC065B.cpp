#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
    題目可以轉為圖論問題
    建邊
    i -> a[i]
    然後跑BFS看1 -> 2的最短距離即為答案
*/

#define maxn 100005

vector<vector<int>> G;
int dis[maxn];
bool vis[maxn];

void bfs(int s, int t)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (vis[curr])
            continue;
        vis[curr] = true;
        if (curr == t)
            return;
        for (int v: G[curr])
        {
            if (!vis[v])
            {
                dis[v] = dis[curr] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    scanf ("%d", &n);
    G.assign(n + 5, vector<int>());
    int v;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &v);
        G[i].emplace_back(v);
    }
    memset(dis, 0x3f, sizeof(dis));
    bfs(1, 2);
    printf("%d\n", (dis[2] == 0x3f3f3f3f) ? -1 : dis[2]);
    return 0;
}