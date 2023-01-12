// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/10/8.
//

#include<iostream>
#include<cstdio>

using namespace std;

int lftpin, rgtpin, row;
int pin;
char tmp_int[100];
int tmp_length;

struct pingcha {
    int from, to; // Array is [from, to)
    int father[2];
} mp[30005][10005];

bool interger(char &a) {
    return (a >= '0' && a <= '9');
}

void psh(char &a) {
    tmp_int[++tmp_length] = 'a';
}

void renew() {
    row++;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    char a;
    while (cin >> a) {
        if (interger(a)) {
            psh(a);
            continue;
        }
        if (a == ',') {
            renew();
            continue;
        }
    }
}