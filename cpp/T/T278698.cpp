#include<cstdio>
#include<iostream>
#define endl '\n';
#include<queue>
#include<cmath>
#include<algorithm>
#include <string>

using std::cin;
using std::cout;
using std::string;
//using endl;
using std::flush;
long long find;

int chan[10000];

std::priority_queue<int> Q;

void print() {
	find++;
	long long f;
	long long pin = 1;
	while (chan[pin] != 0) {
		f += chan[pin] - 1;
	}
	Q.push(f);
	return;
}

void dfs(int max, int now, int rest, int pin, int last) {
	if (rest == 1) {
		print();
		return;
	}
	int ma = (last < rest) ? last : rest;
	//ma = sqrt(ma);
	for (int i = 2; i <= ma; i++) {
		if (rest % i == 0) {
			chan[pin] = i;
			dfs(max, now * i, rest / i, pin + 1, i);
			chan[pin] = 0;
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	cin >> n;
	dfs(n, 1, n, 1, n);
	cout << find << endl;
	while (Q.empty()) {
		cout << Q.top() << ' ';
		Q.pop();
	}
	cout << '\n' << flush;
	return 0;
}