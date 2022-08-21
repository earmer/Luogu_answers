// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/1.
//
#include <bits/stdc++.h>

using namespace std;

short b[2000005][4];
bool d[2000005];
int flied[2005];
int tmp, temp;

int main() {
    int n, w;
    cin >> n >> w;
    int fortime = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[++fortime][1] >> b[fortime][2] >> b[fortime][3];
        d[fortime] = true;
        fortime += b[fortime][3] - 1;
//        tmp = b[fortime][3];
//        temp = fortime;
//        for(int j = 1; j < tmp; j++) b[++fortime][1] = b[temp][1], b[fortime][2] = b[temp][2];
    }
    for (int i = 1; i <= fortime; i++) {
        if (d[i]) tmp = i;
        for (int j = w; j >= b[tmp][1]; j--)
            flied[j] = max(flied[j - b[tmp][1]] + b[tmp][2], flied[j]);
    }
    cout << flied[w];
    return 0;
}