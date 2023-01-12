// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/11/11.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::queue;

int n;
int mp[59][59];
int vis[59][59];

struct poi {
    int x, y;
};

void bfs(int i, int j) {
    if (mp[i][j] == 1) return;
    queue<poi> pos, his;
    pos.push({i, j});
    while (!pos.empty()) {
        poi tmp = pos.front();
        pos.pop();
        if (vis[tmp.x][tmp.y]) continue;
        vis[tmp.x][tmp.y] = 1;
        if (tmp.x < 1 || tmp.x > n || tmp.y < 1 || tmp.y > n) continue;
        if (mp[tmp.x + 1][tmp.y] < 1) pos.push({tmp.x + 1, tmp.y});
        if (mp[tmp.x - 1][tmp.y] < 1) pos.push({tmp.x - 1, tmp.y});
        if (mp[tmp.x][tmp.y + 1] < 1) pos.push({tmp.x, tmp.y + 1});
        if (mp[tmp.x][tmp.y - 1] < 1) pos.push({tmp.x, tmp.y - 1});
    }
    // while(!his.empty()) {
    //     poi tmp = his.front();
    //     his.pop();
    //     mp[a][b] = 2;
    // }
    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= n; j++)
    //         cout << mp[i][j];
    // exit(0);
}

//void pt() {
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (mp[i][j] == 0 && vis[i][j] == 1) cout << 0 << ' ';
//            else if (mp[i][j] == 1) cout << 1 << ' ';
//            else cout << 2 << ' ';
//        }
//        cout << std::endl;
//    }
//}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n; i++) {
        bfs(i, 1), bfs(1, i), bfs(i, n), bfs(n, i);
        //vis[i][1] = vis[1][i] = vis[i][n] = vis[n][i] = 1;
//        pt();
//        cout << std::endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == 0 && vis[i][j] == 1) cout << 0 << ' ';
            else if (mp[i][j] == 1) cout << 1 << ' ';
            else cout << 2 << ' ';
        }
        cout << std::endl;
    }
//    cout << std::endl;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << vis[i][j];
//        }
//        cout << std::endl;
//    }
    return 0;
}
