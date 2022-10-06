
//
//add_executable(t4 "Competition/t4.cpp")

#include<cstdio>
#include<map>
#include<iostream>
#include <string>
#include <algorithm>
#include <random>
int n, k;
int mp[1005][1005];
int sum[1005][1005];

int find(int i, int j, int k) {
	int sm = 0;
	for (int ii = 0; ii <= k; ii++) {
		if (ii + i <= 0 || ii + i > n) continue;
		int jj1 = j - (k - ii) - 1, jj2 = j + (k - ii);
		if (jj1 < 0 || jj2 > n) continue;
		sm += sum[ii + i][jj2] - sum[ii + i][jj1];
	}
	for (int ii = -1; ii >= -k; ii--) {
		if (ii + i <= 0 || ii + i > n) continue;
		int jj1 = j - (k + ii) - 1, jj2 = j + (k + ii);
		if (jj1 < 0 || jj2 > n) continue;
		sm += sum[ii + i][jj2] - sum[ii + i][jj1];
	}
	return sm;
}

int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &mp[i][j]);
			sum[i][j] = sum[i][j - 1] + mp[i][j];
		}
	}
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mx = std::max(mx, find(i, j, k));
		}
	}
	std::cout << mx << std::endl;
	return 0;
}