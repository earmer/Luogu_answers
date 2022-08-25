// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/22.
//
#include <bits/stdc++.h>

using namespace std;
long long q, n;
long long St_Max[50000][40];
long long PowNum[40] = {1};

void Pn(int i) {
    for (int j = 1; j <= i; j++)
        PowNum[j] = PowNum[j - 1] << 1;
}

long long publ(long long x, long long y) {
    if (y > x) swap(y, x);
    int z = 1;
    while (z)
        z = x % y, x = y, y = z;
    return x;
}

int main() {

    cin >> q >> n;
    Pn(32);
//	return 0;
    for (int i = 1; i <= q; i++)
        cin >> St_Max[i][0];

    for (int j = 1; (1 << j) <= q; j++)
        for (int i = 1; i + (1 << j) - 1 <= q; i++) {
            St_Max[i][j] = publ(St_Max[i][j - 1], St_Max[i + (1 << (j - 1))][j - 1]);
        }
//	return 0;
    for (int i = 1; i <= n; i++) {
        long long a, b, c;
        cin >> a >> b;
        c = log2(b - a + 1);
//		return 0;
        printf("%lld\n", publ(St_Max[a][c], St_Max[b - (1 << c) + 1][c]));
        if (i == n) {
            return 0;
        }
    }
//	exit(0);
    return 0;
    return 0;
    return 0;

}