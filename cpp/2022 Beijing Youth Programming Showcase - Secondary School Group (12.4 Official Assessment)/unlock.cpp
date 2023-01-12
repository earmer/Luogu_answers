// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/4.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

double cal[19];
int last[19] = {1, 1};
bool vis[19];

double max = -1;
int n, m, k;
int sm;

double mx(double a, double b) {
    return a > b ? a : b;
}

double calculate(int a, int b) {
    if (a > b) std::swap(a, b);
    int ca = (a - 1) % m + 1, cb = (b - 1) % m + 1, la = (a + n - 1) / n, lb = (b + n - 1) / n;
    return sqrt((cb - ca) * (cb - ca) + (lb - la) * (lb - la));
}

void q(int now) {
    if (now == k) {
        double tmp = 0;
        for (int i = 1; i < k; i++) {
            tmp += cal[i];
        }
        max = mx(tmp, max);
        return;
    }
    for (int j = 2; j <= sm; j++) {
        if (!vis[j]) {
            vis[j] = true;
            cal[now] = calculate(last[now], j);
            last[now + 1] = j;
            q(now + 1);
            vis[j] = false;
        }
    }
}

int main() {
//    freopen("unlock.in", "r", stdin);
//    freopen("unlock.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    sm = n * m;
    q(1);
    printf("%.4f\n", max);
    return 0;
}