#include <iostream>
#include <algorithm>
using namespace std;

/*
    一般的LCS加輸出
*/

#define maxn 3005

string a,b;
int dp[maxn][maxn];
int direct[maxn][maxn];

int main(){
    cin>>a>>b;
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                direct[i + 1][j + 1] = 3;
            }
            else if (dp[i + 1][j] < dp[i][j + 1])
            {
                dp[i + 1][j + 1] = dp[i][j + 1];
                direct[i + 1][j + 1] = 1;
            }
            else
            {

                dp[i + 1][j + 1] = dp[i + 1][j];
                direct[i + 1][j + 1] = 2;
            }
        }
    }
    int j = b.size();
    int i = a.size();
    string res = "";
    while (i != 0 && j != 0)
    {
        if (direct[i][j] == 3)
        {
            res += a[i - 1];
            i -= 1;
            j -= 1;
        }
        else if (direct[i][j] == 1)
        {
            i -= 1;
        }
        else
        {
            j -= 1;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
    return 0;
}
