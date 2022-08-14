//
// Created by Work on 2022/7/20.
//
#include<bits/stdc++.h>

using namespace std;

long long S_Arr[100005], St[100005][21];
long long n, h, temp, Answ = 18000000000;

long long Quest(long long l, long long r) {
    long long k = (long long) log2(r - l + 1);
    return max(St[l][k], St[r - (1 << k) + 1][k]);
}

int main() {
    cin >> n >> h;
    for (long long i = 1; i <= n; ++i) {
        cin >> temp;
        S_Arr[i] = S_Arr[i - 1] + temp;
        cin >> temp;
        St[i][0] = temp;
    }

    for (long long j = 1; j <= 20; ++j)
        for (long long i = 1; i + (1 << j) - 1 <= n; ++i)
            St[i][j] = max(St[i][j - 1], St[i + (1 << (j - 1))][j - 1]);

    for (long long i = 1; i <= n; ++i) {
        long long Lft = i, Rgt = n, Cu_P;
        if (S_Arr[Rgt] - S_Arr[i - 1] < h)
            break;
        while (Lft < Rgt) {
            Cu_P = (Lft + Rgt) >> 1;
            if (S_Arr[Cu_P] - S_Arr[i - 1] > h)
                Rgt = Cu_P;
            if (S_Arr[Cu_P] - S_Arr[i - 1] == h) {
                Rgt = Cu_P;
                break;
            }
            if (S_Arr[Cu_P] - S_Arr[i - 1] < h) Lft = Cu_P + 1;
        }
        Answ = min(Answ, Quest(i, Rgt));
    }
    cout << Answ;
    return 0;
}