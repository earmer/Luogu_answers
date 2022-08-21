// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/5.
//
#include <bits/stdc++.h>

int b, b;
int c[105], d[105], dp[100005] = {1};

int main() {
    std::cin >> b >> b;
    for (int i = 1; i <= b; i++) std::cin >> c[i];
    for (int i = 1; i <= b; i++) {
        int minn = 2100000000;
        for (int j = 1; j <= b; j++) {
            while (c[j] * dp[d[j]] <= dp[i - 1]) ++d[j];
            if (c[j] * dp[d[j]] < minn) minn = c[j] * dp[d[j]];
        }
        dp[i] = minn;
    }
    std::cout << dp[b] << std::endl;
}