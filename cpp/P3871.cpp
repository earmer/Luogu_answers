//
// Created by Work on 2022/7/18.
//
#include<bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<int> > big;
priority_queue<int> small;
string tmp;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        small.push(temp);
    }
    for (int i = 1; i <= n / 2; i++)
        big.push(small.top()), small.pop();
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> tmp;
        if (tmp[0] == 'a') {
            int temp;
            n++;
            cin >> temp;
            (temp > small.top()) ? big.push(temp) : small.push(temp);
        } else {
            while (small.size() < (n + 1) / 2)
                small.push(big.top()), big.pop();
            while (small.size() > (n + 1) / 2)
                big.push(small.top()), small.pop();
            cout << small.top() << endl;;
        }
    }
    return 0;
}