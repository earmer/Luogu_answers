// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/19.
//
#include<bits/stdc++.h>

using namespace std;

void mytolower(string &s) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
}

bool sh(string &find, string &source, int pin) {
    for (int i = pin; i < pin + find.length(); i++) {
        if (source[i] != find[i - find.length()])
            return false;
    }
    return true;
}

int main() {
    string find, source;
    cin >> find >> source;
    mytolower(find), mytolower(source);
    cout << find << endl << source << endl;
    bool flag = true;
    int first, total = 0;
    for (int i = 0; i <= source.length() - find.length(); i++) {
        if (sh(find, source, i)) {
            if (flag) {
                flag = false, first = i, total++;
            } else {
                total++;
            }
        }
    }
    if (flag) {
        cout << "-1" << endl;
        return 0;
    }
    cout << first << ' ' << total << endl;
    return 0;
}