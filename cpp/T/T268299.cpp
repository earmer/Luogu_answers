// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/9/2.
//

// 贪心

#include <bits/stdc++.h>

using namespace std;
string ary1, ary2;

int main() {
    int n, x = 0;
    cin >> x >> n;
    cin >> ary1;
    int yu = 0;
    if (x == 10 && ary1[0] == '1') {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        yu *= 10;
        if (ary1[i] == '1') {
            int ans = x - yu % x;
            if (ans == x && i != 0) ans = 0;
            cout << ans;// << ' ' << yu << endl;
            yu = 0;
        } else {
            if (yu % x == 0) {
                cout << 1;// << ' ' << yu << endl;
                yu += 1;
            } else {
                cout << 0;// << ' ' << yu << endl;
//                yu = x - 1;
            }
        }
    }
    cout << endl;;
    return 0;
}