// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/9/3.
//


#include<bits/stdc++.h>
//#include <cmath>
//#include <cstdio>
//#include <cstring>
////#include <algorithm>
//#include <iostream>
//#include <string>

using namespace std;
int n;
int chr[27];
const long long MOD = 1e9 + 7;

//string kaokingtuchong(string chong1, string chong2){
//
//}

int main() {
    cin >> n;
    long long mdn = 1;
    for (int i = 1; i <= n; i++) {
        mdn *= i;
        mdn %= MOD;
    }
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        chr[c - 'a' + 1]++;
    }
    int yesq = 0, totalq = 0;
    for (int i = 1; i <= 26; i++) {
        if (chr[i] % 2 == 1) yesq++;
        totalq = totalq + chr[i];
    }
    if (yesq > 1) {
        cout << mdn << endl;
        return 0;
    } else if (yesq < 1 && n % 2 == 1) {
        cout << mdn << endl;
        return 0;
    } else {
        long long mnd = 1;
        for (int i = 1; i <= totalq / 2; i++) {
            mnd *= i;
            mnd %= MOD;
        }
//		cout << mdn << endl;
//		cout << mnd << endl;
        for (int i = 1; i <= 26; i++) {
            int pow = 1;
            for (int j = chr[i]; j > (chr[i] + 1) / 2; j--) {
                pow *= j;
            }
            mnd *= pow;
//			cout << pow << "=pow" << endl;
            mnd %= MOD;
        }
//		cout << mnd << endl;
        cout << (mdn - mnd) % MOD << endl;
    }
//	for(int i = 1; i <= 26; i++){
//		int pow = 1;
//		for(int j =1; j <= (chr[i]); j++){
//			pow *= j;
//		}
////		mnd *= pow;
////		mnd %= MOD;
//		cout << i << ' ' << "chr[i] " << chr[i] << " pow " << pow << endl;
//	}
    return 0;
}