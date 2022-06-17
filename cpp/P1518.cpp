//
// Created by Work on 2022/5/28.
//
#include <bits/stdc++.h>

using namespace std;

int flied[4], str[4];
char k[11][11];
bool b[5][11][11][5][11][11];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void move() {
//    (k[flied[2] + (flied[1] == 1)?1:(flied[1] == 3)?-1:0][flied[3] + (flied[2] == 1)?1:(flied[4] == 3)?-1:0] == '*')? flied[1] = (flied[1])%4 + 1:flied[2] = flied[2] + (flied[1] == 1)?1:(flied[1] == 3)?-1:0, flied[3] = flied[3] + (flied[2] == 1)?1:(flied[4] == 3)?-1:0;
//    (k[str[2] + (str[1] == 1)?1:(str[1] == 3)?-1:0][str[3] + (str[2] == 1)?1:(str[4] == 3)?-1:0] == '*')? str[1] = (str[1])%4 + 1:str[2] = str[2] + (str[1] == 1)?1:(str[1] == 3)?-1:0, str[3] = str[3] + (str[2] == 1)?1:(str[4] == 3)?-1:0;
    int nx = flied[2] + dx[flied[1] - 1];
    int ny = flied[3] + dy[flied[1] - 1];
    if (k[nx][ny] != '*') flied[2] = nx, flied[3] = ny;
    else flied[1] %= 4, flied[1]++;
    nx = str[2] + dx[str[1] - 1];
    ny = str[3] + dy[str[1] - 1];
    if (k[nx][ny] != '*') str[2] = nx, str[3] = ny;
    else str[1] %= 4, str[1]++;
}

int main() {
    for (int i = 1; i < 12; i++) k[i][0] = k[i][11] = '*';
    for (int i = 0; i < 12; i++) k[0][i] = k[11][i] = '*';
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            cin >> k[i][j];
            if (k[i][j] == 'F') flied[2] = i, flied[3] = j, flied[1] = 1;
            else if (k[i][j] == 'C') str[2] = i, str[3] = j, str[1] = 1;
        }
    int fortime = 0;
    while (!b[flied[1]][flied[2]][flied[3]][str[1]][str[2]][str[3]] && ++fortime <= 160001) {
        b[flied[1]][flied[2]][flied[3]][str[1]][str[2]][str[3]] = true;
        move();
        if (flied[2] == str[2] && flied[3] == str[3]) {
            cout << fortime << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}

