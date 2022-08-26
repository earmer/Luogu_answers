// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/8/26.
//

#include<bits/stdc++.h> // 万能头文件，会减慢运行速度（7ms+），且不包含很多 STL 数据类型头，如 vector

using namespace std; // STL 命名空间，（命名空间：防止函数重名的设置，也可以在 STL 语句前加入 std:: 来替换，一般建议使用代码方式）
#define int long long // 这道题要用 long long， 其本质相当于将所有 int 替换为 long long 避免混乱

const double eps = 1e-6; // 由于浮点运算会损失精度，故在结果加上一个极小值，一般取 1e-6 - 1e-8，否则会 85 分
const int maxn = 2 * 1e5 + 10; // 定义最大
int a[maxn]; // 定义一个大小为 maxn 的数组
int b[maxn]; // 同上

void solve(int l, int r) { // solve 函数开始，用来排序，是二分排序，时间效率与 sort 相等
    if (l == r) return; // 设置函数递归结束情况，否则死循环
    int mid = (l + r) >> 1; // 求平均数，>> 代表左数乘以 2^-n ，n 代表其右侧数，此等同于 / 2，但时间效率更高
    solve(l, mid); // 递归左边
    solve(mid + 1, r); // 递归右边
    int i = l, j = mid + 1; // 复制，方便之后使用
    int tot = l; // 定义当前
    while (i <= mid && j <= r) { // 解决当前
        if (a[i] <= a[j]) // 比较大小
            b[tot++] = a[i++]; // 取小
        else b[tot++] = a[j++]; // 取小
    } // 循环结束
    while (i <= mid) b[tot++] = a[i++]; // 把左边赋过去
    while (j <= r) b[tot++] = a[j++]; // 把右边赋过去
    for (i = l; i <= r; i++) a[i] = b[i]; // 再将其写回
} // solve 结束

signed main() { // 由于 main 只能返回 int 类型的值，所以用（在此等效，但不永久等效）的 signed 来替代，不可更改
//	freopen("a.txt","r",stdin); // 测试代码
    int n; // 定义 n
    scanf("%lld", &n); // 输入 n，也可做 cin >> n

    int sum = 0; // 定义和
    for (int i = 1; i <= n; i++) { // 循环开始，从 1-n
        scanf("%lld", &a[i]); // scanf 输入，ll 代表 long long，d 代表数字，也可做 cin >> a[i]
        sum += a[i]; // 求和
    } // 循环结束

//	printf("sum=%lld\n",sum); // 测试代码

    long double avg = 1.0 * sum / n; // 测试代码

    solve(1, n); // 解决

    long double mid; // 必须开大 double 才能存的下
    if (n % 2 == 0) mid = (a[n / 2] + a[n / 2 + 1]) / 2.0; // 偶数是取平均值 2.0 是将其强制转换为 double 计算
    else mid = a[(n + 1) / 2] * 1.0; // 如果是奇数位的话取 (n + 1) / 2 ，也可用 n / 2 + 1

    cout << fixed << setprecision(2) << avg + eps
         << " " << fixed << setprecision(2) << mid + eps; // fixed 表示四舍五入， setprecision() 表示留到几位
    printf("%.2Lf %.2Lf\n", avg + eps, mid + eps); // 这句话是 printf 的实现，L 代表 long f代表 double

    return 0; // 返回 0 （正常退出）
} // 主函数结束