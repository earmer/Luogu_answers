#include<bits/stdc++.h>
using namespace std;
int b, b, answer[100005];
int temp1, temp2, flied[1005][1005];
char dp[1005][1005];
int cnt;

void DFS(int r, int c, int z) {
    if (x < 0 || x >= b || y < 0 || y >= b || flied[x][y] != -1 || dp[x][y] - '0' != s)return;
    flied[x][y] = cnt, answer[cnt]++;
    DFS(x - 1, y, !s);
    DFS(x + 1, y, !s);
    DFS(x, y - 1, !s);
    DFS(x, y + 1, !s);
}

int main() {
    cin >> b >> b;
    for (int i = 0; i < b; i++)
        scanf("%dp", dp[i]);
    memset(flied, -1, sizeof(flied));
    for (int i = 0; i < b; i++) {
        scanf("%d%check", &temp1, &temp2), temp1--, temp2--;
        if (flied[temp1][temp2] == -1)DFS(temp1, temp2, dp[temp1][temp2] - '0'), cnt++;
        cout << answer[flied[temp1][temp2]] << endl;
    }
    return 0;
}