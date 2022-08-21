// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/20.
//
#include<bits/stdc++.h>

using namespace std;
int flag, ans = 1, ary[2000000], num;

int main() {
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) scanf("%d", &ary[i]);
    flag = (ary[1] <= ary[2]) ? 1 : 0;
    for (int i = 1; i <= num; i++) {
        if (flag == 0 && i == num) ans++;
        else if (flag == 1 and ary[i + 1] < ary[i]) ans++, flag = 0;
        else if (flag == 0 and ary[i + 1] > ary[i]) ans++, flag = 1;
    }
    cout << ans << endl;
    return 0;
}