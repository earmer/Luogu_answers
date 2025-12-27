// Copyright (c) 2025. earmer.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

/*
简单来说，这道题是一个分层图，不同层用代表用了几次免费。

一个常见的错误想法是：希望通过动态维护每条路径上最贵的K趟航班来计算最小花费。
这是不行的，因为违反了Dijkstra的确定性要求。

要注意的是，最终的答案不一定就在第k层的终点t。
因为有一定可能用不到那么多次免费，所以要取所有层的终点t的最小值。
不过由于这道题的条件是免费，所以也可以每层t都连一个到最终层t的0权边。
这样只取k层的t就是正确的了。

*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int maxN = 1e4 + 5;
const int maxM = 5e4 + 5;

struct E
{
    int v, w, l;
    // to, weight, layer
};

vector<E> G[11][maxN];
int dist[11][maxN];
// 这里其实完全没有必要去用k实际上多层图，可以改成Dijkstra循环内处理。

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int s, t;
    cin >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        for (int j = 0; j <= k; j++)
        {
            G[j][u].push_back({v, w, j});
            G[j][v].push_back({u, w, j});
            if (j < k)
            {
                G[j][u].push_back({v, 0, j + 1});
                G[j][v].push_back({u, 0, j + 1});
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        G[i][t].push_back({t, 0, i + 1});
    }
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[0][s] = 0;

    struct Ele
    {
        int cost;
        int x, y;
        bool operator>(const Ele &other) const
        {
            if (cost != other.cost)
                return cost > other.cost;
            if (x != other.x)
                return x > other.x;
            return y > other.y;
        }
    };

    priority_queue<Ele, vector<Ele>, greater<Ele>> q;
    q.push({0, s, 0});
    while (!q.empty())
    {
        int u = q.top().x, l = q.top().y, cost = q.top().cost;
        q.pop();
        if (cost > dist[l][u])
            continue;
        for (auto i : G[l][u])
        {
            int v = i.v, lv = i.l, w = i.w;
            if (dist[lv][v] > (w + dist[l][u]))
            {
                dist[lv][v] = w + dist[l][u];
                q.push({dist[lv][v], v, lv});
            }
        }
    }
    cout << dist[k][t] << endl;
    return 0;
}