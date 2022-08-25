// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/21.
//

#include <bits/stdc++.h>

using namespace std;

int dp[55][55][55][55], a[55][55];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
//    cout << "%2" << endl;
    for (int j = 1; j <= m; j++)
        for (int k = 1; k <= n; k++)
            for (int l = 1; l <= m; l++)
                for (int o = k + 1; o <= n; o++) {
                    dp[j][k][l][o] = max(max(dp[j][k - 1][l - 1][o], dp[j - 1][k][l][o - 1]),
                                         max(dp[j][k - 1][l][o - 1], dp[j - 1][k][l - 1][o])) + a[j][k] + a[l][o];
//                    cout << "%1" << endl;
                }
//    cout << '%' << endl;
    cout << dp[m][n - 1][m - 1][n] << endl;
    return 0;
}