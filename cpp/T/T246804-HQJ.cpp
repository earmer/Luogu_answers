// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/7/16.
//
//中位数
#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
typedef long long ll;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int n, m, x, a[N], sum[N], ans[N], w;
ll num = 0;
int ml[2 * N], mr[2 * N];

struct node {
    int l, r, id;
} q[N];

bool cmp(node xx, node yy) {
    if (xx.l != yy.l) return xx.l < yy.l;
    return xx.r < yy.r;
}

int main() {
    n = read();
    m = read();
    x = read(); // 读取基本
    int minn = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int tmp;
//        tmp = read();
        scanf("%s", &tmp);
        if (tmp < x) a[i] = -1;
        else if (tmp > x) a[i] = 1;
        else a[i] = 0, w = i;
        sum[i] = sum[i - 1] + a[i]; // 前缀和
        minn = min(minn, sum[i]); // 找最小
    }
    for (int i = 0; i <= n; ++i) {
        sum[i] -= minn; // 这是tick
        sum[i] += 1;
    }
    for (int i = 1; i <= m; ++i) {
        q[i].l = read();
        q[i].r = read();
        q[i].id = i; // 读入并标记
    }
    sort(q + 1, q + m + 1, cmp);
    int flag = 0, lstl, lstr;
    for (int i = 1; i <= m; ++i) {
        if (q[i].l <= w && q[i].r >= w) {
            if (!flag) { //the first time
                flag = 1;
                for (int j = q[i].l - 1; j < w; ++j) ++ml[sum[j]]; // 先涨
                for (int j = w; j <= q[i].r; ++j) {
                    ++mr[sum[j]];
                    num += ml[sum[j]];
                } // 再加
            } else {
                for (int j = lstl - 1; j < q[i].l - 1; ++j) {
                    --ml[sum[j]];
                    num -= mr[sum[j]];
                }
                for (int j = lstr + 1; j <= q[i].r; ++j) {
                    ++mr[sum[j]];
                    num += ml[sum[j]];
                }
            }
            ans[q[i].id] = num;
            lstl = q[i].l, lstr = q[i].r;
        }
    }
    for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
    return 0;
}

































