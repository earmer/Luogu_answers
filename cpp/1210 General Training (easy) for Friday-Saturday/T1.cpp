// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/10.
//

#include <cstdio>

using namespace std;

int ary[1000005];
int upa[1000005];
int dna[1000005];

int main() {
    int n, lgst, lgh = 0, last = 0;
    scanf("%d", &n);
    bool up = true;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ary[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (ary[i] >= ary[i - 1]) upa[i] = upa[i - 1] + 1;
        else upa[i] = 1;
    }
    for (int i = n; i > 0; i--) {
        if (ary[i] >= ary[i + 1]) dna[i] = dna[i + 1] + 1;
        else dna[i] = 1;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = mx > upa[i] + dna[i] ? mx : upa[i] + dna[i] - 1;
    }
    printf("%d\n", mx);
    return 0;
}