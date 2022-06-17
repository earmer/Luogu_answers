#include <bits/stdc++.h>

using namespace std;
int N, dp[5005][5005], tune[5005], ans = 0;

int look(int i, int j) { return max(ans, dp[i][j] = min(j - i - 1, dp[i - 1][j - 1] + 1)); }

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i)scanf("%d", &tune[i]);
    for (int i = N; i > 0; --i)tune[i] -= tune[i - 1];
    for (int i = 2; i <= N; ++i)for (int j = i + ans + 1; j <= N; ++j)if (tune[i] - tune[j] == 0) ans = look(i, j);
    printf("%d\n", (ans <= 3) ? 0 : ++ans);
    return 0;
}