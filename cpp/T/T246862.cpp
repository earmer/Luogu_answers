//
// Created by Work on 2022/6/22.
//
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
int n, m, position[27];
int dict[27][100005];
int use[27][100005];
int flag;
string s[27][100005], tmp;
//
//bool cmp(string a, string b) {
//    int l = min(a.length(), b.length());
//    for(int i = 0; i < l; i++)
//        if (a[l] > b[l])
//            return false;
//    return a.size() < b.size();
//}

int cmp(string a, string b) {
    return a + b > b + a;
}

struct bindto {
    int useed;
    string s;
};

bindto b[27][100005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        b[tmp[0] - 'a' + 1][++position[tmp[0] - 'a' + 1]].s = tmp;
    }
//    cout << "1" << endl;
    char c;
    int now;
    string s1;
    while (m--) {
        cin >> c;
        now = b[c - 'a' - 1][1].useed;
        s1 = b[c - 'a' - 1][1].s;
        for (int i = 2; i <= position[i]; i++) {
            if (b[c - 'a' - 1][i].useed != now)
                break;
            s1 = (b[c - 'a' - 1][i].s + s1 < s1 + b[c - 'a' - 1][i].s) ? s1 : b[c - 'a' - 1][i].s;
        }
        cout << s1 << endl;
    }
    return 0;
}
