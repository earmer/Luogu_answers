// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by 101 on 2022-04-26.
//
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int post(int s) {
    if (s == 1) return 2;
    return 2 * post(s - 1);
}

int main() {
    for (int i = 1; i < 25; i++)
        cout << post(i) << ", ";
    return 0;
}
