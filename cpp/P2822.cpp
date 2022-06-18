#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int t, k, n, m;
int c[2005][2005], s[2005][2005];

void prepare();

int main() {
    memset(c, 0, sizeof(c));
    memset(s, 0, sizeof(s));
    cin >> t >> k;
    prepare();
    while (t--) {
        cin >> n >> m;
        if (m > n) m = n;
        cout << s[n][m] << endl;
    }
    return 0;
}

void prepare() {
    c[1][1] = 1;
    for (int i = 0; i <= 2000; i++) c[i][0] = 1;
    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
        }
    }
    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if (c[i][j] == 0) s[i][j] += 1;
        }
        s[i][i + 1] = s[i][i];
    }
}