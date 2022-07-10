//
// Created by Work on 2022/6/23.
//

#include<stdio.h>
#include<bits/stdc++.h>

long long n, d, temp, tp;
long long ans = -1e10;
long long bt[1000005][6];
using namespace std;

int main() {
    cin >> n >> d;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= d; j++) {
            cin >> bt[i][j];
        }
        for (int k = 1; k < i; k++) {
            //for all numbers
            long long t = 0;
            for (long long l = 1; l <= d; l++) {
                //finding the number of elements in the array
                t += abs(bt[k][l] - bt[i][l]);
            }
            ans = max(ans, t);
        }
    }
    cout << ans << endl;
    return 0;
}