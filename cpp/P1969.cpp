//
// Created by Work on 2022/6/18.
//
#include <bits/stdc++.h>
using namespace std;
int f, N, n, answer;
int main(){
    scanf("%d", &N);
    for(int i = 1; i<=N; i++) scanf("%d", &f), (f > n) ?answer+=f-n:0, n = f;
    printf("%d\n", answer);
}