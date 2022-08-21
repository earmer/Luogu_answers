// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/5/31.
//
#include <bits/stdc++.h>

using namespace std;
int vv[55], mm[55], kk[55], flied[405][405];

int main() {
    int v, m, n;
    cin >> v >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> vv[i] >> mm[i] >> kk[i];
    for (int i = 1; i <= m; i++)
        for (int j = v; j >= vv[i]; j--)
            for (int l = m; l >= mm[i]; l--) {
                flied[j][l] = max(flied[j][l], flied[j - vv[i]][l - mm[i]] + kk[i]);
            }
    cout << flied[v][m];
    return 0;
}