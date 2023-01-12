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
    int hang;
    cin >> hang;
    int ans = 0;
    string s;
    getline(cin, s);
    for (int i = 1; i <= hang; i++) {
//        string s;
        // bool flag = false;
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ' ') continue;
            if (s[j] == '#') {
                if (j + 1 < s.length() && s[j + 1] == ' ') {
                    for (int k = j + 2; k < s.length(); k++) {
                        if (s[k] != ' ') {
                            ans++;
                            // cout << "yes" << endl;
                            break;
                        }
                    }
                    break;
                }
            }
            // cout << "no" << endl;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}