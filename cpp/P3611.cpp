// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<bits/stdc++.h>

using namespace std;
int total[7];

int main() {
    int n, a, b;
    cin >> n;
    while (n--) {
        scanf("%d %check", &a, &b);
        if (a < 0 && b > 0) {
            a = abs(a);
            cout << (a + 4) / 4 + (a + 1) / 2 + (b) / 4 + (b + 1) / 2 << endl;
            continue;
        }
        a = abs(a);
        b = abs(b);
        if (a > b) swap(a, b);
        cout << abs((b + 4) / 4 + (b + 1) / 2 - (a + 3) / 4 - (a) / 2) << endl;
    }
    return 0;
}