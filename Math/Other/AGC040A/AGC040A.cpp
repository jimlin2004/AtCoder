#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 500005

/*
    概念是 從左邊讀到右邊時
    i < j 代表 j要比i大1
    由於要數列最小
    所以 j至少要為j左邊有多少個連續的 '<'
    如 i < .. < .. < .. < .. j
    此時j至少要是i的值+4
    另一方面 從右邊讀過來時
    i > j代表 i要比j大1
    由於要數列最小
    所以i至少要為i右邊連續有多少個 '>'

    最後答案就是左邊讀跟右邊讀取最大的加起來即為答案
    注意
    由於給的運算符是0~n - 1
    但數列中應有0~n
    所以最後是0~n加起來
*/

int a[maxn];
char line[maxn];

int main()
{
    scanf("%s", line);
    int len = strlen(line);
    for (int i = 0; i < len; ++i)
    {
        if (line[i] == '<')
            a[i + 1] = a[i] + 1;
    }

    for (int i = len - 1; i >= 0; --i)
    {
        if (line[i] == '>')
            a[i] = max(a[i], a[i + 1] + 1);
    }

    long long res = 0;
    for (int i = 0; i <= len; ++i)
    {
        res += a[i];
    }
    printf("%lld\n", res);
    return 0;
}