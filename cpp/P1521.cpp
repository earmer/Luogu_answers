// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <bits/stdc++.h>

using namespace std;
// This program is answer for Mooyo Mooyo'dp problem.

bool graph[100][10];
int color_graph[100][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
const int width = 10;
int height, K;

void BFS(int x, int y) {
    int ans = 0;
    queue<int> qx;
    queue<int> qy;
    qx.push(x);
    qy.push(y);
    graph[x][y] = true;
    while (!qx.empty()) {
        int tx = qx.front();
        int ty = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx >= 0 && nx < width && ny >= 0 && ny < height && !graph[nx][ny]) {
                graph[nx][ny] = true;
                qx.push(nx);
                qy.push(ny);
                ++ans;
            }
        }
    }
    if (ans >= K) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (!graph[i][j])
                    color_graph[i][j] = 0;
            }
        }
    }
    memset(graph, false, sizeof(graph));
}

/*
 6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223
 */
int main() {
    cin >> height;
    cin >> K;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> color_graph[i][j];
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (color_graph[i][j]) {
                BFS(i, j);
            }
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << color_graph[i][j];
        }
        cout << endl;
    }
    return 0;
}