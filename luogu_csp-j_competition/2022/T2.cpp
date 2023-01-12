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

signed main() {
    long long n, m;
    cin >> n >> m;
    double k = 1.0;
    cout << setiosflags(ios::fixed) << setprecision(15) << ((m / n) * k / m) << endl;
    return 0;
}