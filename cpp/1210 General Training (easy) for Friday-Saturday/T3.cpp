// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/10.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
struct pos {
    int x, y;
} p[1005];
int n;

bool checkx(int colomn) {
    colomn *= 2;
    int cl = 0, cr = 0;
    for (int i = 0; i <= n; i++) {
        if (p[i].x < colomn) {
            cl++;
        } else cr++;
    }
    return cl > cr;
}

bool checky(int colomn) {
    colomn *= 2;
    int cl = 0, cr = 0;
    for (int i = 0; i <= n; i++) {
        if (p[i].y < colomn) {
            cl++;
        } else cr++;
    }
    return cl > cr;
}

int yy(int colomn, int clm) {
    colomn *= 2, clm *= 2;
//    cout << colomn << ' ' << clm << endl;
    int cl = 0, cr = 0, xl = 0, xr = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i].y < clm) {
            if (p[i].x < colomn) {
                cl++;
//                cout << "[1] \n";
            } else { cr++; }
        } else if (p[i].x < colomn) {
            xl++;
//            cout << "[3] \n";
        } else { xr++; }
    }
//    cout << cl << ' ' << cr << ' ' << xl << ' ' << xr << endl;
    return max(max(cl, cr), (xl, xr));
}

int main() {

    cin >> n;
    int mx = -210000000, my = -210000000, ix = 210000000, iy = 210000000;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        mx = max(mx, p[i].x), my = max(my, p[i].y);
        ix = min(ix, p[i].x), iy = min(iy, p[i].y);
    }
    int xl = -210000000, xr = 210000000;
    while (xl < xr) {
        int mid = (xl + xr) >> 1;
        if (checkx(mid)) {
            xr = mid;
        } else xl = mid + 1;
    }
    int yl = -210000000, yr = 210000000;
    while (yl < yr) {
        int mid = (yl + yr) >> 1;
        if (checky(mid)) {
            yr = mid;
        } else yl = mid + 1;
    }
//    printf("%d %d\n", xl, yl);
    printf("%d", yy(xl, yl));
//    printf("%d", xl * 2);
    return 0;
}