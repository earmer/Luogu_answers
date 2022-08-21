// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/14.
//
#include<bits/stdc++.h>

using namespace std;
int N, m;
int b[2005][2005], dp[2005][2005];

int main() {
    scanf("%d%d", &N, &m);
    for (int i = 1; i <= m; ++i)for (int j = 1; j <= N; ++j)scanf("%d", &b[j][i]);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = min(dp[i - 1][j], (j == 1) ? dp[i - 1][m] : dp[i - 1][j - 1]) + b[i][j];
    int ans = 2100000000;
    for (int i = 1; i <= m; ++i)ans = min(ans, dp[N][i]);
    printf("%d", ans);
    return 0;
}
