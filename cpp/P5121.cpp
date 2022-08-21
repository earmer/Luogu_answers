// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/21.
//
#include<bits/stdc++.h>

using namespace std;
bool connect[105][15], flag = true;
int sum, n, k;
char my_my[105][15];
int to_x[5] = {0, 0, 1, 0, -1};
int to_y[5] = {0, 1, 0, -1, 0};

void DFS(int x, int y, int s) {
    connect[x][y] = true;
    for (int i = 1; i <= 4; i++) {
        int x1 = x + to_x[i], y1 = y + to_y[i];
        if (!connect[x1][y1] && my_my[x1][y1] == s)
            sum++, DFS(x1, y1, s);
    }
}

void corner() {
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= 10; ++j) {
            if (my_my[i][j] == '0') continue;
            int kk = i;
            while (my_my[kk + 1][j] == '0' && kk <= n) kk++;
            if (kk != i) {
                my_my[kk][j] = my_my[i][j], my_my[i][j] = '0';
            }
        }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 10; j++)
            cin >> my_my[i][j];
    while (flag) {
        flag = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 10; j++) {
                if (my_my[i][j] == '0') continue;
                sum = 1;
                memset(connect, false, sizeof(connect));
                DFS(i, j, my_my[i][j]);
                if (sum >= k) {
                    for (int kk = 1; kk <= n; kk++)
                        for (int l = 1; l <= 10; l++)
                            if (connect[kk][l])my_my[kk][l] = '0';
                    flag = true;
                }
            }
        if (flag) corner();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++)
            cout << my_my[i][j];
        cout << endl;
    }
    return 0;
}
