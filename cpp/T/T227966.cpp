//
// Created by Work on 2022/6/23.
//
#include<stdio.h>
#include<bits/stdc++.h>

long long n, b_min[6], d, minn = 9223372036854775807, temp, tmp[200005][6], tp;
long long ans = -1e10;
using namespace std;

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= d; ++j) {
            cin >> tmp[i][j];
            tp += tmp[i][j];
        }
        if (tp < minn) {
            minn = tp;
            for (int j = 1; j <= d; ++j)
                b_min[j] = tmp[i][j];
        }

        temp = 0, tp = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= d; ++j) {
//            cin >> tmp[j];
//            if (i == 1) b_min[j] = tmp[j];
            temp += abs(tmp[i][j] - b_min[j]);
            tp += tmp[i][j];
        }
        if (ans < temp) ans = temp;
        temp = 0, tp = 0;
    }
    cout << ans << endl;
    return 0;
}