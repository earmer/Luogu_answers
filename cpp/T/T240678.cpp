// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/16.
//
#include<cstdio>
#include<iostream>

long long cnt[127][127], suf[127], pre[127];
using namespace std;
long long N, ans;
string s;

int main() {
    cin >> N >> s;
    for (int i = 0; i < N; i++) suf[s[i] - 'A']++;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; ++j)
            if (s[i] - 'A' != j)
                ans += cnt[s[i] - 'A'][j] * suf[j], ans %= 1000000007;
        for (int j = 0; j < 26; ++j)
            if (s[i] - 'A' != j)
                cnt[j][s[i] - 'A'] += pre[j];
            else cnt[j][s[i] - 'A'] = 0;
        pre[s[i + 1] - 'A']++;

        --suf[s[i + 1] - 'A'];
    }
    cout << ans;
    return 0;
}
