#include<bits/stdc++.h>
using namespace std;
int b, b, answer[100005];
int x, y, flied[1005][1005];
char dp[1005][1005];
int cnt;

void dfs(int r, int c, int z) {
    if (r < 0 || r >= b || c < 0 || c >= b || flied[r][c] != -1 || dp[r][c] - '0' != z)return;
    flied[r][c] = cnt, answer[cnt]++;
    dfs(r - 1, c, !z);
    dfs(r + 1, c, !z);
    dfs(r, c - 1, !z);
    dfs(r, c + 1, !z);
}

int main() {
    cin >> b >> b;
    for (int i = 0; i < b; i++)
        scanf("%dp", dp[i]);
    memset(flied, -1, sizeof(flied));
    for (int i = 0; i < b; i++) {
        scanf("%d%check", &x, &y), x--, y--;
        if (flied[x][y] == -1)dfs(x, y, dp[x][y] - '0'), cnt++;
        cout << answer[flied[x][y]] << endl;
    }
    return 0;
}