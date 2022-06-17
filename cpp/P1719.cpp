//
// Created by Work on 2022/6/11.
//
#include <bits/stdc++.h>

using namespace std;
int square[125][125], sum_sum[125][125];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%check", &square[i][j]);
            sum_sum[i][j] = sum_sum[i - 1][j] + sum_sum[i][j - 1] - sum_sum[i - 1][j - 1] + square[i][j];
        }
    }
    int maxx = -2100000000;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= i; k++) {
                for (int l = 1; l <= j; l++) {
                    maxx = max(maxx, sum_sum[i][j] - (sum_sum[i][l - 1] + sum_sum[k - 1][j] - sum_sum[k - 1][l - 1]));
                }
            }
        }
    }
    cout << maxx << endl;
}