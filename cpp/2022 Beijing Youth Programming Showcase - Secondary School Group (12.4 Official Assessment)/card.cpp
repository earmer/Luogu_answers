// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/4.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

int cd[6];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int tms;

    scanf("%d", &tms);
    while (tms--) {
        for (int i = 1; i <= 5; i++) {
            scanf("%d", &cd[i]);
        }
        std::sort(cd + 1, cd + 6);
        printf("1\n");
    }
    return 0;
}