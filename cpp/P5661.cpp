// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<bits/stdc++.h>

using namespace std;

struct t {
    int price, now;
    bool use;
} node[100005];

int n, ans, top, m = 1;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int bus, pri, tm;
        scanf("%d%d%d", &bus, &pri, &tm);
        if (!bus) node[++top].price = pri, node[top].now = tm, ans += pri;
        else {
            bool flag = false;
            for (int j = m; j <= top; j++) {
                if (node[j].use) continue;
                if (tm - node[j].now > 45) m = j;
                else if (node[j].price >= pri) {
                    flag = true;
                    node[j].use = true;
                    break;
                }
            }
            if (!flag) ans += pri;
        }
    }
    printf("%d", ans);
}