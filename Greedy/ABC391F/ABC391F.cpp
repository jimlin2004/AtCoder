#include <bits/stdc++.h>
using namespace std;

/*

    概念跟UVA的top k sum想法差不多
    先排序好A、B、C後
    從最大的組合開始(n, n, n)
    丟入pq
    每次pop出來後會丟入(i - 1, j, k), (i, j - 1, k), (i, j, k - 1)，
    這是因為(i, j, k)會先於上面三個
    但要注意(i, j, k)枚舉會重複，所以要用set去掉重複的 
    O(NlogN + KlogK)

*/

#define maxn 200005

struct Item
{
    int i, j, k;
    long long sum;

    bool operator < (const Item& other) const
    {
        return sum < other.sum;
    }
};

long long A[maxn];
long long B[maxn];
long long C[maxn];

priority_queue<Item> pq;
set<tuple<int, int, int>> vis; // 去掉重複的

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &A[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &B[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &C[i]);
    
    sort(A + 1, A + 1 + n);
    sort(B + 1, B + 1 + n);
    sort(C + 1, C + 1 + n);

    pq.push({n, n, n, A[n] * B[n] + B[n] * C[n] + C[n] * A[n]});
    vis.insert({n, n, n});

    --k;

    while (k--)
    {
        Item item = pq.top();
        pq.pop();

        int i = item.i, j = item.j, k = item.k;
        if (i - 1 > 0 && (vis.find({i - 1, j, k}) == vis.end()))
        {
            pq.push({i - 1, j, k, A[i - 1] * B[j] + B[j] * C[k] + C[k] * A[i - 1]});
            vis.insert({i - 1, j, k});
        }
        if (j - 1 > 0 && (vis.find({i, j - 1, k}) == vis.end()))
        {
            pq.push({i, j - 1, k, A[i] * B[j - 1] + B[j - 1] * C[k] + C[k] * A[i]});
            vis.insert({i, j - 1, k});
        }
        if (k - 1 > 0 && (vis.find({i, j, k - 1}) == vis.end()))
        {
            pq.push({i, j, k - 1, A[i] * B[j] + B[j] * C[k - 1] + C[k - 1] * A[i]});
            vis.insert({i, j, k - 1});
        }
    }

    printf("%lld\n", pq.top().sum);

    return 0;
}