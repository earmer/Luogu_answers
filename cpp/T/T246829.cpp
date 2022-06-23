//
// Created by Work on 2022/6/22.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long times, tmp, time, t;
    cin >> times;
//    cout << "TMP   TIME    T" << endl;
    while (times--) {
        cin >> t;
        tmp = 1, time = -1;
        for (;;) {
            tmp *= 2;
            time++, time %= 10;
//            cout << tmp << ' ' << time << ' ' << t  << ' ' << (t % tmp) + 1 << endl;
            if ((tmp >> 1) == (t % tmp) + 1)
                break;
        }
        cout << time << endl;
    }
}
//1
//43252898
