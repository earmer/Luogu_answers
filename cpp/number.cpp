#include<cstdio>
#include<iostream>

using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int big = -1000000000, small = 1000000000, n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp > big) big = temp;
        if (temp < small) small = temp;
    }
    cout << 2 * (big - small) << endl;
    return 0;
}
