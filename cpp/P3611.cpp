#include<bits/stdc++.h>

using namespace std;
const int N = 10000 + 5;
int n, t_max;
int cow[N];

bool check(int x) {
    priority_queue<int, vector<int>, greater<int> > dance;//维护舞台上舞蹈的牛，小->大
    for (int i = 1; i <= x; i++)
        dance.push(cow[i]);
    for (int i = x + 1; i <= n; i++) {
        int cur = dance.top();    //下台了的牛
        dance.pop();
        dance.push(cur + cow[i]);//读入下一头牛
    }
    int cur;
    while (!dance.empty()) {    //取出最终的用时
        cur = dance.top();
        dance.pop();
    }
    return cur <= t_max;
}

int main() {
    cin >> n >> t_max;
    for (int i = 1; i <= n; ++i) {
        cin >> cow[i];
    }
    int l = 0, r = n + 1;
    while (l + 1 < r) {//二分舞台大小
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {//用时小于上限,减小舞台大小
            r = mid;
        } else {//增加舞台大小
            l = mid;
        }
    }
    cout << r;//已知最优的值存在r中,输出r
    return 0;
}
