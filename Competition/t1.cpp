#include<cstdio>

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		printf("%d\n", (min(t1, t2) - 1) * 2);
	}
	return 0;
}