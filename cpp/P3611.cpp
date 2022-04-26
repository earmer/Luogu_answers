#include<bits/stdc++.h>

using namespace std;
int n, t_max;
int LEss = 0, least = 0, peo_t[999999];

bool check(int water) {
    int cows[water];
    int t = 0;
    for (int i = 0; i < water; i++) cows[i] = peo_t[i];
    for (int i = water + 1; i <= n; i++) {
        sort(cows, cows + water);
        t += cows[0];
//        cout<<cows[0]<<' ';
        for (int j = 0; j < water; j++) cows[j] -= cows[0];
        cows[0] = peo_t[i];
    }
    sort(cows, cows + water);
    t += cows[water - 1];
    cout<<t<<endl;
    return t <= t_max;
}

int main() {
    cin >> n >> t_max;
    for (int i = 1; i <= n; i++) {
        cin >> peo_t[i];
    }

    int l = 0, r = n;
    int mid = (r + l + 1) / 2;
    while (l + 1 < r) {
        mid = (r + l + 1) / 2;
        cout << mid << endl;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << endl << r;
    return 0;
}
