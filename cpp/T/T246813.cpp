// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/30.
//

#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<vector<int> > city;

void read(int n) {
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        city.push_back(vector<int>(l, r));
        city.push_back(vector<int>(r, l));
    }
}

struct street {
    int id, deep;
};

int find(int nd) {
    vector<int>::iterator i;
    queue<street> q;
    vector<int> visit;
    q.push({*i, 0});
    visit.push_back(*i);
    while (!q.empty()) {
        street jie = q.front();
        q.pop(); // remove the front
        vector<int>::iterator j;
        for (j = visit.begin(); j != visit.end(); j++) {

        }
    }
}

char tu[105][105];
int n, sx, sy, ex, ey;
int much[105][105];
int tx[5] = {0, 0, 1, 0, -1}, ty[5] = {0, 1, 0, -1, 0};

struct node {
    int x, y, gd;
};

queue<node> q;

bool check(int x, int y) {
    if (tu[x][y] == 'x') return false;
    else return true;
}

int bfs(int xx, int yy) {
    q.push({xx, yy, 0});
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++) {
            node tm = p;
            tm.x += tx[i], tm.y += ty[i];
            while (check(tm.x, tm.y)) {
                if (tu[tm.x][tm.y] == 'B') return tm.gd;
                tu[tm.x][tm.y] = 'x';
                q.push({tm.x, tm.y, tm.gd + 1});
                tm.x += tx[i], tm.y += ty[i];
            }
        }
    }
    return -1;
}

signed main() {
//    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tu[i][j];
            if (tu[i][j] == 'x') continue;
            if (tu[i][j] == 'A') sx = i, sy = j, tu[i][j] = 'x';
            if (tu[i][j] == 'B') ex = i, ey = j;
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        tu[i][n + 1] = tu[i][0] = tu[0][i] = tu[n + 1][i] = 'x';
    }
    cout << bfs(sx, sy) << endl;
    return 0;
}