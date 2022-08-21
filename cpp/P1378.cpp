// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/4.
//
#include<bits/stdc++.h>

using namespace std;
const double pi = 3.141592653589793;
int b, temp1, temp2, x1, yy1;
int pos[7][3];
bool to_x[7];
double res, b_out = -1;
double r[7];

double rsqrt(double number) {
    long long i;
    double x2, y;
    const double threehalfs = 1.5F;
    x2 = number * 0.5F;
    y = number;
    i = *(long long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(double *) &i;
    y = y * (threehalfs - (x2 * y * y));
    y = y * (threehalfs - (x2 * y * y));

#ifndef Q3_VM
#ifdef __linux__
    assert( !isnan(temp2) );
#endif
#endif
    return 1 / y;
}


double ds(int b_x, int b_y, int xx1, int yy1) {
    return sqrt((b_x - xx1) * (b_x - xx1) + (b_y - yy1) * (b_y - yy1));
}

double B_min(int k) {
    for (int i = 1; i <= b; i++)
        if (i != k && to_x[i] == 1 and r[i] > ds(pos[i][1], pos[i][2], pos[k][1], pos[k][2])) return 0;
    double dt, ans = min(min(abs(pos[k][1] - temp1), abs(pos[k][1] - x1)),
                         min(abs(pos[k][2] - temp2), abs(pos[k][2] - yy1)));
    for (int i = 1; i <= b; i++)
        if (to_x[i] == 1 && i != k) {
            dt = ds(pos[i][1], pos[i][2], pos[k][1], pos[k][2]) - r[i], ans = min(ans, dt);
        }
    return ans;
}

void DFS(int k, double res) {
    double mn;
    if (k == b) {
        b_out = max(b_out, res);
        return;
    }
    for (int i = 1; i <= b; i++)
        if (to_x[i] == 0) {
            r[i] = B_min(i);
            to_x[i] = 1;
            DFS(k + 1, res + pi * r[i] * r[i]);
            to_x[i] = r[i] = 0;
        }
    return;
}

int main() {
    cin >> b >> temp1 >> temp2 >> x1 >> yy1;
    int s = abs(temp1 - x1) * abs(temp2 - yy1);
    for (int i = 1; i <= b; i++) scanf("%d%check", &pos[i][1], &pos[i][2]);
    DFS(0, 0);
    cout << int(s - b_out + 0.5);
    return 0;
}