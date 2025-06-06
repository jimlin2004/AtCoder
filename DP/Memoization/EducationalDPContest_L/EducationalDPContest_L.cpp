#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*
    定義dp[l][r]是l ~ r時與先手最大差異值
    Deque可以拿頭尾
    所以轉移式中dp[l][r]與dp[l + 1][r]、dp[l][r - 1]有關
    轉移式:
        dp[l][r] = max{a[l] - solve(l + 1, r), a[r] - solve(l, r - 1)}
    裡面用減的主要是因為求的是相減且會一直換手，所以正負正負...
*/

#define maxn 3005

bool vis[maxn][maxn];
long long dp[maxn][maxn];
long long a[maxn];

long long solve(int l, int r)
{
    if (l > r)
        return 0;
    if (vis[l][r])
        return dp[l][r];
    vis[l][r] = true;
    long long res = a[l] - solve(l + 1, r);
    res = max(res, a[r] - solve(l, r - 1));
    return dp[l][r] = res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    printf("%lld\n", solve(1, n));
    return 0;
}