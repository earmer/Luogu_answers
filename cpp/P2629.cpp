// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/2.
//

#include<cstdio>
#include<algorithm>

using namespace std;
long long n;
long long message[1000001], sumary[1000001], sumMin[1000001], subCha[1000001], ans = 0;

int main() {
    scanf("%lld", &n);
    sumMin[0] = 1e15;
    subCha[n + 1] = 1e15;
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &message[i]);
        sumary[i] = sumary[i - 1] + message[i];
        sumMin[i] = min(sumary[i], sumMin[i - 1]);
    }
    for (long long i = n; i >= 1; i--)
        subCha[i] = min(sumary[i], subCha[i + 1]);
    for (long long i = 1; i <= n; i++)
        if ((subCha[i] - sumary[i - 1] >= 0) &&
            (sumMin[i - 1] + sumary[n] - sumary[i - 1] >= 0))
            ans++;
    printf("%lld\n", ans);
    return 0;
}