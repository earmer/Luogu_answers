// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/12/2.
//

#include <cstdio>

using namespace std;
int nowLineA, nowColumnA, nowColumnB, toLine;

signed graph[1005][1005];
long long cover[1005][1005];

int main() {
    int mapSize, carpetNum;
    scanf("%d%d", &mapSize, &carpetNum);
    for (int i = 0; i < carpetNum; ++i) {
        scanf("%d%d%d%d", &nowLineA, &nowColumnA, &toLine, &nowColumnB);
        ++graph[nowLineA][nowColumnA];
        --graph[nowLineA][nowColumnB + 1];
        --graph[toLine + 1][nowColumnA];
        ++graph[toLine + 1][nowColumnB + 1];
    }
    for (int i = 1; i <= mapSize; i++) {
        for (int j = 1; j <= mapSize; j++) {
            cover[i][j] = cover[i - 1][j] + cover[i][j - 1] - cover[i - 1][j - 1] + graph[i][j];
            printf("%lld ", cover[i][j]);
        }
        printf("\n");
    }
    return 0;
}