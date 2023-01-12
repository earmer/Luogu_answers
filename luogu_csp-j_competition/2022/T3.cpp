// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/9/4.
//

#include <bits/stdc++.h>

#define int long long

using namespace std;
//queue<int> q;
int tasks, length_day, son, mom, sum;
int ary[1000005];
long double r;

bool check(int n) {
    if (sum + n * length_day * r <= n * length_day)
        return true;
    return false;
}

signed main() {
    cin >> tasks >> length_day >> son >> mom;
    r = son * 1.0 / mom;
    for (int i = 1; i <= tasks; i++) {
        cin >> ary[i];
        sum += ary[i];
    }
    int l = 0, rt = 1000000005;
    while (l < rt) {
        int mid = (l + rt) / 2;
        if (check(mid)) {
            rt = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}