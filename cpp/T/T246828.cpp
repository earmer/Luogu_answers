// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/22.
//
#include <bits/stdc++.h>

using namespace std;
int num[100005], Sum_Array[100005];
int dp[10005][1550];

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    for (long long i = 1; i <= n; i++) {
        cin >> num[i];
        Sum_Array[i] = Sum_Array[i - 1] + num[i];
    }

    for (int i = k; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i - 1][j] > dp[i - k][j - 1] + Sum_Array[i] - Sum_Array[i - k]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - k][j - 1] + Sum_Array[i] - Sum_Array[i - k];
        }
    }
    cout << dp[n][m];
    return 0;
}