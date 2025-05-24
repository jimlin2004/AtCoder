#include <bits/stdc++.h>
using namespace std;

// 用dfs樹壓平後用線段樹維護樹轉成區間問題

#define maxn 300005

struct Edge
{
    int u, v;
};

long long st[maxn * 4 + 5];
vector<Edge> edges;
vector<vector<int>> G;
int dfn[maxn];
int subtreeSize[maxn];
int t = 1; // dfn


void dfs(int u, int p)
{
    subtreeSize[u] = 1;
    dfn[u] = t++;
    for (int v: G[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        subtreeSize[u] += subtreeSize[v];
    }
}

void build(int i, int l, int r)
{
    if (l == r)
    {
        st[i] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    st[i] = st[i * 2] + st[i * 2 + 1];
}

void update(int i, int l, int r, int p, long long c)
{
    if (l == r)
    {
        st[i] += c;
        return;
    }

    int mid = (l + r) / 2;
    if (p <= mid)
        update(i * 2, l, mid, p, c);
    if (mid < p)
        update(i * 2 + 1, mid + 1, r, p, c);
    
    st[i] = st[i * 2] + st[i * 2 + 1];
}

long long query(int i, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return st[i];
    }

    int mid = (l + r) / 2;
    long long res = 0;
    if (ql <= mid)
        res += query(i * 2, l, mid, ql, qr);
    if (mid < qr)
        res += query(i * 2 + 1, mid + 1, r, ql, qr);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    G.assign(n + 5, {});

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edges.push_back({u, v});
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, -1);
    build(1, 1, n);

    int q;
    scanf("%d", &q);
    while (q--)
    {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1)
        {
            int x;
            long long w;
            scanf("%d %lld", &x, &w);
            update(1, 1, n, dfn[x], w);
        }
        else if (cmd == 2)
        {
            int edgeIndex;
            scanf("%d", &edgeIndex);
            --edgeIndex; // 變成0 ~ m - 1的index空間
            int u = edges[edgeIndex].u;
            int v = edges[edgeIndex].v;

            int root = 0;
            if (dfn[u] > dfn[v])
                root = u;
            else
                root = v;
            
            int totalW = query(1, 1, n, 1, n);
            int subtreeW = query(1, 1, n, dfn[root], dfn[root] + subtreeSize[root] - 1);

            printf("%lld\n", abs(totalW - subtreeW - subtreeW));
        }
    }

    return 0;
}