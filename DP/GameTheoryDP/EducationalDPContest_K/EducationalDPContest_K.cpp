#include <cstdio>
#include <cstring>
using namespace std;

/*
    利用博奕論的dp
    必勝狀態: 所有下個狀態中包含至少一個必敗狀態
    必敗狀態: 所有下個狀態都是必勝狀態

    所以init dp[0] = 0
    剩下就是搜下去

    這題的技巧可以延伸到SG
*/

#define maxn 105
#define maxk 100005

int a[maxn];
int dp[maxk];
int n;

//遞迴深度會爆掉
// int solve(int k)
// {
//     if (dp[k] != -1)
//         return dp[k];
//     int res = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         if ((k - a[i] >= 0) && (solve(k - a[i]) == 0))
//         {
//             res = 1;
//         }
//     }
//     return dp[k] = res;
// }

int main()
{
    int k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    // memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    //遞迴會爆，所以改用這個
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i - a[j] >= 0)
                dp[i] |= (dp[i - a[j]] == 0);
        }
    }
    // puts((solve(k) == 1) ? "First" : "Second");
    puts((dp[k] == 1) ? "First" : "Second");
    return 0;
}