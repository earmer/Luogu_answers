// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/6/23.
//
#include <bits/stdc++.h>
//the time use will be O(N + M) times

struct ans {
    int p, o;
};

using namespace std;
const int MAX = 1000005; // Max number of 1000000
int arr[MAX]; // Array of integers that will be used for computer the answer
int appear[MAX * 3]; // Calculate times for the particular numbers appear in the question array
int small[MAX];
answer lft[MAX], rgt[MAX];
int answers[MAX]; // Array of integers that will be used for computer the answer

bool cmp(answer a, answer b) {
    return a.p <= b.p;
}

int main() {
    int length, question, middle, answer = 0, mid; // Array of integers that will be used for computer the answer
    cin >> length >> question >> middle; // Read the array length and the number of question(small)
    for (int i = 1; i <= length; i++) cin >> arr[i];
    for (int i = 1; i <= length; i++) if (arr[i] == middle) mid = i;
    for (int i = 1; i <= length; i++)
        (arr[i] > middle) ? small[i] = small[i - 1] + 1 : (arr[i < middle]) ? small[i] = small[i - 1] - 1 : 0;

    for (int i = 1; i <= question; i++) cin >> lft[i].p >> rgt[i].p;
    for (int i = 1; i <= question; i++) lft[i].o = rgt[i].o = i;
    sort(lft, lft + question + 1, cmp), sort(rgt, rgt + question + 1, cmp);
    small[0] = 0;
    appear[small[0] + 1000000]++;
    int l = 0, r = 0;

//    cout << 1 << endl;

    for (int i = 1; i <= question; i++) {
        for (int j = r + 1; j <= rgt[i].p; j++) {
            appear[small[j] + 1000000]++;
            if (j < mid) continue;
            answer += appear[small[j] + 1000000];
        }
//        cout << 1 << endl;
        for (int j = l; j < lft[i].p; j++) {
            appear[small[j] + 1000000]--;
            if (j > mid) {
                answer = 0;
                break;
            }
            answer -= appear[small[j] + 1000000];
        }
//        cout << 1 << endl;
        l = lft[i].p - 1, r = rgt[i].p;
        answers[lft[i].o] = answer;
    }
    for (int i = 1; i <= question; i++) cout << answers[i] << endl;
    return 0;
}