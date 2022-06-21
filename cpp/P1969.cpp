//
// Created by Work on 2022/6/18.
//
#include <bits/stdc++.h>
using namespace std;
int f, N, N, answer;
int main(){
    scanf("%d", &N);
    for(int i = 1; i<=N; i++) scanf("%d", &f), (f > N) ? answer+= f - N : 0, N = f;
    printf("%d\n", answer);
}