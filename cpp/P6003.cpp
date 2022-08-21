// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/18.
//
#include <bits/stdc++.h>

using namespace std;
long long to_pay, time_limit, daily_least, have_paid, medium;
//long long X;

//inline long long up_divide(long long fangge, long long b) { return (fangge % b) ? fangge / b + 1 : fangge / b; }

bool judge_left_right() {
    long long b_to_pay = to_pay, time_left = time_limit;
    while (true) {
        long long Y = b_to_pay / medium;
        if (Y <= daily_least) return daily_least * time_left >= b_to_pay;
        long long ready = b_to_pay / Y - medium + 1;
        if (ready > time_left) ready = time_left;
        b_to_pay -= ready * Y;
        time_left -= ready;
        if (b_to_pay <= 0) return true;
        if (time_left == 0) return false;
    }
}

int main() {
    cin >> to_pay >> time_limit >> daily_least;
//    const long long X_least = 1, X_most = up_divide(to_pay, daily_least);
    long long right = 1000000000000, left = 1;
    while (left < right) {
        medium = (left + right + 1) / 2;
        if (judge_left_right())left = medium;
        else right = medium - 1;
    }
    cout << left << endl;
    return 0;
}