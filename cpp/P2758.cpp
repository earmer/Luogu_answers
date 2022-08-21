// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/7.
//
#include <bits/stdc++.h>
#include<cstring>

using namespace std;
string s1, s2;
char str0[2005], str1[2005];
int e[2005][2005];

int dfs(int i, int j) {
    if (e[i][j] != -1) return e[i][j];
    if (i == 0) return (e[i][j] = j);
    if (j == 0) return (e[i][j] = i);
    int right = 1;
    if (str0[i] == str1[j]) right = 0;
    return e[i][j] = min(dfs(i - 1, j - 1) + right, min(dfs(i - 1, j) + 1, dfs(i, j - 1) + 1));
}

int main() {
    cin >> s1 >> s2;
    memset(e, -1, sizeof(e));
    int len1 = s1.size(), len2 = s2.size();
    for (int i = 1; i <= len1; i++) str0[i] = s1[i - 1];
    for (int i = 1; i <= len2; i++) str1[i] = s2[i - 1];
    dfs(len1, len2);
    cout << e[len1][len2];
    return 0;
}
