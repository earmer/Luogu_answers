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
ans lft[MAX], rgt[MAX];
int answers[MAX]; // Array of integers that will be used for computer the answer

bool cmp(ans a, ans b) {
    return a.p <= b.p;
}

int main() {
    int length, question, middle, answer = 0; // Array of integers that will be used for computer the answer
    cin >> length >> question >> middle; // Read the array length and the number of question(s)
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
//    if(lft[1] == middle) answer++; // Answer
    for (int i = lft[1].p - 1; i <= rgt[1].p; i++) {// Find the first answer
        appear[sml[i] + 1000000]++;
        if (i < chong) continue;
        answer += appear[sml[i] + 1000000] - 1;
        answers[lft[1].o] = answer;
    }
//    for (int i = 1; i <= question; i++) {
//        if (lt[i] == lft[1] && rt[i] == rgt[1])
//            answers[i] = answer;
//    }
//    appear[100000]--;
    for (int i = 2; i <= question; i++) {
        for (int j = rgt[i - 1].p + 1; j <= rgt[i].p; j++) {
            appear[sml[j] + 1000000]++;
            if (j < chong) continue;
            answer += appear[sml[j] + 1000000] - 1;
        }
        for (int j = lft[i - 1].p; j < lft[i].p; j++) {
            answer -= appear[sml[j - 1] + 1000000] - 1;
            if (j > chong) {
                answer = 0;
                break;
            }
            appear[sml[j - 1] + 1000000]--;
        }
//        for (int j = 1; j <= question; j++) {
//            if (lt[j] == lft[i] && rt[j] == rgt[i])
//                answers[j] = answer;
//        }
        answers[lft[i].o] = answer;
    }
    for (int i = 1; i <= question; i++) { cout << answers[i] << endl; }
    return 0;
}