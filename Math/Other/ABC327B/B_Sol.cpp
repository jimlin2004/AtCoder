#include <cstdio>
using namespace std;

//由於最多10^18，所以其實只要搜最多15^15就行

int main()
{
    long long B;
    scanf("%lld", &B);
    int res = -1;
    for (int A = 1; A <= 15; ++A)
    {
        long long x = 1;
        for (int i = 1; i <= A; ++i)
            x *= A;
        if (x == B)
        {
            res = A;
            break;
        }
    }

    printf("%d\n", res);
    return 0;
}