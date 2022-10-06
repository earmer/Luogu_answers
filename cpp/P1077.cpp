#include<cstdio>
#include<iostream>
using namespace std;

const int MODS = 1000007;

int n, m, dp[105] = {1}, sum_ary[105], ary[105];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> ary[i];
    for (int i = 0; i <= m; i++) sum_ary[i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            int temp = j - min(ary[i], j) - 1;
            if (temp < 0) dp[j] = (dp[j] + sum_ary[j - 1]) % MODS;
            else dp[j] = (dp[j] + sum_ary[j - 1] - sum_ary[temp] + MODS) % MODS;
        }
        for (int j = 1; j <= m; j++)
            sum_ary[j] = (sum_ary[j - 1] + dp[j]) % MODS;
    }
    cout << dp[m] << endl;
    return 0;
}