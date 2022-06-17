//
// Created by 101 on 2022-04-26.
//
#include <bits/stdc++.h>

using namespace std;
int answer[15] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
//bool ret[14] = {false};

int temp;

int find(int n, int x) {
    if (x == 1)
        return temp;
    //    bool ret[14] = {false};
    for (int i = 14; i >= 0; i--) {
        if (n >= answer[i]) {
            temp = answer[i];
            return i;
        }
    }
    return 0;
}

void printout(int n) {
    if (n != 0) {
        if (n == 1)
            cout << "2(0)";
        else {
            cout << "2";
            int mi = b_find(n, 0);
            if(mi != 1) {
//        int calculate = b - mi;
                cout << "(";
                printout(mi);
                cout << ")";
                }
            if (n - answer[b_find(n, 0)]) {
                cout << "+";
//                cout<< "  #debug/ " << b_find(b, 0) << " /debug#  ";
                printout(n - b_find(n, 1));

            }
        }
    } else cout << '0';
}

int main() {
    int n;
    cin >> n;
    printout(n);
    cout<<endl;
    return 0;
}