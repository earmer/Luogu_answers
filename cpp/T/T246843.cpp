//
// Created by Work on 2022/6/23.
//
#include <bits/stdc++.h>

using namespace std;
long long dp[10000][10000];
long long bigg[10000], smalll[100000];
long long num[10];

int main() {
    int m, n, sum;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][0];
    }
    for (long long i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
        bigg[2] = smalll[2] = num[i];
        if (bigg[2] > bigg[1]) swap(bigg[2], bigg[1]);
        if (bigg[1] > bigg[0]) swap(bigg[1], bigg[0]);
        if (smalll[2] < smalll[1]) swap(smalll[2], smalll[1]);
        if (smalll[1] < smalll[0]) swap(smalll[1], smalll[0]);
    }
    return 0;
}