// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int LEss = 0, least = 0;

int main(int argc, char **argv) {
    //freopen("oooout.txt","to_y",stdout);
    int people = 0, water = 0, t = 0;
    cin >> people >> water;
    int peo_t[people];
    for (int i = 0; i < people; i++) {
        cin >> peo_t[i];
    }
    int w_o[water];
    for (int i = 0; i < water; i++) {
        w_o[i] = peo_t[i];
    }
    for (int i = water; i <= people; i++) {

        LEss = 999999;

        for (int j = 0; j < water; j++) {
            if (w_o[j] < LEss) {
                LEss = w_o[j];
                least = j;
            }
        }
        for (int j = 0; j < water; j++) {
            w_o[j] = w_o[j] - LEss;
        }
        t = t + LEss;
        if (i == people)
            break;
        w_o[least] = peo_t[i];
    }
    LEss = 0;
    for (int j = 0; j < water; j++) {
        if (w_o[j] > LEss) {
            LEss = w_o[j];
        }
    }
    t += LEss;
    cout << t;
    return 0;
}
// https://www.luogu.com.cn/problem/P1190