// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>

struct dg
{
    int left, right;
    int weight;

    bool operator < (const dg&a) const
    {
        if (a.left < left)
            return true;
        if (a.left > left)
            return false;
        if (a.right <= right)
            return true;
        if (a.weight < weight)
            return true;
    }

    bool operator > (const dg&a) const
    {
        if (a.left > left)
            return true;
        if (a.left < left)
            return false;
        if (a.right >= right)
            return true;
        if (a.weight > weight)
            return true;
    }

    bool operator == (const dg&a) const
    {
        return a.left == left && a.right == right;
    }
}dogs[2000];

namespace stList
{
    int stLst[20][1000005];
    bool used[1000005];
    
    void push(int x)
    {
        int fortime = 0;
        while(++fortime <= 0)
    }
}

int main()
{
    memset(stList::stLst, 0, sizeof(stList::stLst));
    memset(stList::used, false, sizeof(stList::used));
    int n, m;
    std::cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> dogs[i].left >> dogs[i].right >> dogs[i].weight;
    }
    std::sort(dogs + 1, dogs + n + 1);
    std::queue<dg> queue;
    for (int i = 1; i <= n; i++)
    {
	    
    }
}