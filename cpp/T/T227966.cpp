// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/23.
//

#include<stdio.h>
#include<bits/stdc++.h>

long long N, d, temp, tp;
long long answer = -1e10;
long long bt[1000005][6];
long long maxx[1025], minn[1025];
using namespace std;

void digm(long long i, int tms, long long answ, long long re) {
    if (tms > d) maxx[re] = max(answ, maxx[re]), minn[re] = min(answ, minn[re]);
    else {
        digm(i, tms + 1, answ + bt[i][tms], re + int(pow(2, tms))), digm(i, tms + 1, answ - bt[i][tms], re);
    }
}

void pick(long long l, long long s) {
    if (l > d) answer = max(answer, maxx[s] - minn[s]);
    else {
        pick(l + 1, s + pow(2, l)), pick(l + 1, s);
    }
}

int main() {
    cin >> N >> d;
    for (int i = 0; i <= 1024; i++) maxx[i] = -9223372036854775807, minn[i] = 9223372036854775807;
    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= d; j++) {
            cin >> bt[i][j];
        }
        digm(i, 1, 0, 0);
    }
    pick(1, 0);
    cout << answer << endl;
    return 0;
}