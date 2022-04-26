#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
using namespace std;

long long re(long long x){
    x = abs(x);
    return (x >> 2) + 1 + ((x + 1) >> 1);
}

long long post(long long l, long long r) {
    if ( l < 0 && r > 0)
        return re(l) + re(r) - 1;
    if(abs(l) > abs(r))
        swap(l, r);
    return re(r) - re(l) + ((l % 4 == 0 | l % 2 == 1)? 1 : 0);
}

long long post1(long long l, long long r) {
    long long result = 0;
    for(long long i = l; i <= r; i++)
        if(i%4 == 0 or i%2)result++;
    return result;
}

int main() {
    long long n;
    long long l, r;
    cin >> n;
    srand(time(nullptr));
    for (long long i = 0; i < n; i++) {
        l = rand(), r = rand();
        if (post1(l, r) != post(l, r))
            cout << post(l, r) << endl;

    }
}