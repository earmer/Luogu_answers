// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/4.
//

#include <cstdio>
#include <iostream>

char res[128];

void query(int i, int up) {
    if (i > up) {
        for (int j = 1; j <= up; j++) {
            printf("%c", res[j]);
        }
        printf("\n");
        return;
    }
    res[i] = '0';
    query(i + 1, up);
    res[i] = '1';
    query(i + 1, up);
    return;
}

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    int n;
    scanf("%d", &n);
    query(1, n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}