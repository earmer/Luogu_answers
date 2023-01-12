// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/5.
//

#include <cstdio>
#include <iostream>

long long total;
long long row[2000005] = {0, 1, 0, 1};

int main() {
    int mv;
    int center;
    scanf("%d", &mv);
    center = mv + 1;
    for (int i = 2; i < center; i++) {
        for (int j = 2 * i - 1; j > 0; j -= 2) {
            row[j + 2] += row[j];
            row[j + 2] %= 998244353;
        };
    }
    for (int i = 2 * center - 1; i >= center; i -= 2) {
        total += row[i] * (i - center);
        total %= 998244353;
//        printf("%lld\n", row[i] * (i - center));
    }
    printf("%lld", total * 2 % 998244353);
    return 0;
}