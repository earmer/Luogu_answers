// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/5/22.
//
#include <bits/stdc++.h>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
int pos[10005][6];

int main() {
    memset(pos, 0, sizeof(pos));
    string s;
    cin >> s;
    int fortime = 0;

    while (s.find('z') != -1) {
        fortime++;
        pos[fortime][0] = s.find('z');
        if (pos[fortime][0] == -1) {
            break;
        }
        s[pos[fortime][0]] = 't';
    }
    int breakpoint[6] = {fortime, fortime, fortime, fortime, fortime, fortime};
    for (int i = 0; i < fortime; i++) {
        pos[i][1] = s.find('h', pos[i][0]);
        if (pos[i][1] == -1) {
            breakpoint[1] = i;
            break;
        }
        s[pos[i][1]] = 't';
    }
    for (int i = 0; i < fortime; i++) {
        pos[i][2] = s.find('i', pos[i][1]);
        if (pos[i][2] == -1) {
            breakpoint[2] = i;
            break;
        }
        s[pos[i][2]] = 't';
    }
    for (int i = 0; i < fortime; i++) {
        pos[i][3] = s.find('h', pos[i][2]);
        if (pos[i][3] == -1) {
            breakpoint[3] = i;
            break;
        }
        s[pos[i][3]] = 't';
    }
    for (int i = 0; i < fortime; i++) {
        pos[i][4] = s.find('u', pos[i][3]);
        if (pos[i][4] == -1) {
            breakpoint[4] = i;
            break;
        }
        s[pos[i][4]] = 't';
    }
    for (int i = 0; i < fortime; i++) {
        pos[i][5] = s.find('i', pos[i][4]);
        if (pos[i][5] == -1) {
            breakpoint[5] = i;
            break;
        }
        s[pos[i][5]] = 't';
    }
    int ans = 0;
    ans = min(min(breakpoint[0], min(breakpoint[1], min(breakpoint[2], min(breakpoint[3], breakpoint[4])))),
              breakpoint[5]);
    cout << ans << endl;
    return 0;
}