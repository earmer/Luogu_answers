//
// Created by Work on 2022/6/23.
//
#include <bits/stdc++.h>

using namespace std;
int N, block, lenth, nums[10005];
bool tick[10005];


struct block_info {
    int position;
    int num;
} matches[10005];

bool cmp(block_info a, block_info b) {
    return a.num > b.num;
}

void input() {
    for (int i = 1; i <= N; i++)
        cin >> nums[i];
//    int temp = 0;
    for (int i = 1; i <= lenth; i++)
        matches[lenth].num += nums[i];
    matches[lenth].position = lenth;
    for (int i = 1; i < lenth; i++)
        matches[i].num = 0, matches[i].position = i;
    for (int i = lenth + 1; i <= N; i++)
        matches[i].num = matches[i - 1].num - nums[i - lenth] + nums[i], matches[i].position = i;
    sort(matches + 1, matches + N + 1, cmp);
}

int main() {
    cin >> N >> block >> lenth;
    input();
    long long ans = 0;
    for (int i = 1; i < N; i++) {
//        cout << matches[i].position << " " << matches[i].num << endl;
    }
    for (int i = 1; i <= block; i++) {
        for (int j = 0; j < lenth; j++)
            if (tick[matches[i].position - j]) goto end;
        for (int j = 0; j < lenth; j++)
            tick[matches[i].position - j] = true;
        ans += matches[i].num;
        if (false) {
            end:
            block++;
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}