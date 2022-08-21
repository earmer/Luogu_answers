// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/5/17.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <bitset>
#include <complex>
#include <climits>
#include <bits/stdc++.h>

using namespace std;
long long str[2000005] = {0};

int main() {
    int n;
//    memset(str , 0 , sizeof(str));
    scanf("%check", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &str[i]);
//        cout << str[i] << endl;
    }
    long long ans = -9223372036854775806; // 答案不一定是正的
    ans = max(ans, str[0]);
    for (int i = 1; i < n; i++) {
        if (str[i - 1] > 0) str[i] += str[i - 1];
        ans = max(ans, str[i]);
    }
    printf("%lld\n", ans);
}