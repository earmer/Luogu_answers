//
// Created by Work on 2022/6/22.
//
#include <bits/stdc++.h>

using namespace std;
long long bigg[3] = {0, 0, 0}, smalll[3] = {1000001, 1000001, 1000001};

//void popup(){
//    long long i = 3;
//    while(i != 0 && bigg[--i] > bigg[i - 1]) swap(bigg[i], bigg[i - 1]);
//}
//
//void popdown(){
//    long long i = 3;
//    while(i != 0 && smalll[--i] < smalll[i - 1]) swap(smalll[i], smalll[i - 1]);
//}

int main() {
    long long n;
    cin >> n;
    long long num[n];
    long long sum = 0;

    for (long long i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
        bigg[2] = smalll[2] = num[i];
        if (bigg[2] > bigg[1]) swap(bigg[2], bigg[1]);
        if (bigg[1] > bigg[0]) swap(bigg[1], bigg[0]);
        if (smalll[2] < smalll[1]) swap(smalll[2], smalll[1]);
        if (smalll[1] < smalll[0]) swap(smalll[1], smalll[0]);
    }
    cout << (sum - bigg[0] - bigg[1] - smalll[1] - smalll[0]) / (n - 4) << endl;
    return 0;
}