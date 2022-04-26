//
// Created by 101 on 2022-04-26.
//
#include <bits/stdc++.h>

using namespace std;
int num[14] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
bool ret[14] = {false};
string s;

void pt(){

}

void find(int n) {
//    bool ret[14] = {false};
    for (int i = 13; i >= 0; i--) {
        if (n >= num[i]) {
            ret[i] = true;
            n -= num[i];
        }
    }
}


int main() {
    int n;
    cin >> n;
    find(n);
    cout <<  pt();
    return 0;
}