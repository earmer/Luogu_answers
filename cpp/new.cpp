#include <bits/stdc++.h>

using namespace std;


int main() {
    string s[5] = {"yuan", "yuanmingyuan", "yubn"};
    sort(s, s + 5);
    for (int i = 0; i < 5; i++)
        cout << s[i] << endl;
    return 0;
}