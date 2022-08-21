// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int post(int l, int r) {
    if (l < 0 && r > 0)
        return (abs(l - 1) >> 1) + (abs(l + 1) >> 2) + (abs(r + 1) >> 1) + (abs(r / 4) + 1);
    if(abs(l) > abs(r))
        swap(l, r);
    return ((abs(r) + 1) >> 1) + (abs(r) >> 2) - (abs(l) >> 1) - ((abs(l) - 1) >> 2);
}

int main() {
    int n;
    int l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        cout << post(l, r);
    }
    return 0;
}
