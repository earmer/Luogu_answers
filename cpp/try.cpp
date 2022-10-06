#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

// struct _Pos{
// 	int x, y, steps;
// 	_Pos(){}
// 	_Pos(int a, int b, int c) {
// 		x = a, y = b, steps = c;
// 	}

// };
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

// 使用Node来作图的储存

vector<_Slide> points[505][505];

int dist[505][505];
bool visit[505][505];
const int INF = 2147483647;

//void print_dist() {
//	for (int i = 1; i <= n + 1; i++) {
//		for (int j = 1; j <= m + 1; j++) {
//			cout << dist[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//}

/* 很有问题的 DJ 过程
0 E E E E E
E 0 E E E E
E E E E E E
E E E E E E

0 E 1 E E E
E 0 E E E E
1 E 0 E E E
E E E E E E

0 E 1 E E E
E 0 E 2 E E
1 E 0 E E E
E E E E E E

0 E 1 E 3 E
E 0 E 2 E E
1 E 0 E 3 E
E E E E E E

0 E 1 E 3 E
E 0 E 2 E 3
1 E 0 E 3 E
E E E E E E

0 E 1 E 3 E
E 0 E 2 E 3
1 E 0 E 3 E
E E E 4 E 3

0 E 1 E 3 E
E 0 E 2 E 3
1 E 0 E 3 E
E E E 4 E 3

0 E 1 E 3 E
E 0 E 2 E 3
1 E 0 E 3 E
E E E 4 E 3

0 E 1 E 3 E
E 0 E 2 E 3
1 E 0 E 3 E
E E E 4 E 3

0 E 1 E 3 E
E 0 E 2 E 3
1 E 0 E 3 E
E 2 E 4 E 3

0 E 1 E 3 E
E 0 E 2 E 3
1 E 0 E 3 E
E 2 E 4 E 3

0 E 1 E 3 E
E 0 E 0 E 3
1 E 0 E 3 E
E 1 E 0 E 3
*/

void Dijkstra()
{
	memset(visit, false, sizeof(visit));
	priority_queue<_Slide> Q; // 优先队列优化
	Q.push(_Slide(1, 1, 0));  // 推入初始点
	Q.push(_Slide(3, 2, 100));
	Q.push(_Slide(1, 2, 3));
	while (!Q.empty()) {
		cout << Q.top().length << ' ';
		Q.pop();
	}
	//for (int i = 0; i <= 503; ++i)
	//	for (int j = 0; j <= 503; ++j)
	//		dist[i][j] = INF; // 设为最大值
	//dist[1][1] = 0;			  // 将初始点设为0
	//while (!Q.empty())
	//{ // 没有可以扩展的点时停止
	//	_Slide nd = Q.top();
	//	Q.pop();
	//	if (visit[nd.x][nd.y])
	//		continue;
	//	visit[nd.x][nd.y] = true;
	//	//printf("[%d][%d] --> ");
	//	for (vector<_Slide>::iterator ed = points[nd.x][nd.y].begin(); ed != points[nd.x][nd.y].end(); ed++)
	//	{
	//		_Slide et = *ed;
	//		int x = et.x, y = et.y, w = et.length;
	//		/*if (visit[x][y])
	//			continue;*/
	//		if (dist[x][y] > dist[nd.x][nd.y] + w)
	//		{
	//			dist[x][y] = dist[nd.x][nd.y] + w;
	//			Q.push(_Slide(x, y, dist[x][y]));
	//		}
	//	}
	//	//print_dist();
	//}
}


// 完全没有问题的建图部分::begin()
//void make(char a, int x, int y)
//{
//	if (a == '/')
//	{
//		points[x][y].push_back(_Slide(x + 1, y + 1, 1));
//		points[x + 1][y + 1].push_back(_Slide(x, y, 1));
//		points[x][y + 1].push_back(_Slide(x + 1, y, 0));
//		points[x + 1][y].push_back(_Slide(x, y + 1, 0));
//		return;
//	}
//	else if (a == '\\')
//	{
//		points[x][y].push_back(_Slide(x + 1, y + 1, 0));
//		points[x + 1][y + 1].push_back(_Slide(x, y, 0));
//		points[x][y + 1].push_back(_Slide(x + 1, y, 1));
//		points[x + 1][y].push_back(_Slide(x, y + 1, 1));
//	}
//	// bool f = (a == '\\') ? true : false;
//	// points[x][y].push_back({x + 1, y + 1, f});
//	// points[x + 1][y + 1].push_back({x, y, f});
//	// points[x][y + 1].push_back({x + 1, y, !f});
//	// points[x + 1][y].push_back({x, y + 1, !f});
//}

//  x    x+1
// y+1 x+1,y+1
//

int main()
{
	//cin >> n >> m;
	/*for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char a;
			cin >> a;
			make(a, i, j);
		}
	}*/
	//printf("\n");
	//for (int i = 1; i <= n + 1; i++)
	//{
	//	for (int j = 1; j <= m + 1; ++j)
	//	{
	//		printf("points[%d][%d] --> ", i, j);
	//		for (auto eq : points[i][j])
	//		{
	//			printf("[%d][%d](%d) ", eq.x, eq.y, eq.length);
	//			//if(eq.y > j) {
	//			//	if(eq.length){
	//			//		cout << '/';
	//			//	}
	//			//	else cout << '\\';
	//			//}
	//		}
	//		printf("\n");
	//	}
	//	printf("\n");
	//}
// 完全没有问题的建图部分::end()

	// }
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 	}
	// }
	Dijkstra();
	//cout << dist[n + 1][m + 1] << endl;
	return 0;
	// system("Pause");
}