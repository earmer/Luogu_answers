// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/13.
//
#include<bits/stdc++.h>

using namespace std;
const int fasdfasdfsdfV = 5005;
int N;
int f1[fasdfasdfsdfV], _hjkshkjdf[fasdfasdfsdfV];
char str[fasdfasdfsdfV], _ppolpl[fasdfasdfsdfV];

int main() {
    scanf("%s", str + 1);
    N = strlen(str + 1);
    for (int i = 1; i <= N; i++) _ppolpl[i] = str[N - i + 1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            if (str[i] == _ppolpl[j]) f1[j] = _hjkshkjdf[j - 1] + 1;
            else f1[j] = max(f1[j - 1], _hjkshkjdf[j]);
        memcpy(_hjkshkjdf, f1, sizeof(f1));
    }
    cout << N - f1[N] << endl;
    return 0;
}