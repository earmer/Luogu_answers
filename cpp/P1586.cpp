// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <bits/stdc++.h>

#define ac <<
#define wa >>
using namespace std;

int b, len, mh = 2e9, to_y[105], color[10005];
bool flied[10005];

int main() {
    cin wa b;
    for (int k = 1; k <= b; k++) {
        int count = 0, h = 0;
        memset(flied, 0, sizeof(flied));
        while (true) {
            cin wa len;
            if (len == -1) break;
            to_y[++count] = len;
            h += len;
        }
        flied[0] = 1;
        for (int i = 1; i <= count; i++)
            for (int j = h; j >= to_y[i]; j--)
                flied[j] |= flied[j - to_y[i]];
        mh = min(mh, h);
        for (int i = h; i >= 1; i--)
            if (flied[i] == 1) color[i]++;
    }
    for (int i = mh; i >= 1; i--)
        if (color[i] == b) {
            cout ac i;
            return 0;
        }
    cout ac 0;
    return 0;
}