// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/23.
//

#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct node {
    int x, y, d;
};
char mapp[105][105], sx, sy, ex, ey;
int dp[105][105], tx[5] = {0, 0, 1, 0, -1}, ty[5] = {0, 1, 0, -1, 0};
queue<node> q;

int deal(int x, int y, int n, int now) {
    while (mapp[x][y] != 'x') {
        if (!dp[x][y] and (x != sx && y != ey)) {
            dp[x][y] = now + 1;
            q.push({x, y, n});
        }
        x += tx[n], y += ty[n];
    }
}

void man1() {
    return mapp[]
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> mapp[i][j];
            if (mapp[i][j] == 'A') sx = i, sy = j;
            if (mapp[i][j] == 'B') ex = i, ey = j;
        }
    for (int i = 1; i <= n; i++) mapp[0][i] = mapp[i][0] = mapp[n][i] = mapp[i][n];
    q.push({sx, sy, 0});
    while (!q.empty()) {
        node frt = q.front();
        for (int i = 1; i <= 4; i++) {
            deal(frt.x, frt.y, i, dp[frt.x][frt.y]);
        }
        q.pop();
    }
    cout << dp[ex][ey] << endl;
    return 0;
}