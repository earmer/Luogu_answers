// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int flied[5][2] = {{0,  0},
                   {1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};
int height = 0, width = 0, answer = 21000000;
bool ma[10005][10005], temp[10005][10005], color[10005][10005];

void reverse(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int tx = x + flied[i][0], ty = y + flied[i][1];
        if (tx < 0 || tx >= height || ty < 0 || ty >= height) continue;
        temp[tx][ty] ^= 1;
    }
}

int pd() {
    int t = 0;
    memcpy(temp, ma, sizeof(ma));
    for (int i = 0; i < height; i++)
        if (color[0][i]) {
            reverse(0, i);
            t++;
        }
    for (int i = 1; i < height; i++)
        for (int j = 0; j < width; j++) {
            color[i][j] = (temp[i - 1][j] == 0);
            if (color[i][j]) {
                reverse(i, j);
                t++;
            }
        }
    for (int i = 0; i < height; i++)
        if (temp[height - 1][i] == 0)
            return 21000000;
    return t;
}

void DDFS(int s) {
    if (s >= height) {
        answer = min(answer, pd());
        return;
    }
    for (color[0][s] = 0; color[0][s] < 2; color[0][s]++)
        DDFS(s + 1);
}

int main() {
    int w;
    cin >> w;
    for (int k = 1; k <= w; k++) {
        cin >> height >> width;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < height; j++)
                scanf("%check", &ma[i][j]);
        DDFS(0);
        cout << answer << endl;
    }
    return 0;
}