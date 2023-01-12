// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/9/4.
//

/* name: d
 * author: 5ab
 * created at: 22-06-27 00:06
 */
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

typedef long long ll;
const int max_n = 300000;

int hd[max_n], des[max_n << 1], nxt[max_n << 1], val[max_n << 1], f[max_n], fi[max_n], siz[max_n], e_cnt = 0, bne;
ll sdep[max_n], tsm[max_n], tdep[max_n], ssm[max_n];
char ans[max_n];

void add(int s, int t, int v) {
    des[e_cnt] = t, val[e_cnt] = v;
    nxt[e_cnt] = hd[s], hd[s] = e_cnt++;
}

ll *sm, *dep;

void dfs(int id, int fa) {
    siz[id] = 1, sm[id] += dep[id], f[id] = fa;
    for (int p = hd[id]; p != -1; p = nxt[p])
        if (des[p] != fa) {
            dep[des[p]] = dep[id] + val[p];
            fi[des[p]] = (p >> 1);
            dfs(des[p], id);
            siz[id] += siz[des[p]];
            sm[id] += sm[des[p]];
        }
}

void dfs2(int id, int fa) {
    for (int p = hd[id]; p != -1; p = nxt[p])
        if (des[p] != fa && (p >> 1) != bne) {
            ans[p >> 1] = '2' - (p & 1);
            dfs2(des[p], id);
        }
}

inline int read() {
    int c = getchar(), t = 1, n = 0;
    while (isspace(c)) { c = getchar(); }
    if (c == '-') { t = -1, c = getchar(); }
    while (isdigit(c)) { n = n * 10 + c - '0', c = getchar(); }
    return n * t;
}

void pans(ll x) {
    if (x >= 10)
        pans(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    memset(hd, -1, sizeof hd);

    int n = read(), s = read(), t = read();

    for (int i = 1, x, y, c; i < n; i++) {
        x = read(), y = read(), c = read();
        add(x - 1, y - 1, c), add(y - 1, x - 1, c);
    }
    sm = tsm, dep = tdep, dfs(t - 1, -1);
    sm = ssm, dep = sdep, dfs(s - 1, -1);

    ll mxoffset = 0;
    for (int x = t - 1; x != s - 1; x = f[x])
        if (tsm[f[x]] + ssm[x] > mxoffset) {
            // cerr << x << " " << dep[x] << " " << siz[x] << " " << fi[x] << endl;
            mxoffset = tsm[f[x]] + ssm[x];
            bne = fi[x];
        }

    memset(ans, '0', sizeof(char) * (n - 1));
    dfs2(s - 1, -1), dfs2(t - 1, -1);

    pans(ssm[s - 1] + tsm[t - 1] - mxoffset);
    printf("\n%s", ans);

    return 0;
}
