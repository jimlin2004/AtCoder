#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

inline long long carDis(long long w, int A)
{
	return w * A;
}

inline long long trainDis(long long w, int B, int C)
{
	return w * B + C;
}

long long w[1001][1001];
bool visited[1001];
long long dis1[1001]; //從1出發，做車，也就是與city 1的距離
long long disN[1001]; //與從N出發，做火車，也就是與city N的距離

struct Item
{
	int u;
	long long w;
	bool operator < (const Item& other) const
	{
		return this->w > other.w;
	}
};

void dijkstarByCar(int N, int A, int B, int C, int s)
{
	memset(visited, 0, sizeof(visited));
	memset(dis1, 0x3f, sizeof(dis1));
	priority_queue<Item> pq;
	dis1[s] = 0;
	pq.push({s, dis1[s]});
	while (!pq.empty())
	{
		Item item = pq.top();
		pq.pop();
		visited[item.u] = true;
		for (int v = 1; v <= N; ++v)
		{
			if (visited[v])
				continue;
			if (dis1[v] > dis1[item.u] + carDis(w[item.u][v], A))
			{
				dis1[v] = dis1[item.u] + carDis(w[item.u][v], A);
				pq.push({v, dis1[v]});
			}
		}
	}
}

void dijkstarByTrain(int N, int A, int B, int C, int s)
{
	memset(visited, 0, sizeof(visited));
	memset(disN, 0x3f, sizeof(disN));
	priority_queue<Item> pq;
	disN[s] = 0;
	pq.push({s, disN[s]});
	while (!pq.empty())
	{
		Item item = pq.top();
		pq.pop();
		visited[item.u] = true;
		for (int v = 1; v <= N; ++v)
		{
			if (visited[v])
				continue;
			if (disN[v] > disN[item.u] + trainDis(w[item.u][v], B, C))
			{
				disN[v] = disN[item.u] + trainDis(w[item.u][v], B, C);
				pq.push({v, disN[v]});
			}
		}
	}
}

int main()
{
	int N, A, B, C;
	scanf("%d %d %d %d", &N, &A, &B, &C);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%lld", &w[i][j]);
		}
	}
	
	dijkstarByCar(N, A, B, C, 1);
	dijkstarByTrain(N, A, B, C, N);

	long long res = 0x3f3f3f3f3f3f3f3f;
	for (int k = 1; k <= N; ++k)
	{
		res = min(res, dis1[k] + disN[k]);
	}
	printf("%lld\n", res);
	return 0;
}