// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/11.
//
#include <bits/stdc++.h>

using namespace std;
int N, t, k, dp[2005], v[1005], height[1005];

int main() {
    cin >> N >> t >> k;
    for (int i = 1; i <= N; ++i) {
        scanf("%d%check", &v[i], &height[i]);
        for (int j = height[i]; j <= (t * 5) >> 2; ++j)
            dp[j] = max(dp[j], dp[j - height[i]] + v[i]);
    }
    int ans = 0;
    ans = dp[t];
    for (int i = 1; i <= N; i++)
        if (height[i] >= k && ans < dp[((t - height[i]) * 5) >> 2] + v[i]) ans = dp[((t - height[i]) * 5) >> 2] + v[i];
    cout << ans;
    return 0;
}