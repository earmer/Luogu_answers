// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/26.
//

#include <bits/stdc++.h>

#define int long long

using namespace std;
const int max_n = 2 * 1e5 + 5;
const int P = 1e5;
int n, ary[max_n], sum_array[max_n], cnt[max_n];

void make_ring(int num) {
    const int nm = num;
    for (int i = 1; i < nm; i++) {
        cin >> ary[i];
        if (ary[i] % 2 == 1) {
            ary[i] = 1;
        } else ary[i] = -1;
        sum_array[i] = ary[i] + sum_array[i - 1];
    }
    num = nm;
    for (int i = 1; i <= nm; i++) {
        sum_array[i + n] = sum_array[i + n - 1] + ary[i];
    }
}

int take_ring(int num) {
    int ans = 0;
//    cnt[P]++;
    for (int i = 1; i <= num * 2; i++) {
        if (i <= num) {
            printf("ans=%lld, i=%lld, cnt[sum_array[i] + P]=%lld, sum_array[i]=%lld\n", ans, i, cnt[sum_array[i] + P],
                   sum_array[i]);
            ans += cnt[sum_array[i] + P];
            cnt[sum_array[i] + P]++;

            printf("ans=%lld, i=%lld, cnt[sum_array[i] + P]=%lld, sum_array[i]=%lld\n", ans, i, cnt[sum_array[i] + P],
                   sum_array[i]);
        } else {
            printf("ans=%lld, i=%lld, cnt[sum_array[i] + P]=%lld, sum_array[i]=%lld\n", ans, i, cnt[sum_array[i] + P],
                   sum_array[i]);


            ans += cnt[sum_array[i] + P];
            cnt[sum_array[i - n - 1] + P]--;
            printf("ans=%lld, i=%lld, cnt[sum_array[i] + P]=%lld, sum_array[i]=%lld\n", ans, i, cnt[sum_array[i] + P],
                   sum_array[i]);
        }

    }
    return ans;
}

signed main() {
    cin >> n;
    make_ring(n);
    cout << take_ring(n) << endl;
//    for(int i = 1; i <= n*2; i ++){
//        cout << "smary[i]" << sum_array[i] << endl;
//    }
    return 0;
}