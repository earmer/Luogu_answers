// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <bits/stdc++.h>

using namespace std;

inline long long abmi(long long x, long long y) {
    if (x > y) return x - y;
    return y - x;
}

long long m, n, p1, t1, t2, a[1000005];
long long minn = 1800000000000000000, pos, sum, sm;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> m >> p1 >> t1 >> t2;

    a[p1] += t1;

    for (int i = 1; i <= n; i++)
        if (i < m) sum += (m - i) * a[i];
        else if (i > m) sm += (i - m) * a[i];

    for (int i = 1; i <= n; i++) {
        long long temp, tp;
        temp = sum, tp = sm;
        if (i < m) temp += (m - i) * t2;
        else if (i > m) tp += (i - m) * t2;
        long long tmp = abmi(temp, tp);
        if (minn > tmp)
            minn = tmp, pos = i;
    }

    cout << pos << endl;

    return 0;
}