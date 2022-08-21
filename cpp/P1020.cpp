// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/19.
//
#include<bits/stdc++.h>

using namespace std;

int nums[100005], f[100005];
int num = 1, ans;

int main() {
    while (cin >> nums[num++]);
    num -= 2;
    ans = 1, f[1] = nums[1];
    for (int i = 2; i <= num; i++)
        if (f[ans] >= nums[i]) f[++ans] = nums[i];
        else
            for (int j = 1;; j++)
                if (f[j] < nums[i]) {
                    f[j] = nums[i];
                    break;
                }
    cout << ans << endl;
    ans = 1, f[1] = nums[1];
    for (int i = 2; i <= num; i++)
        if (f[ans] < nums[i]) f[++ans] = nums[i];
        else
            for (int j = 1;; j++)
                if (f[j] >= nums[i]) {
                    f[j] = nums[i];
                    break;
                }
    cout << ans << endl;
    return 0;
}