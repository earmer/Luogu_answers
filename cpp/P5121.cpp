//
// Created by Work on 2022/6/21.
//
#include<bits/stdc++.h>

using namespace std;
bool connect[105][15], f = true;
int sum, n, k;
char ch[105][15];
int to_x[5] = {0, 0, 1, 0, -1};
int to_y[5] = {0, 1, 0, -1, 0};

void dfs(int x, int y, int s) {
    connect[x][y] = true;
    for (int i = 1; i <= 4; i++) {
        int xx = x + to_x[i], yy = y + to_y[i];
        if (connect[xx][yy] == 0 && ch[xx][yy] == s)
            sum++, dfs(xx, yy, s);
    }
}

void corner() {
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= 10; ++j) {
            if (ch[i][j] == '0') continue;
            int kk = i;
            while (ch[kk + 1][j] == '0' && kk <= n) kk++;
            if (kk != i) {
                ch[kk][j] = ch[i][j],ch[i][j] = '0';
            }
        }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 10; j++)
            cin >> ch[i][j];
    while (f) {
        f = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 10; j++) {
                if (ch[i][j] == '0') continue;
                sum = 1;
                memset(connect, false, sizeof(connect));
                dfs(i, j, ch[i][j]);
                if (sum >= k) {
                    for (int kk = 1; kk <= n; kk++)
                        for (int l = 1; l <= 10; l++)
                            if (connect[kk][l]) {
                                ch[kk][l] = '0';
                            }
                    f = true;
                }
            }
        if (f) corner();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << ch[i][j];
        }
        cout << endl;
    }
    return 0;
}
