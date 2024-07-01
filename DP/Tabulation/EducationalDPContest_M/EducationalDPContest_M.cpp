#include <cstdio>
using namespace std;

#define maxn 105
#define maxk 100005
const long long MOD = 1e9 + 7;

/*
    定義 dp[前i位小朋友][拿了幾顆糖果]
    轉移式很好想到:
    for (int i = 0; i <= a[1]; ++i)
        dp[1][i] = 1;
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j <= K; ++j)
        {
            for (int k = 0; k <= a[i]; ++k)
            {
                if (j - k >= 0)
                    dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    但這麼做會花上O(NK^2)會超時

    注意到中間的 k from 0 to a[i]其實可以用前綴和
    也就是在算dp[i]之前先將dp[i - 1]處理成前綴和
    這樣空間有O(NK)
    轉移O(1)
    所以O(NK)即可
*/

//dp[前i位小朋友][拿了幾顆糖果]
long long dp[maxn][maxk];
long long a[maxn];
long long prefixSum[maxk];

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%lld", &a[i]);
    }
    
    for (int i = 0; i <= a[1]; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= N; ++i)
    {
        prefixSum[0] = dp[i - 1][0];
        for (int j = 1; j <= K; ++j)
        {
            prefixSum[j] = (prefixSum[j - 1] + dp[i - 1][j]) % MOD;
        }

        for (int j = 0; j <= K; ++j)
        {
            if (j - a[i] > 0)
            {
                //注意減法MOD運算
                dp[i][j] = (prefixSum[j] - prefixSum[j - a[i] - 1] + MOD) % MOD;
            }
            else
            {
                dp[i][j] = prefixSum[j];
                dp[i][j] %= MOD;
            }
        }
    }
    printf("%lld\n", dp[N][K] % MOD);
    return 0;
}