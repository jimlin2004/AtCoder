#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int res = 0;
    int count = 0;
    int prev, curr;
    scanf("%d", &prev);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &curr);
        if (curr <= prev)
            ++count;
        else
        {
            if (count > res)
                res = count;
            count = 0;
        }
        prev = curr;
    }
    if (count > res)
        res = count;
    printf("%d\n", res);
    return 0;
}