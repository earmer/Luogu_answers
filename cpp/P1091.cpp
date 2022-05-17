//
// Created by Work on 2022/5/17.
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
int ans, n, a[105], dp[105], b[105], pd2[105];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i] = pd2[i] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++)
        b[i] = a[n - i + 1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {//改了，为什么还 挖 ？
            if (b[i] > b[j])
                pd2[i] = max(pd2[i], pd2[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] != 1 && pd2[n - i + 1] != 1)
            ans = max(ans, pd2[n - i + 1] + dp[i] - 1);
    }
    cout << n - ans - 2;//还真就只需要 -2
    return 0;
}