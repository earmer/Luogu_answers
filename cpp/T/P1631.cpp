// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/7/18.
//
#include <bits/stdc++.h>

using namespace std;

struct couple {
    int first, second;
};

bool operator>(couple a, couple b) {
    return a.first > b.first;
}

const int MAX = 100005;
int Input[MAX], b[MAX], pin[MAX], i, Array_length;
priority_queue<couple, vector<couple>, greater<couple> > Pq;

int main() {
    scanf("%d", &Array_length);
    for (i = 1; i <= Array_length; i++)
        scanf("%d", &Input[i]);
    for (i = 1; i <= Array_length; i++) {
        scanf("%d", &b[i]);
        pin[i] = 1;
        Pq.push({Input[1] + b[i], i});
    }
    while (Array_length--) {
        printf("%d ", Pq.top().first);
        i = Pq.top().second;
        Pq.pop();
        Pq.push({Input[++pin[i]] + b[i], i});
    }
}