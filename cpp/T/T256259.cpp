//
// Created by Work on 2022/7/21.
//
#include <bits/stdc++.h>

using namespace std;

struct tree {
    int left, right;
    char value;
} trees[1005];

char num[1005];
int pin = 0, length;

int Dfs(int now) {
    trees[++pin].value = num[x];
    int temp = pin;
    if (num[x + 1] != '.')trees[temp].left = pin + 1, x = Dfs(x + 1);
    else x++;
    if (num[x + 1] != '.')trees[temp].right = pin + 1, x = Dfs(x + 1);
    else x++;
    if (trees[temp].left == trees[temp].right) trees[temp].left = trees[temp].right = 0;
    return x;
}

void mid(int pos) {
    if (pos == 0) return;
//	cout << trees[pos].left << ' ' ;
    if (trees[pos].left)mid(trees[pos].left);
    cout << trees[pos].value;
    if (trees[pos].right)mid(trees[pos].right);
}

void last(int pos) {
    if (pos == 0) return;
//	cout << trees[pos].left << ' ' ;
    if (trees[pos].left)last(trees[pos].left);
    if (trees[pos].right)last(trees[pos].right);
    cout << trees[pos].value;
}

int main() {
    while (cin >> num[++length]);
    Dfs(1);
    mid(1);
    cout << endl;
    last(1);
    cout << endl;
//	for(int i = 1; i <= pin; i++){
//		cout << trees[i].left << ' ' << trees[i].right << ' ' << trees[i].value << endl;
//	}
    return 0;
}