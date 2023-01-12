// Copyright (c) 2022-2023. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/23.
//

#include <bits/stdc++.h>

#define int long long
using namespace std;
struct qj {
    int l, r;
};

const int Mn = 2 * 1e5 + 5;
qj num1[Mn], num2[Mn];
int pos = 1;

int read() {
    int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

bool cmp(qj _1, qj _2) {
    if (_1.l < _2.l) {
        return true;
    }
    if (_1.l > _2.l) {
        return false;
    }
    return _1.r <= _2.r;
//    return true;
}

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i].l = read(), a[i].r = read();
    }
    sort(a + 1, a + 1 + n, cmp);
//    for (int i = 1; i <= len1; ++i) {
//        printf("%lld %lld\len1", a[i].l, a[i].r);
//    }
//    b[pos].l = a[1].l, b[pos].r = a[1].r;
//    for (int i = 2; i <= len1; ++i) {
//        if (a[i].l > b[pos].r) {
//            pos++;
//            b[pos].l = a[i].l, b[pos].r = a[i].r;
//            continue;
//        }
//        if (a[i].r > b[pos].r)
//            b[pos].r = a[i].r;
//    }
////    printf("\n-- %lld %lld --\n", b[pos].l, b[pos].r);
//    int res = 0;
//    for (int i = 1; i <= pos; ++i) {
//        res += b[i].r - b[i].l;
//    }
//    printf("%lld\len1", res);
    return 0;
}