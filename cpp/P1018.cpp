// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/20.
//
#include<bits/stdc++.h>

using namespace std;
int f[200][100][2000], ary[200][200][200];

void cal(int m, int n, int q) {
    int cache[105] = {0};
    for (int i = 1; i <= ary[q][m][0]; ++i)
        for (int j = 1; j <= f[q - 1][n - 1][0]; ++j)
            cache[i + j - 1] += ary[q][m][i] * f[q - 1][n - 1][j];
    for (int i = 1; i <= 100; i++) {
        if (cache[i]) cache[0] = i;
        cache[i + 1] += cache[i] / 10, cache[i] %= 10;
    }
    if (cache[0] < f[m][n][0]) return;
    if (cache[0] > f[m][n][0])
        for (int i = cache[0]; i >= 0; i--)
            f[m][n][i] = cache[i];
    for (int i = cache[0]; i >= 0; i--)
        if (i == 0) return;
        else if (cache[i] < f[m][n][i]) return;
        else if (cache[i] > f[m][n][i]) break;
    for (int i = cache[0]; i >= 0; i--)
        f[m][n][i] = cache[i];
}

void r_p(int n) {
    char temp;
    ary[1][n][0] = n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        ary[1][n][n - i + 1] = int(temp) - '0';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ary[i][j][0] = j - i + 1;
            for (int q = 1; q <= ary[i][j][0]; q++) {
                ary[i][j][q] = ary[1][n][q + i - 1];
            }
        }
    }
}


int main() {
    int n, cuts;
    cin >> n >> cuts;
    r_p(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i && j <= cuts + 1; j++) {
            if (j == 1) {
                f[i][j][0] = i;
                for (int k = 1; k <= i; k++)
                    f[i][j][k] = ary[1][i][k];
            }
            for (int k = i; k >= j - 1; k--) {
                cal(i, j, k);
            }
        }
    for (int i = f[n][cuts + 1][0]; i >= 1; i--) {
        cout << f[n][cuts + 1][i];
    }
    return 0;
}