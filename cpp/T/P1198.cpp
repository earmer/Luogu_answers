//
// Created by Work on 2022/7/20.
//
#include <bits/stdc++.h>

using namespace std;
long long St[200005][40], Last_time;
long long Array_Length, Operate, Mod_num;

void Adj() {
    for (int i = 1; Array_Length - (1 << i) >= 0; i++)
        St[Array_Length][i] = max(St[Array_Length][i - 1], St[Array_Length - (1 << (i - 1))][i - 1]);
}

long long find(int x, int y) {
    double t = log(y - x + 1) / log(2);
    int K = t;
    return max(St[y][K], St[x + (1 << K) - 1][K]);
}

int main() {
    scanf("%d%lld", &Operate, &Mod_num);
    for (int i = 1; i <= Operate; i++) {
        char c;
        cin >> c;
        long long tmp;
        if (c == 'A') {
            scanf("%lld", &tmp);
            St[++Array_Length][0] = (tmp + Last_time) % Mod_num;
            Adj();
            continue;
        }
        int L;
        scanf("%d", &L);
        long long ans;
        if (L == 1) {
            printf("%lld\n", St[Array_Length][0]);
            Last_time = St[Array_Length][0];
            continue;
        }
        ans = find(Array_Length - L + 1, Array_Length);
        printf("%lld\n", ans);
        Last_time = ans;
    }
    return 0;
}