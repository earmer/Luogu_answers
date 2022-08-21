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
int appear[MAX * 2]; // Calculate times for the particular numbers appear in the question array
int sml[MAX];
answer lft[MAX] = {0, 0}, rgt[MAX] = {0, 0};
int answers[MAX]; // Array of integers that will be used for computer the answer

bool cmp(answer a, answer b) {
    return a.p <= b.p;
}

int main() {
    int length, question, middle, answer = 0; // Array of integers that will be used for computer the answer
    cin >> length >> question >> middle; // Read the array length and the number of question(small)
    int chong;
    for (int i = 1; i <= length; i++) {
        cin >> arr[i]; // Read the array
        if (arr[i] == middle) {
            chong = i;
            sml[i] = sml[i - 1];
            continue;
        }
        (arr[i] > middle) ? sml[i] = sml[i - 1] + 1 : sml[i] = sml[i - 1] - 1;
    }
    for (int i = 1; i <= question; i++) {
//        int lft, rgt;
        cin >> lft[i].p >> rgt[i].p; // Read the question
        lft[i].o = rgt[i].o = i;
    }
    sort(lft + 1, lft + question + 1, cmp), sort(rgt + 1, rgt + question + 1, cmp); // Sort
    appear[1000000] = 1;
    for (int i = 1; i <= question; i++) {
        for (int j = rgt[i - 1].p + 1; j <= rgt[i].p; j++) {
            if (j == chong) {
                answer++;
                continue;
            }
            answer += appear[sml[j] + 1000000];
            appear[sml[j] + 1000000]++;
        }
        for (int j = lft[i - 1].p; j < lft[i].p - 1; j++) {
            if (j > chong) {
                answer = 0;
                break;
            }
            answer -= appear[sml[j] + 1000000];
            appear[sml[j] + 1000000]--;
        }
        answers[lft[i].o] = answer;
    }
    for (int i = 1; i <= question; i++) { cout << answers[i] << endl; }
    return 0;
}