// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/11.
//
#include <bits/stdc++.h>

using namespace std;
int N, sum;
bool vised[25];
int ans[25], pc[25];

bool DFS(int i, int num, int v) {
    if (s > sum)
        return false;
    if (x == N) {
        if (s == sum) {
            ans[x] = y;
            return true;
        }
        return false;
    }
    vised[y] = true;
    for (int j = 1; j <= N; j++)
        if (!vised[j] && DFS(x + 1, j, s + pc[x] * j)) {
            ans[x] = y;
            return true;
        }
    vised[y] = false;
    return false;
}

int main() {
    cin >> N >> sum;
    pc[0] = pc[N - 1] = 1;
    if (N > 1)
        for (int i = 1; i * 2 <= N; i++)
            pc[i] = pc[N - 1 - i] = (N - i) * pc[i - 1] / i;
    if (DFS(0, 0, 0)) {
        for (int i = 1; i < N; i++)
            cout << ans[i] << " ";
        cout << ans[N] << endl;
    }
    return 0;
}