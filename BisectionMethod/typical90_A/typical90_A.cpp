#include <cstdio>
using namespace std;

/*
    對答案二分搜
    搜出長度len，去檢查在限制
    切出的長度一定要大於等於len的情況下
    能切出多少段(res = cnt - k)
    當res > 0時代表len太小 -> l = mid
    res < 0時代表len太大 -> r = mid
    res == 0時試試看能不能更大 -> l = mid
    最後答案在l
    O(NlogK)
*/

#define maxn 100005

long long A[maxn];
//存的是切點間的長度
long long diff[maxn];
int N, L;
int k;

int check(long long len)
{
    long long curr = 0;
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        curr += diff[i];
        if (curr >= len)
        {
            ++cnt;
            curr = 0;
        }
    }
    return cnt - k - 1;
}

int main()
{
    scanf("%d %d", &N, &L);
    scanf("%d", &k);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &A[i]);
        diff[i] = A[i] - A[i - 1];
    }
    diff[N + 1] = L - A[N];
    ++N;
    long long l = 0, r = L;
    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;
        int res = check(mid);
        if (res >= 0)
            l = mid;
        else
            r = mid;
    }
    printf("%lld\n", l);
    return 0;
}