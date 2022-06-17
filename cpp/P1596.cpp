#include<cstdio>
#include<iostream>
#include <cstring>

using namespace std;

int color;

struct position {
    int x, y;
};
int ball[5005];
position p;

void find(int x, int y) {
    for (int i = x; i <= y; ++i) {
        int color = ball[i];
        bool flag = true;
        for (int j = y; j > i; --j) {
            if (ball[j] == color) {
                flag = false;
                b_find(i + 1, j - 1);
                i = j;
                break;
            }
        }
        if (flag) {
            ++color;
//            cout << ball[i] << " ";
        }
    }
}

int ball1[5005];

int main() {
//    freopen("abab.in", "r", stdin);
//    freopen("abab.out", "w", stdout);
    memset(ball1, -1, sizeof(ball));
    int n, tmp;
    cin >> n >> tmp;
    int pin = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ball1[i];
    }
    ball[0] = ball1[0];
    for (int i = 1; i < n; ++i) {
        if (ball1[i] != ball1[i - 1]) {
            ball[++pin] = ball1[i];
        }
    }
//    for (int i = 0; i < pin; ++i) {
//        cout << ball[i];
//    }
//    cout << endl;
    b_find(0, pin);
    cout << color << endl;
    return 0;
}
