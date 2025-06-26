#include <bits/stdc++.h>
using namespace std;

// 用值域線段樹爆破mex查詢

#define maxn 1500005

int st[maxn << 2];
int cnt[maxn];
int A[maxn];

void update(int i, int pos, int l, int r, int val)
{
    if (l == pos && r == pos)
    {
        st[i] = val;
        return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(i * 2, pos, l, mid, val);
    else
        update(i * 2 + 1, pos, mid + 1, r, val);
    
    st[i] = min(st[i * 2], st[i * 2 + 1]);
}

int query(int i, int l, int r)
{
    if (l == r)
        return l;
    
    int mid = (l + r) >> 1;
    if (st[i * 2] == 0)
        return query(i * 2, l, mid);
    else
        return query(i * 2 + 1, mid + 1, r);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int maxRange = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
        maxRange = max(maxRange, A[i]);
    }
    ++maxRange;
    
    for (int i = 0; i < m; ++i)
    {
        if (cnt[A[i]] == 0)
            update(1, A[i], 0, maxRange, 1);
        ++cnt[A[i]];
    }

    int res = query(1, 0, maxRange);
    for (int i = m; i < n; ++i)
    {
        if (cnt[A[i - m]] == 1)
            update(1, A[i - m], 0, maxRange, 0);
        --cnt[A[i - m]];

        if (cnt[A[i]] == 0)
            update(1, A[i], 0, maxRange, 1);
        ++cnt[A[i]];

        res = min(res, query(1, 0, maxRange));
    }

    printf("%d\n", res);
    
    return 0;
}