#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int post(int l, int r) {
    if ( l < 0 && r > 0)
        return (abs(l-1)>>1 )+ (abs(l+1)>>2) + (abs(r+1)>>1) + (abs(r / 4) + 1);
    if(abs(l) > abs(r))
        swap(l, r);
    return ((abs(r) + 1)>>1) + (abs(r) >> 2) - (abs(l) >> 1) - ((abs(l) - 1) >> 2);
}

int main() {
    int n;
    int l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        cout << post(l, r);
    }
    return 0;
}
