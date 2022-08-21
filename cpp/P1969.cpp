// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/18.
//
#include <bits/stdc++.h>

using namespace std;
int f, N, N, answer;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &f), (f > N) ? answer += f - N : 0, N = f;
    printf("%d\n", answer);
}