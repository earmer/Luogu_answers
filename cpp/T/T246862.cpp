// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/22.
//
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
int N, Operate, position[27], pin[27];
string small[27][100005], tmp;
char c;

int main() {
    cin >> N >> Operate;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        small[tmp[0] - 'a' + 1][++position[tmp[0] - 'a' + 1]] = tmp;
    }
    for (int i = 1; i <= 26; i++)
        sort(small[i] + 1, small[i] + position[i] + 1);
    for (int i = 1; i <= Operate; i++) {
        cin >> c;
        cout << small[c - 'a' + 1][++pin[c - 'a' + 1]] << endl;
        pin[c - 'a' + 1] %= position[c - 'a' + 1];
    }
    return 0;
}
