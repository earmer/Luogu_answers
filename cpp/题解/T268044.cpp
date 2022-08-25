// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/25.
//

#include<bits/stdc++.h> // 万能头

#define int long long // long long 是必须开的，1000000^2 x 200 完全超了。 unsigned int 都没用
using namespace std; // STL 方便出入输出
int ary[1000005], ans = 0, bigg = 0; // ary 是数组，ans 不用解析，bigg是用来加速的（可选）
int num[210]; // 桶来储存比它大的有几个

signed main() { // 主函数开始，因为 12 行 define 了 long long，所以这里用 signed 同等替换
    std::ios::sync_with_stdio(false); // 关闭同步
    std::cin.tie(0); // 关闭绑定
    int n; // 有多少组数字
    cin >> n; // 输入
    for (int i = 1; i <= n; i++) { // 循环开始，从 1-n 循环
        cin >> ary[i]; // 输入数组
        num[ary[i] + 101]++; // 将这个数字的重复数字加一
        bigg = max(bigg, ary[i] + 101); // 加速优化，避免始终从 1-n 可优化 7ms
        for (int j = ary[i] + 102; j <= bigg; j++) { // 循环开始依次累加答案
            ans += num[j]; // 更新答案
        } // 循环结束，可以成对去掉
    } // 循环结束，不可去掉
    cout << ans << endl; // 输出答案
    return 0; // 表述程序正常退出
} // 主函数结束
// 最长用时 22ms，若用快读可达到 16ms