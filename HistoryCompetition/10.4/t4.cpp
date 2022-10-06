#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <bitset>

using namespace std;

const int N = 3 * 1e4 + 10;

int wid;
//bool map[N][N];
//bool vis[N][N];
bitset<N>map[N];
bitset<N>vis[N];
//queue<string> q;

int toint(string s) {
	int n = 0, pin = 0;
	while (pin < s.length()) {
		n *= 10;
		n += s[pin++] - '0';
	}
	return n;
}

void push(int h, string str) {
	int a = str.find("-");
	if (a == -1) {
		map[h][toint(str)] = true;
	}
	else {
		string s = "";
		int from, to;
		for (int i = 0; i < a; i++) {
			s += str[i];
		}
		from = toint(s);
		//q.push(s);
		string k = "";
		for (int i = a + 1; i < str.length(); i++) {
			k += str[i];
		}
		to = toint(k);
		for (int i = from; i <= to; i++) {
			map[h][i] = true;
		}
		//q.push(k);
	}
	return;
}

int dir[4][2] = { {0,1},{0, -1}, {1, 0}, {-1, 0} };
struct node {
	int x, y;
	node(int xx, int yy) {
		x = xx;
		y = yy;
	}
};

queue<node> q;

bool check(int x, int y) {
	if (x > wid || x <= 0 || y > wid || y <= 0) return false;
	if (!map[x][y] || vis[x][y]) return false;
	return true;
}

priority_queue<int, vector<int>, less<int> > Q;

void print() {
	for (int i = 1; i <= wid; i++) {
		for (int j = 1; j <= wid; j++) {
			if (vis[i][j]) {
				cout << 1;
			}
			else cout << ' ';
		}
		cout << endl;
	}
}

void BFS(int x, int y) {
	q.push(node(x, y));
	vis[x][y] = true;
	int much = 0;
	while (!q.empty()) {
		much++;
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = now.x + dir[i][0];
			int ty = now.y + dir[i][1];
			if (check(tx, ty)) {
				q.push(node(tx, ty));
				vis[tx][ty] = true;
			}
		}
	}
	Q.push(much);
	//print();
}

int main()
{
	scanf("%d", &wid);
	string str;
	//getline(cin, str);
	for (int i = 1; i <= wid; i++) {
		cin >> str;
		string tmp = "";
		int pin = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == ',' || str[j] == ';') {
				push(i, tmp);
				tmp = "";
				continue;
			}
			tmp += str[j];
		}
	}
	for (int i = 1; i <= wid; i++) {
		for (int j = 1; j <= wid; j++) {
			if (!vis[i][j] && map[i][j]) {
				BFS(i, j);
			}
		}
	}
	//for (int i = 1; i <= wid; i++) {
	//	for (int j = 1; j <= wid; j++) {
	//		if (vis[i][j]) {
	//			cout << 1;
	//		}
	//		else cout << ' ';
	//	}
	//	cout << endl;
	//}
	while (!Q.empty()) {
		int count = 1;
		int want = Q.top();
		printf("%d ", want);
		Q.pop();
		while (!Q.empty() && Q.top() == want) {
			count++;
			Q.pop();
		}
		printf("%d\n", count);
	}
	return 0;
}
