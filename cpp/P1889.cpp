// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/7/13.
//
#include<bits/stdc++.h>

using namespace std;
int N, x[10005], y[10005], answer = 0, midx, midy;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    sort(x + 1, x + N + 1);
    for (int i = 1; i <= N; i++) x[i] -= i;
    sort(x + 1, x + N + 1);
    sort(y + 1, y + N + 1);
    if (!N % 2)
        midx = (x[N / 2] + x[N / 2 + 1]) / 2, midy = (y[N / 2] + y[N / 2 + 1]) / 2;
    else
        midx = x[N / 2 + 1], midy = y[N / 2 + 1];

    for (int i = 1; i <= N; i++)
        answer += abs(x[i] - midx) + abs(y[i] - midy);
    cout << answer << endl;
    return 0;
}
