// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/2.
//

#include <cstdio>

#define int long long

using namespace std;

int visitTime[100005];
int noCardCost[100005];
int cardCost[100005];
int cardBuy[100005];

namespace bigOrSmall {
    int bigger(int a, int b) {
        return a > b ? a : b;
    }

    int smaller(int a, int b) {
        return a < b ? a : b;
    }
}

int cost;

signed main() {
    int city, way;
    scanf("%lld%lld", &city, &way);
    int last = 0, now = 0;
    for (int i = 1; i <= way; ++i) {
        if (!last) {
            scanf("%lld", &last);
            continue;
        }
        scanf("%lld", &now);
        visitTime[bigOrSmall::smaller(last, now)]++;
        visitTime[bigOrSmall::bigger(last, now)]--;
        last = now;
    }
    now = 0;
    for (int i = 1; i < city; ++i) {
        scanf("%lld%lld%lld", &noCardCost[i], &cardCost[i], &cardBuy[i]);
        now += visitTime[i];
        if (now != 0)
            cost += (noCardCost[i] * now < cardCost[i] * now + cardBuy[i]) ? noCardCost[i] * now : cardCost[i] * now +
                                                                                                   cardBuy[i];
    }
//    for (int i = 1; i < city; ++i) {
//
//    }
    printf("%lld\n", cost);
    return 0;
}