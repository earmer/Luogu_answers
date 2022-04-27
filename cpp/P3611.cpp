#include <bits/stdc++.h>

using namespace std;
int n, n1, m, w[9999999], s[9999999], maxx, limit;

bool water() {
    for (int i = 0; i < n1;i++) s[i] = w[i];
    int t = 0;
    for (int i = n1; i < n; i++) {
        sort(s, s + n1);
        int temp = s[0];
        t += temp;
        for (int j = 0; j < n1; j++) {
            s[i] -= temp;
        }
        s[0] = w[i];
    }
    sort(s, s+n1);
    t += s[n1 - 1];
    return t <= limit;
}

int main() {
    cin >> n >> limit;
    n1 = n;
    for (int i = 0; i < n; i++) cin >> w[i];
    int l = 0, r = n1;
    while (l < r) {
        n1 = (l + r) / 2;
        if (water())r = n1;
        else l = n1 + 1;
    }
    cout << n1;
}