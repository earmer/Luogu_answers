#include <bits/stdc++.h>

using namespace std;

inline long long read() {
    long long a;
    scanf("%lld", &a);
    return a;
}

inline bool rdb() {
    char a;
    cin >> a;
    if (a == '1') return true;
    return false;
}

bool els[105][105], res[105], vis[105], flg[2], tmp;
int btl[2], lth, tot;

int main() {
    int ftm = read();
    while (ftm--) {
        lth = read(), tot = read();
        for (int i = 1; i <= tot; i++) {
            for (int j = 1; j <= lth; j++)
                els[i][j] = rdb();
            res[i] = rdb();
            vis[i] = false;
        }
        for (int k = 1; k <= lth; k++) {
            for (int j = 1; j <= lth; j++) {
                btl[0] = btl[1] = -114514;
                flg[0] = flg[1] = false;
                for (int i = 1; i <= tot; i++) {
                    if (!vis[i]) {
                        if (btl[els[i][j]] == -114514)
                            btl[els[i][j]] = res[i];
                        else if (btl[els[i][j]] != res[i])
                            flg[els[i][j]] = true;
                    }
                }
                for (int i = 1; i <= tot; i++)
                    if (!flg[els[i][j]])
                        vis[i] = true;
            }
        }
        tmp = false;
        for (int i = 1; i <= tot; i++)
            if (!vis[i]) tmp = true;
        if (tmp) printf("LIE\n");
        else printf("OK\n");
    }
    if (ftm) return 0;
    printf("1919810 - Dong Huaxing AK IOI!");
    return 0;
}