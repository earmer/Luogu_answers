// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<bits/stdc++.h>

using namespace std;
long long n, a[1000000], m, p, s, k, sum, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i]);
    cin >> m >> p >> s >> k;
    for (int i = 1; i <= n; i++) sum += a[i] * (m - i);
    sum += s * (m - p);
    ans = m + int(sum * 1.0 / k + 0.5 * ((sum > 0) ? 1 : -1)); //这里需注意，如果sum是个负数，四舍五入是要反着加的。
    if (ans > n) cout << n;
    if (ans < 1) ans = 1;
    printf("%lld", ans);
    return 0;
}