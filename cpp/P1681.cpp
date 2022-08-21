// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<bits/stdc++.h>

using namespace std;
int N, ans;
int dp[65][270005], temp;

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &temp);
        dp[temp][i] = i + 1;
    }
    for (int i = 2; i <= 58; ++i)
        for (int j = 1; j <= N; ++j) {
            if (!dp[i][j]) dp[i][j] += dp[i - 1][dp[i - 1][j]];
            if (dp[i][j]) ans = i;
        }
    cout << ans;
}