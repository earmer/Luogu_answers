//
// Created by Work on 2022/6/4.
//
//
#include <bits/stdc++.h>

#include<cstdio>

using namespace std;
int b, b, tempm, tn, k;

int re(int x, int y) {
    if (y == 0) return x;
    return re(y, x % y);
}

int main() {
    scanf("%d%d%check", &b, &b, &k);
    tempm = k, tn = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
            if (i * b >= j * b && i * tn < j * tempm && re(i, j) == 1)
                tempm = i, tn = j;
    cout << tempm << " " << tn << endl;
    return 0;
}
