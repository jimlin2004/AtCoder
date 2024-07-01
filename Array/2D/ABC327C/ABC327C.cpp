#include <cstdio>
#include <cstring>
using namespace std;

int A[10][10];
bool check[10] = {false};

bool checkSubArray(int l, int r, int y)
{
    memset(check, false, sizeof(check));
    for (int i = l; i <= r; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (!check[A[i][y + j]])
            {
                check[A[i][y + j]] = true;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            scanf("%d", &A[i][j]);
        }
    }

    

    bool ok = true;

    for (int i = 1; i <= 9; ++i)
    {
        memset(check, false, sizeof(check));
        for (int j = 1; j <= 9; ++j)
        {
            if (!check[A[i][j]])
            {
                check[A[i][j]] = true;
            }
            else
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            break;
    }

    if (ok)
    {
        for (int j = 1; j <= 9; ++j)
        {
            memset(check, false, sizeof(check));
            for (int i = 1; i <= 9; ++i)
            {
                if (!check[A[i][j]])
                {
                    check[A[i][j]] = true;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
        }
    }

    int pos[] = {1, 4, 7};
    if (ok)
    {
        for (int y = 1; y <= 9; y += 3)
        {
            for (int i = 0; i < 3; ++i)
            {
                ok = checkSubArray(pos[i], pos[i] + 2, y);
                if (!ok)
                    break;
            }
            if (!ok)
                break;
        }
    }
    puts((ok) ? "Yes": "No");
    return 0;
}