#include <iostream>
#include <string>
using namespace std;

void solve(string str, int leftCnt, int remain)
{
    if (leftCnt == 0 && remain == 0)
    {
        cout << str << '\n';
    }
    if (leftCnt > remain)
        return;
    if (leftCnt < 0)
        return;
    solve(str + '(', leftCnt + 1, remain - 1);
    solve(str + ')', leftCnt - 1, remain - 1);
}

int main()
{
    int n;
    cin >> n;
    solve("", 0, n);
    return 0;
}