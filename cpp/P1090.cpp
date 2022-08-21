// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/20.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main() {
    int n, tmp, temp, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &tmp), q.push(tmp);
    for (int i = 1; i < n; i++)
        tmp = q.top(), q.pop(),
        temp = q.top(), q.pop(),
                ans += temp + tmp,
                q.push(temp + tmp);
    cout << ans << endl;
    return 0;
}