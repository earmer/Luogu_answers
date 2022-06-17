//
// Created by Work on 2022/5/28.
//
#include <bits/stdc++.h>

using namespace std;
int b[100005], I = 2, color, cow, volume;
int main(){
//    int cow, volume;
    cin >> cow >> volume;

    for(int i = 1; i <= cow; i++)
        cin >> b[i];
//    sort(b + 1, b + cow + 1);
//    int I = 2, color = 0;
    for(int i = 1; i < cow; i++){
        while(I <= cow && b[I] - b[i] <= volume) ++I;
        I--;
        color += I - i;
    }
    cout << color << endl;
    return 0;
}