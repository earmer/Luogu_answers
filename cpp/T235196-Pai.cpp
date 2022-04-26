//
// Created by 101 on 2022-04-26.
//
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int post(int s){
    if(s == 1) return 2;
    return 2 * post(s - 1);
}

int main() {
    for(int i = 1;i<25;i++)
        cout<<post(i)<<", ";
    return 0;
}
