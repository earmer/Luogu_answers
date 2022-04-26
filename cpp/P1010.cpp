//
// Created by 101 on 2022-04-26.
//
#include <bits/stdc++.h>

using namespace std;
int num[14] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
bool ret[14] = {false};
string s;

int temp;
int find(int n, int x)
{
    if (x == 1)
        return temp;
    //    bool ret[14] = {false};
    for (int i = 13; i >= 0; i--)
    {
        if (n >= num[i])
        {
            temp = num[i];
            return i;
        }
    }
}

void prt(int n)
{
    cout << "2";
    if (n != 2)
    {
        int mi = find(n, 0);
        int calculate = n - mi;
        cout << "(" << prt(mi - 1) << ")";
        if (n - find(n, 1))
            cout << "+" << prt(n - find(n, 1));
    }
    if (n == 1)
        cout << "(0)";
}

int main()
{
    int n;
    cin >> n;
    find(n);
    cout << pt();
    return 0;
}