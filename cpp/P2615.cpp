// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/11.
//
#include <bits/stdc++.h>

using namespace std;
int N;
int Magic_square[40][40], cnt = 0;

int status(int x, int y) {// temp1 是行，temp2 是列
    if (x == 1) {
        if (y == N) {
            return 3;
        } else return 1;
    } else if (y == N) {
        return 2;
    } else {
        if (!Magic_square[x - 1][y + 1]) {
            return 4;
        }
        return 5;
    }
}

void solve(int x, int y, int n) {
    if (n > cnt) return;
    int temp = status(x, y);
    if (temp == 1) {
        Magic_square[N][++y] = ++n;
        solve(N, y, n);
        return;
    }
    if (temp == 2) {
        Magic_square[--x][1] = ++n;
        solve(x, 1, n);
        return;
    }
    if (temp == 3) {
        Magic_square[++x][y] = ++n;
        solve(x, y, n);
        return;
    }
    if (temp == 4) {
        Magic_square[--x][++y] = ++n;
        solve(x, y, n);
        return;
    }
    Magic_square[++x][y] = ++n;
    solve(x, y, n);
    return;
}

int main() {
    cin >> N;
    cnt = N * N;
    Magic_square[1][N / 2 + 1] = 1;
    solve(1, N / 2 + 1, 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < N; j++)
            cout << Magic_square[i][j] << " ";
        cout << Magic_square[i][N] << endl;
    }
    return 0;
}