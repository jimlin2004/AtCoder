#include <iostream>
#include <queue>
using namespace std;

//經典BFS踩地雷

char grid[55][55];
int h, w;
int cnt[55][55];

int dir[8][2] = {
    {0, 1}, {-1, 1}, {-1, 0}, {-1, -1},
    {0, -1}, {1, -1}, {1, 0}, {1, 1}
};

inline bool isVaild(int x, int y)
{
    return (x > 0) && (x <= w) && (y > 0) && (y <= h);
}

queue<pair<int, int>> q;
void bfs()
{
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int d = 0; d < 8; ++d)
        {
            int newX = p.first + dir[d][0];
            int newY = p.second + dir[d][1];
            if (isVaild(newX, newY) && grid[newY][newX] != '#')
            {
                ++cnt[newY][newX];
            }
        }
    }
}

int main()
{
    cin >> h >> w;
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '#')
                q.push({j, i});
        }
    }

    bfs();

    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (grid[i][j] != '#')
                cout << cnt[i][j];
            else
                cout << '#';
        }
        cout << '\n';
    }

    return 0;
}