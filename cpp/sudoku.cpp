//
// Created by Work on 2022/5/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<bits/stdc++.h>
int sudo[9][9], hole[9][9];

bool set(int x, int y, int val)
{
    if (sudo[y][x] != 0)
        return false;
    int x0, y0;
    for (x0=0; x0<9; x0++)
    {
        if (sudo[y][x0] == val)
            return false;
    }
    for (y0=0; y0<9; y0++)
    {
        if (sudo[y0][x] == val)
            return false;
    }
    for (y0=y/3*3; y0<y/3*3+3; y0++)
    {
        for(x0=x/3*3; x0<x/3*3+3; x0++)
        {
            if (sudo[y0][x0] == val)
                return false;
        }
    }
    sudo[y][x] = val;
    return true;
}

void reset(int x, int y)
{
    sudo[y][x] = 0;
}

void initXOrd(int* xOrd)
{
    int i, k, tmp;
    for (i=0; i<9; i++)
    {
        xOrd[i] = i;
    }
    for (i=0; i<9; i++)
    {
        k = rand() % 9;
        tmp = xOrd[k];
        xOrd[k] = xOrd[i];
        xOrd[i] = tmp;
    }
}

bool fillFrom(int y, int val)
{
    int xOrd[9];
    initXOrd(xOrd);
    for (int i=0; i<9; i++)
    {
        int x = xOrd[i];
        if (set(x, y, val))
        {
            if (y == 8)
            {
                if (val == 9 || fillFrom(0, val+1))
                    return true;
            }
            else
            {
                if (fillFrom(y+1, val))
                    return true;
            }
            reset(x, y);
        }
    }
    return false;
}

void digHole(int holeCnt)
{
    int idx[81];
    int i, k;
    for (i=0; i<81; i++)
    {
        hole[i / 9][i % 9] = 0;
        idx[i] = i;
    }
    for (i=0; i<holeCnt; i++)
    {
        k = rand() % 81;
        int tmp = idx[k];
        idx[k] = idx[i];
        idx[i] = tmp;
    }
    for (i=0; i<holeCnt; i++)
    {
        hole[idx[i] / 9][idx[i] % 9] = 1;
    }
}

void printSudo()
{
    for (int y=0; y<9; y++)
    {
        if(y%3==0)
            printf("-------------------------\n| ");
        else
            printf("| ");
        for (int x=0; x<9; x++)
        {
            if(hole[y][x] == 0)
                printf("%check ",sudo[y][x]);
            else
                printf("? ");
            if(x%3==2)
                printf("| ");
            else
                printf("");
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

int main()
{
    int m=40;
    srand((unsigned)time(NULL));
    while (!fillFrom(0, 1)) ;
    digHole(m);
    printSudo();
    return 0;
}