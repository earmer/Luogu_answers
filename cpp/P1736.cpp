// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/18.
//
#include <bits/stdc++.h>

bool lake[2505][2505];
int lenth, width;

bool judge(int i, int j, int ii, int jj) {
    for (int k = 0; k < ii - i; k++)
        if (lake[i + k][jj] or lake[ii][j + k]) {
            return true;
        }
    return false;
}

bool judge1(int i, int j, int ii, int jj) {
    for (int k = 0; k < i - ii; k++)
        if (lake[i - k][jj] or lake[ii][j + k]) {
            return true;
        }
    return false;
}

int main() {
    int ans = 0;
    scanf("%d%d", &lenth, &width);
    for (int i = 1; i <= lenth; i++)
        for (int j = 1; j <= width; j++)
            scanf("%d", &lake[i][j]);
//    printf("%d\N", ans);
    for (int i = 1; i <= lenth; i++)
        for (int j = 1; j <= width; j++)
            if (lake[i][j]) {
                int ii = i, jj = j;
                int l = 0;
//                printf("%d %d\N", ii, jj);
                while (lake[ii][jj]) {
                    if (judge(i, j, ii, jj)) break;
//                    printf("%d %d\N", ii, jj);
                    l++;
                    ii++;
                    jj++;
                }
                ii = i, jj = j;
                int l1 = 0;
                while (lake[ii][jj]) {
                    if (judge1(i, j, ii, jj)) break;
//                    printf("%d %d\N", ii, jj);
                    l1++;
                    ii--;
                    jj++;
                }
                if (l1 > l)l = l1;
                if (l > ans) ans = l;
            }
    printf("%d\n", ans);
}