#include<bits/stdc++.h>

using namespace std;
int total[7];

int main() {
    int n, a, b;
    cin >> n;
    while(n--){
        scanf ("%d %d", &a, &b);
        if(a < 0 && b > 0){
            a = abs(a);
            cout << (a + 4)/4 + (a + 1) / 2 + (b) / 4 + (b + 1) / 2 << endl;
            continue;
        }
        a = abs(a);
        b = abs(b);
        if (a > b) swap(a, b);
        cout <<abs((b+ 4) / 4 + (b + 1) / 2 -  (a + 3)/4 - (a) / 2)<< endl;
    }
    return 0;
}