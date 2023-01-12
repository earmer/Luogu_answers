// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/10.
//

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

//int ary[1000005];
int limit, a, b, c, d;

int cnt[100000], cnm[100000];
const int p = 50000;

int main() {
    scanf("%d%d%d%d%d", &limit, &a, &b, &c, &d);
    if (a > 0 && b > 0 && c > 0 && d > 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= limit; i++) {
        for (int j = 1; j <= limit; j++) {
            cnt[i * a + j * b + p]++;
        }
    }
    for (int i = 1; i <= limit; i++) {
        for (int j = 1; j <= limit; j++) {
            cnm[-i * c - j * d + p]++;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 99999; i++) {
        ans += min(cnt[i], cnm[i]);
    }
    printf("%d\n", ans * 16);
    return 0;
}