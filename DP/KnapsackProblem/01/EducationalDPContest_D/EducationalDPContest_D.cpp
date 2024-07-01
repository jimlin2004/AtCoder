#include <cstdio>
#include <algorithm>
using namespace std;

/*
    單純01背包
*/

#define maxn 105
#define maxw 100005

long long dp[maxw];

long long weight[maxn];
long long v[maxn];

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld %lld", &weight[i], &v[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = w; j >= weight[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + v[i]);
        }
    }
    printf("%lld\n", dp[w]);
    return 0;
}