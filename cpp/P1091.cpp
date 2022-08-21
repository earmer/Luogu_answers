// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/5/17.
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
int color, b, str[105], flied[105], d[105], pd2[105];

int main() {
    cin >> b;
    for (int i = 1; i <= b; i++)
        cin >> str[i];
    for (int i = 1; i <= b; i++) flied[i] = pd2[i] = 0;
    for (int i = 2; i <= b; i++) {
        for (int j = 1; j <= i; j++) {
            if (str[i] > str[j])
                flied[i] = max(flied[i], flied[j] + 1);
        }
    }
    for (int i = 1; i <= b; i++)
        d[i] = str[b - i + 1];
    for (int i = 2; i <= b; i++) {
        for (int j = 1; j < i; j++) {//改了，为什么还 挖 ？
            if (d[i] > d[j])
                pd2[i] = max(pd2[i], pd2[j] + 1);
        }
    }
    for (int i = 1; i <= b; i++) {
        if (flied[i] != 1 && pd2[b - i + 1] != 1)
            color = max(color, pd2[b - i + 1] + flied[i] - 1);
    }
    cout << b - color - 2;//还真就只需要 -2
    return 0;
}