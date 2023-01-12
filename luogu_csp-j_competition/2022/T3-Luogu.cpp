// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/9/4.
//

/* name: c
 * author: 5ab
 * created at: 22-07-27 07:59
 */
#include <iostream>

using namespace std;

typedef long long ll;
const int max_n = 100000;

int a[max_n];

inline void chmax(ll &a, ll b) { if (a < b) a = b; }

inline ll cdiv(ll a, ll b) { return (a + b - 1) / b; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, p, q;
    ll sm = 0;

    cin >> n >> x >> p >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }

    ll ans = 0, cnt = 0, csm;
    for (int i = n - 1; i >= 0;) {
        chmax(ans, cnt + cdiv(sm * q, 1ll * x * (q - p)));
        // cerr << sm * q << " " << 1ll * x * (q - p) << endl;

        csm = 0;
        while (i >= 0 && a[i] + csm < x)
            csm += a[i--];
        sm -= csm, cnt++;
    }

    cout << ans << endl;

    return 0;
}