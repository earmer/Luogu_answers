//
// Created by Work on 2022/6/22.
//
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
int n, m, position[27], pin[27];
string s[27][100005], tmp;
char c;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        s[tmp[0] - 'a' + 1][++position[tmp[0] - 'a' + 1]] = tmp;
    }
    for (int i = 1; i <= 26; i++)
        sort(s[i] + 1, s[i] + position[i] + 1);
    for (int i = 1; i <= m; i++) {
        cin >> c;
        cout << s[c - 'a' + 1][++pin[c - 'a' + 1]] << endl;
        pin[c - 'a' + 1] %= position[c - 'a' + 1];
    }
    return 0;
}
