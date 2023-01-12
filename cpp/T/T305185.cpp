// Copyright (c) 2023. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2023/1/6.
//

#include <bits/stdc++.h>

#define int long long
using namespace std;

int read() {
    int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

int c[360361] = {};

signed main() {
    int a = read(), b = read(), d = read();
    if (d == 1) {
        printf("%lld\n", a);
        return 0;
    }
    if (d == 2) {
        printf("%lld\n", b);
        return 0;
    }
    d -= 2;
    c[0] = b, c[1] = a * b % 10;
    for (int i = 2; i <= 360360; ++i) {
        c[i] = c[i - 1] * c[i - 2] % 10;
    }
    printf("%lld\n", c[d % 360360]);
    return 0;
}

//signed main() {
//    for (int i = 1; i <= 9; i++) {
//        for (int j = 1; j <= 9; j++) {
//            printf("%d %d ", i, j);
//            int f1 = i, f2 = j;
//            for (int k = 1; k <= 20; k++) {
//                f2 = f1 * f2;
//                f1 = (f1 != 0) ? f2 / f1 : 0;
//                f2 %= 10;
//                printf("%d ", f2);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}