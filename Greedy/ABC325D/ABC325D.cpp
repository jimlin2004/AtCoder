#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    基本上是排程Greedy
    先將Segment以l在r sort
    之後以每個Segment的r最小的先選
*/

struct Segment
{
    long long l, r;
    bool operator < (const Segment& other) const
    {
        return this->r > other.r;
    }
};

vector<Segment> segments;

int main()
{
    int n;
    scanf("%d", &n);
    long long l, r;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld %lld", &l, &r);
        segments.push_back({l, l + r});
    }

    sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
        if (a.l == b.l)
            return a.r < b.r;
        return a.l < b.l;
    });

    priority_queue<Segment> pq;
    int res = 0;
    long long currT = 1;
    int index = 0;
    while (1)
    {
        if (pq.empty())
        {
            if (index == n)
                break;
            currT = segments[index].l;
        }
        while (index < n && (segments[index].l == currT))
        {
            pq.push(segments[index]);
            ++index;
        }

        while (!pq.empty() && pq.top().r < currT)
        {
            pq.pop();
        }
        if (!pq.empty())
        {
            pq.pop();
            ++res;
        }
        ++currT;
    }

    printf("%d\n", res);
    return 0;
}