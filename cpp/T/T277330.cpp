#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

// 在 150ms 时限下，需开 O2
using namespace std;

int n, m;
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

vector<_Slide> points[505][505];

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
		for (vector<_Slide>::iterator ed = points[nd.x][nd.y].begin(); ed != points[nd.x][nd.y].end(); ed++)
		{
			_Slide et = *ed;
			int x = et.x, y = et.y , w = et.length;
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
		points[x][y].push_back(_Slide(x + 1, y + 1, 1));
		points[x + 1][y + 1].push_back(_Slide(x, y, 1));
		points[x][y + 1].push_back(_Slide(x + 1, y, 0));
		points[x + 1][y].push_back(_Slide(x, y + 1, 0));
		return;
	}
	else if (a == '\\')
	{
		points[x][y].push_back(_Slide(x + 1, y + 1, 0));
		points[x + 1][y + 1].push_back(_Slide(x, y, 0));
		points[x][y + 1].push_back(_Slide(x + 1, y, 1));
		points[x + 1][y].push_back(_Slide(x, y + 1, 1));
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char a;
			cin >> a;
			make(a, i, j);
		}
	}
	Dijkstra();
	if (dist[n + 1][m + 1] == INF) {
		cout << "NO SOLUTION" << endl;
	}
	else cout << dist[n + 1][m + 1] << endl;
	return 0;
}