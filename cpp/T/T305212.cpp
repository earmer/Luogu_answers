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

int tk[100005];

int N, GD;

int check(int gra) {
    int now = 0;
    int grd = 0;
    for (int i = 1; i <= N; i++) {
        now += tk[i];
        if (now < 0) now = 0;
        if (now >= gra) now = 0, grd++;
    }
    if (grd > GD) return 1;
    if (grd < GD) return -1;
    return 0;
}

signed main() {
    N = read(), GD = read();
    if (GD == 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        tk[i] = read();
    }

//    int bg = l + 10;
//    while (check(bg) != 0) {
//        --bg;
//        if (bg < 1) {
//            printf("-1\n");
//            return 0;
//        }
//    }
    int l = 0, r = 210000000000;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid) == 1) {
            l = mid + 1;
        } else r = mid;
    }
    int l1 = l;
    l = 0, r = 210000000000;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid) == -1) {
            r = mid;
        } else l = mid + 1;
    }
    int l2 = l - 1;
    if (l2 < l1) {
        printf("-1\n");
        return 0;
    }
    printf("%lld %lld\n", l1, l2);
//    int sm = l - 5;
//    if (sm < 1) {
//        sm = 1;
//    }
//    while (check(sm) != 0) {
//        ++sm;
//        if (sm > bg) {
//            printf("-1\n");
//            return 0;
//        }
//    }
//    printf("%lld %lld", sm, bg);
    return 0;
}
/*
 * 5 2
 * 10
 * -7
 * 3
 * 1
 * 2
 */