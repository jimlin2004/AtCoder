#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define maxn 470000

bool isPrime[maxn];
int prime[maxn];
int primeSize = 0;

void getPrimes()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < maxn; ++i)
    {
        if (isPrime[i])
            prime[primeSize++] = i;
        for (int j = 0; j < primeSize && i * prime[j] <= maxn; ++j)
        {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

map<int, int> mp;

void primeFactorization(long long n)
{
    for (int i = 0; i < primeSize; ++i)
    {
        if (prime[i] * prime[i] > n)
            break;
        if (n % prime[i])
            continue;
        while (n % prime[i] == 0)
        {
            mp[prime[i]]++;
            n /= prime[i];
        }
    }
}

int main()
{
    long long n;
    scanf("%lld", &n);
    getPrimes();
    primeFactorization(n);
    bool ok = true;
    bool first = true;
    int prev = 0;
    int a = 0;
    for (auto p: mp)
    {
        if (first)
        {
            first = false;
            prev = p.second;
            a = p.first;
        }
        else
        {
            if (p.second != prev)
            {
                ok = false;
                break;
            }
            a *= p.first;
        }
    }

    if (mp.size() == 0)
        ok = false;

    if (ok)
    {
        if (prev != a)
            ok = false;
    }

    if (ok)
    {
        printf("%d\n", a);
    }
    else
        printf("-1\n");
    return 0;
}