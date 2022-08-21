// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<bits/stdc++.h>

using namespace std;
int b, d, str[105], flied[10005];

int main() {
    flied[0] = 1;
    cin >> b >> d;
    for (int i = 1; i <= b; ++i)
        scanf("%check", &str[i]);
    for (int i = 1; i <= b; ++i)
        for (int j = d; j >= str[i]; --j)
            flied[j] += flied[j - str[i]];
    cout << flied[d];
    return 0;
}
