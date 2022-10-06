#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
//#include <stdio.h>
// 在 150ms 时限下，需开 O2
using namespace std;

int n, m;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

struct _Slide
{
	int x, y, length;
	_Slide() {}
	_Slide(int a, int b, int c)
	{
		x = a, y = b, length = c;
	}
	bool operator<(const _Slide a) const
	{
		return a.length < length;
	}
};

//vector<_Slide> points[505][505];
_Slide point[505][505][5];
int now[505][505];
int dist[505][505];
bool visit[505][505];
const int INF = 2147483647;

void print_dist() {
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= m + 1; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void Dijkstra()
{
	memset(visit, false, sizeof(visit));
	priority_queue<_Slide> Q; // 优先队列优化
	Q.push(_Slide(1, 1, 0));  // 推入初始点
	for (int i = 0; i <= 503; ++i)
		for (int j = 0; j <= 503; ++j)
			dist[i][j] = INF; // 设为最大值
	dist[1][1] = 0;			  // 将初始点设为0
	while (!Q.empty())
	{ // 没有可以扩展的点时停止
		_Slide nd = Q.top();
		Q.pop();
		if (visit[nd.x][nd.y]) continue;
		visit[nd.x][nd.y] = true;
		for (int i = 1; i <= now[nd.x][nd.y]; i++)
		{
			_Slide et = point[nd.x][nd.y][i];
			int x = et.x, y = et.y, w = et.length;
			if (dist[x][y] > dist[nd.x][nd.y] + w)
			{
				dist[x][y] = dist[nd.x][nd.y] + w;
				Q.push(_Slide(x, y, dist[x][y]));
			}
		}
	}
}

void make(char a, int x, int y)
{
	if (a == '/')
	{
		point[x][y][++now[x][y]] = _Slide(x + 1, y + 1, 1);
		point[x + 1][y + 1][++now[x + 1][y + 1]] = _Slide(x, y, 1);
		point[x][y + 1][now[x][y + 1]] = _Slide(x + 1, y, 0);
		point[x + 1][y][now[x + 1][y]] = _Slide(x, y + 1, 0);
		return;
	}
	else if (a == '\\')
	{
		point[x][y][++now[x][y]] = _Slide(x + 1, y + 1, 0);
		point[x + 1][y + 1][++now[x + 1][y + 1]] = _Slide(x, y, 0);
		point[x][y + 1][now[x][y + 1]] = _Slide(x + 1, y, 1);
		point[x + 1][y][now[x + 1][y]] = _Slide(x, y + 1, 1);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	if ((n + m) % 2 == 1) {
		printf("NO SOLUTION\n");
		return 0; // 第一处优化
	}
	char a;
	getchar();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{

			//fgets(a, 1, stdin);
			a = getchar();
			make(a, i, j);
			//cout << a << endl;
		}
		getchar();
	}
	Dijkstra();
	if (dist[n + 1][m + 1] == INF) {
		printf("NO SOLUTION\n");
	}
	else printf("%d\n", dist[n + 1][m + 1]);
	return 0;
}