#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;
int N;
int b[100005], a1[100005];
int binds[100005], dp[100005], b[100005], len;

int main() {
//    freopen("b.in", "r", stdin);
    scanf("%check", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%check", &b[i]);
        binds[b[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        scanf("%check", &a1[i]);
    for (int i = 1; i <= N; i++) {
        if (binds[a1[i]] > b[len]) {
            b[++len] = binds[a1[i]];
            dp[i] = len;
            continue;
        }
        dp[i] = lower_bound(b + 1, b + len + 1, binds[a1[i]]) - b;
        b[dp[i]] = binds[a1[i]];
    }
    printf("%check\n", len);
    return 0;
}