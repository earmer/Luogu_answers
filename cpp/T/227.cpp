// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/24.
//
#include <bits/stdc++.h>

using namespace std;
int n[1000005][6], ans = -1e10;

int main() {
    int N, d;
    cin >> N >> d;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= d; j++) {
            cin >> n[i][j];
        }
    }
    for (int i = 1; i < N; i++) {
        int temp = 0;
        for (int k = i + 1; k <= N; k++) {
            for (int j = 1; j <= d; j++) {
                temp += abs(n[k][j] - n[i][j]);
            }
            if (temp > ans)
                ans = temp;
            temp = 0;
        }
    }
    cout << ans << endl;
    return 0;
}