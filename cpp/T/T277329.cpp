#include<cstdio>
#include<iostream>
#include<algorithm>


//using namespace std;
std::string s;
const int maxn = 8005;
const int p = 8001;

int st_x[maxn], st_y[maxn], count_x, count_y;
int st_total[maxn], count_total;
bool fx[maxn][2 * maxn], fy[maxn][2 * maxn];


void deal() {
	int pin = 0;
	int max = s.length();
	for (; pin < max; pin++) {
		if (s[pin] == 'T') break;
	}
	printf("PIN: %d\n", pin);
	fx[0][pin] = true;
	fy[0][0] = true;
	//count_total++;
	for (; pin < max; pin++) {
		if (s[pin] == 'T') {
			count_total++;
			continue;
		}
		if (s[pin] == 'F') {
			st_total[count_total]++;
			continue;
		}
	}
	for (int i = 1; i <= count_total; i++) {
		if (i % 2 == 1) {
			st_y[++count_y] = st_total[i];
		}
		else st_x[++count_x] = st_total[i];
	}
	printf("X: %d, Y: %d\n", count_x, count_y);
	return;
}

int main() {
	std::cin >> s;
	deal();
	// Dp X Row
	for (int i = 1; i <= count_x; i++) {
		for (int j = -8001; j <= 8001; j++) {
			if (fx[i - 1][j - st_x[i] + p] || fx[i - 1][j + st_x[i] + p])
				fx[i][j + p] = true;
		}
	}
	// Dp Y Row
	for (int i = 1; i <= count_y; i++) {
		for (int j = -8001; j <= 8001; j++) {
			if (fy[i - 1][j - st_y[i] + p] || fy[i - 1][j + st_y[i] + p])
				fy[i][j + p] = true;
		}
	}
	int gainx, gainy;
	scanf("%d%d", &gainx, &gainy);
	if (fx[count_x][gainx + p] && fy[count_y][gainy + p])
		std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	return 0;
}