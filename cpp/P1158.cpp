// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/20.
//
#include <bits/stdc++.h>

using namespace std;

struct dis {
    int length1, length2;
} dist[100005];

int spot_1_x, spot_2_x, spot_1_y, spot_2_y, total_missiles;

int spot_distance(int s1x, int s1y, int s2x, int s2y) {
    return (pow(abs(s1x - s2x), 2) + pow(abs(s1y - s2y), 2));
}

bool cmp(dis a, dis b) {
    return a.length1 < b.length1;
}

int main() {
    cin >> spot_1_x >> spot_1_y >> spot_2_x >> spot_2_y >> total_missiles;
    for (int i = 1; i <= total_missiles; i++) {
        int t_x, t_y;
        cin >> t_x >> t_y;
        dist[i].length1 = spot_distance(t_x, t_y, spot_1_x, spot_1_y);
        dist[i].length2 = spot_distance(t_x, t_y, spot_2_x, spot_2_y);
    }
    sort(dist + 1, dist + total_missiles + 1, cmp);
    int answer = dist[total_missiles].length1, max_l2 = 0;
    for (int i = total_missiles - 1; i > 0; --i) {
        max_l2 = max(max_l2, dist[i + 1].length2);
        answer = min(answer, max_l2 + dist[i].length1);
    }
    cout << answer << endl;
    return 0;
}