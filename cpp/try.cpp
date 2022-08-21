// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

///
// 程序名称：毕达哥拉斯树（Pythagoras tree）
// 编译环境：Mictosoft Visual Studio 2010, EasyX_20200315(beta)
//
#include <graphics.h>
#include <conio.h>
#include <math.h>

const double PI = 3.1415926536;

// 定义一个结构体 Point，存储点的坐标
struct Point {
    double x;
    double y;
};

// 直线的旋转（p1 是定点）
Point Rotate(Point p1, Point p2, double angle) {
    Point r;
    r.x = p1.x + (p2.x - p1.x) * cos(angle) + (p2.y - p1.y) * sin(angle);
    r.y = p1.y + (p2.y - p1.y) * cos(angle) - (p2.x - p1.x) * sin(angle);
    return r;
}

// 直线的缩放（p1 是定点）
Point Zoom(Point p1, Point p2, double ratio) {
    Point r;
    r.x = p1.x + (p2.x - p1.x) * ratio;
    r.y = p1.y + (p2.y - p1.y) * ratio;
    return r;
}

// 画出正方形
void Draw(Point p1, Point p2) {
    Point p11 = Rotate(p1, p2, 90 * PI / 180);
    Point p22 = Rotate(p2, p1, 270 * PI / 180);

    POINT pts[] = {{int(p1.x + 0.5),  int(p1.y + 0.5)},                    // +0.5 是为了四舍五入
                   {int(p2.x + 0.5),  int(p2.y + 0.5)},
                   {int(p22.x + 0.5), int(p22.y + 0.5)},
                   {int(p11.x + 0.5), int(p11.y + 0.5)}};

    static int color_H = 270;
    setfillcolor(HSVtoRGB(float(color_H), 1, 1));                            // 设置正方形的填充颜色
    setlinecolor(HSVtoRGB(float((color_H + 80) % 360), 0.5, 0.5));            // 设置正方形的边框颜色
    color_H = (color_H + 1) % 360;
    fillpolygon(pts, 4);                                                    // 填充正方形颜色

    if (((p22.x - p11.x) * (p22.x - p11.x) + (p22.y - p11.y) * (p22.y - p11.y)) > 3 * 3)    // 正方形的边长 >3 时递归
    {
        double a = 60 * PI / 180;                    // 60 度形式
//		double nums = 45 * PI / 180;					// 45 度形式
        Point p = Rotate(p11, p22, a);
        p = Zoom(p11, p, cos(a));

        Draw(p, p22);
        Draw(p11, p);
    }
}

// 主函数
int main() {
    initgraph(640, 480);                // 初始化窗口
    setbkcolor(0xfecaeb);                // 设置背景颜色
    cleardevice();

    Point p1 = {290, 400};
    Point p2 = {350, 400};
    Draw(p1, p2);

    _getch();
    closegraph();                        // 关闭窗口
    return 0;
}