//
// Created by Work on 2022/6/11.
//
#include <bits/stdc++.h>

using namespace std;
int N, sum;
bool vised[25];
int ans[25], pc[25];

bool dfs(int i, int num, int v) {
    if (v > sum)
        return false;
    if (i == N) {
        if (v == sum) {
            ans[i] = num;
            return true;
        }
        return false;
    }
    vised[num] = true;
    for (int j = 1; j <= N; j++)
        if (!vised[j] && dfs(i + 1, j, v + pc[i] * j)) {
            ans[i] = num;
            return true;
        }
    vised[num] = false;
    return false;
}

int main() {
    cin >> N >> sum;
    pc[0] = pc[N - 1] = 1;
    if (N > 1)
        for (int i = 1; i * 2 <= N; i++)
            pc[i] = pc[N - 1 - i] = (N - i) * pc[i - 1] / i;
    if (dfs(0, 0, 0)) {
        for (int i = 1; i < N; i++)
            cout << ans[i] << " ";
        cout << ans[N] << endl;
    }
    return 0;
}