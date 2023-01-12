// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/9/11.
//

#include <bits/stdc++.h>

struct bl {
    int tp, bm, ht;
};

using namespace std;
const int Maxn = 1000;
int bowls;
long double height, bm_height;
bl bowl[Maxn];

bool cmp(bl a, bl b) {
    if (a.bm > b.bm)
        return true;
    if (a.bm < b.bm)
        return false;
    if (a.tp > b.tp)
        return true;
    if (a.tp < b.tp)
        return false;
    if (a.ht < b.ht)
        return true;
    return false;
}

bool panding(int t, int b, int h, bl bowm) {
    int up_top = (t - b) * 1.0 * (bowm.ht / h) + b;//, up_bom = ((t - b) * 1.0 / bowm.bm) * h;
    if (up_top < bowm.tp) return 1;
    return 0;
}

long double dl(int t, int b, int h, bl bowm) {
//    if (b >= bowm.bm) return 0;
    long double result;
    if (panding(t, b, h, bowm)) {
        int tp = t - b;
        long double xi = 1.00;
        result = (tp * xi / bowm.bm) * h;
    } else {
        int tp = bowm.tp - bowm.bm;
    }
    return result;
}

int main() {
    scanf("%d", &bowls);
    for (int i = 1; i <= bowls; i++) {
        scanf("%d%d%d", &bowl[i].ht, &bowl[i].bm, &bowl[i].tp);
    }
    sort(bowl + 1, bowl + bowls + 1, cmp);
    int lst_bm = 10000000, lst_tp = 10000000, lst_ht = 0;
    for (int i = 1; i <= bowls; i++) {
        bm_height += dl(lst_tp, lst_bm, lst_ht, bowl[i]);
        height = max(height, bm_height + bowl[i].ht);
        lst_tp = bowl[i].tp;
        lst_ht = bowl[i].ht;
        lst_bm = bowl[i].bm;
        cout << height << endl;
    }
    if (height - (long long) (height) >= 0.5) height = (long long) (height) + 1;
    else height = (long long) (height);
    cout << height << endl;
    return 0;
}