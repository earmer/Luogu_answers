#include<cstdio>
#include<iostream>
#include<bitset>

using namespace std;

bitset<100005> mp[100005];
long long num = 0;

void paint(int a, int b, int c) {
	a *= 2, b *= 2, c *= 2;
	while (c--) {
		for (int i = b; i <= b + c + 1; i++) {
			num += !mp[i][a] - mp[i][b];
			mp[a][i] = !mp[a][i];
		}
		a++;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		paint(a, b, c);
	}
	cout << num << endl;
}