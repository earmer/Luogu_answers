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
int s[MAX];
ans lft[MAX], rgt[MAX];
int answers[MAX]; // Array of integers that will be used for computer the answer

bool cmp(ans a, ans b) {
    return a.p <= b.p;
}

int main() {
    int length, question, middle, answer = 0, mid; // Array of integers that will be used for computer the answer
    cin >> length >> question >> middle; // Read the array length and the number of question(s)
    for (int i = 1; i <= length; i++) cin >> arr[i];
    for (int i = 1; i <= length; i++) if (arr[i] == middle) mid = i;
    for (int i = 1; i <= length; i++)
        (arr[i] > middle) ? s[i] = s[i - 1] + 1 : (arr[i < middle]) ? s[i] = s[i - 1] - 1 : 0;

    for (int i = 1; i <= question; i++) cin >> lft[i].p >> rgt[i].p;
    for (int i = 1; i <= question; i++) lft[i].o = rgt[i].o = i;
    sort(lft, lft + question + 1, cmp), sort(rgt, rgt + question + 1, cmp);
    s[0] = 0;
    appear[s[0] + 1000000]++;
    int l = 0, r = 0;

//    cout << 1 << endl;

    for (int i = 1; i <= question; i++) {
        for (int j = r + 1; j <= rgt[i].p; j++) {
            appear[s[j] + 1000000]++;
            if (j < mid) continue;
            answer += appear[s[j] + 1000000];
        }
//        cout << 1 << endl;
        for (int j = l; j < lft[i].p; j++) {
            appear[s[j] + 1000000]--;
            if (j > mid) {
                answer = 0;
                break;
            }
            answer -= appear[s[j] + 1000000];
        }
//        cout << 1 << endl;
        l = lft[i].p - 1, r = rgt[i].p;
        answers[lft[i].o] = answer;
    }
    for (int i = 1; i <= question; i++) cout << answers[i] << endl;
    return 0;
}