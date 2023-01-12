// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/2.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int argjalsdkjfvciasdfnxklcvjl[2000005], drmdfasdlxcvj = 1000000;

int main() {
    string str;
    cin >> str;
    int lth = str.size();
    int mx;
//    argjalsdkjfvciasdfnxklcvjl[1000000] = 1;
    for (int i = 1; i <= lth; i++) {
        if (str[i - 1] == 'R') ++drmdfasdlxcvj;
        else --drmdfasdlxcvj;
        if (!argjalsdkjfvciasdfnxklcvjl[drmdfasdlxcvj]) argjalsdkjfvciasdfnxklcvjl[drmdfasdlxcvj] = i;
        else mx = max(mx, i - argjalsdkjfvciasdfnxklcvjl[drmdfasdlxcvj]);
        if (drmdfasdlxcvj == 1000000) mx = i;
    }
    printf("%d\n", mx);
    return 0;
}