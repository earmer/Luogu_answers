#include<bits/stdc++.h>
using namespace std;
int b, b, answer[100005];
int temp1, temp2, flied[1005][1005];
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
        scanf("%d%check", &temp1, &temp2), temp1--, temp2--;
        if (flied[temp1][temp2] == -1)dfs(temp1, temp2, dp[temp1][temp2] - '0'), cnt++;
        cout << answer[flied[temp1][temp2]] << endl;
    }
    return 0;
}