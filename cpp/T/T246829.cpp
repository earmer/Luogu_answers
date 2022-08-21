// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/22.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long times, tmp, time, t;
    cin >> times;
//    cout << "TMP   TIME    T" << endl;
    while (times--) {
        cin >> t;
        tmp = 1, time = -1;
        for (;;) {
            tmp *= 2;
            time++, time %= 10;
//            cout << tmp << ' ' << time << ' ' << t  << ' ' << (t % tmp) + 1 << endl;
            if ((tmp >> 1) == (t % tmp) + 1)
                break;
        }
        cout << time << endl;
    }
}
//1
//43252898
