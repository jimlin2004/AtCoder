#include <iostream>
#include <string>
using namespace std;

string dp[20];

void solve(int n)
{
    if (dp[n] != "" || n == 1)
    {
        cout << dp[n];
    }
    else
    {
        solve(n - 1);
        cout << " " << to_string(n) << " ";
        solve(n - 1);
        dp[n] = dp[n - 1] + " " + to_string(n) + " " + dp[n - 1];
    }
}

int main()
{
    for (int i = 0; i < 20; ++i)
        dp[i] = "";
    dp[1] = "1";
    int n;
    cin >> n;
    solve(n);
    cout << '\n';
    return 0;
}