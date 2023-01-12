// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

//
// Created by Work on 2022/10/27.
//

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace data {
    struct date {
        int year, month, day;
    };
    struct date_full {
        int year, month, day, past;
    };
}

namespace judge {
    string __date_type(data::date __date) {
        if (__date.year == 1852 && __date.month == 10 && __date.day <= 4 or __date.year == 1852 &&
            __date.month < 10 or __date.year < 1852) {
            if (__date.year < 0) return "BCJulianDay";
            return "DCJulianDay";
        }
        if (__date.year == 1852 && __date.month == 10 && __date.day >= 15 or __date.year == 1852 &&
            __date.month > 10 or __date.year > 1852) {
            return "DCGregorianDay";
        }
        return "DayDoseNotExist";
    }

    string __leap_year(data::date __date) {
        if (judge::__date_type(__date).find("Dose") != -1) {
            return "DayDoseNotExist";
        }
        if (judge::__date_type(__date).find("Julian") != -1) {
            if (__date.year > 1) {
                if (__date.year % 4 == 0) {
                    return "DCJulianLeapYear";
                } else return "DCNotJulianLeapYear";
            }
            if (__date.year - 1 % 4 == 0) {
                return "BCJulianLeapYear";
            } else return "BCNotJulianLeapYear";
        }
        if (__date.year % 4 == 0 && __date.year % 100 != 0 or __date.year % 400 == 0) {
            return "DCGregorianLeapYear";
        }
        return "DCNotGregorianLeapYear";
    }
}

namespace convert {
    data::date __jp400y, __jp1y_Lp, __jp1y;
    int LeapYear[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int NotLeapYear[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int __month_day(data::date __date) {
        if (judge::__leap_year(__date).find("Not") == -1) {
            return LeapYear[__date.month];
        } else return NotLeapYear[__date.month];
    }

    data::date __jump_1_day(data::date __date) {
        if (__date.day == 1) {
            if (__date.month == 1) {
                if (__date.year == 1) {
                    return {-1, 12, 31};
                } else {
                    return {__date.year - 1, 12, 31};
                }
            }
            return {__date.year, __date.month - 1, __month_day(__date)};
        }
        return {__date.year, __date.month, __date.day - 1};
    }

    data::date_full __jump_1_year(data::date __date) {
        if (__date.month == 2 && __date.day == 29) {
            return {__date.year - 1, __date.month, 28, 366};
        }
        if (judge::__leap_year(__date).find("Not") == -1) {
//            if(judge::__leap_year({__date.year - 1, __date.month, __date.day}).find("Not") == -1) {
//
//            }
        }
    }
}

void __dfaksdjflkjsljisndfozxcv8908081230480980__jfjlkjhzlkjnfsdmxlzcvkmksdfj1__sdjfhlkjhxcklvjhaskldfjh1() {
    long long JulianDate;
    scanf("%lld", &JulianDate);
    long long InternationalYear, InternationalMonth, P = 0;
    bool ConsiderateLeapYear_In_Future4Year = false;
    if (JulianDate >= 2299161) goto a;
    JulianDate += 1095;
    InternationalYear = -4716 + JulianDate / 1461 * 4, JulianDate %= 1461;
    ConsiderateLeapYear_In_Future4Year = true;
    P = 1;
    goto b;
    a:;
    JulianDate -= 1721424;
    JulianDate += 10 - 12;
    InternationalYear = 1 + JulianDate / 146097 * 400, JulianDate %= 146097;
    if (JulianDate < 109572)goto c;
    InternationalYear += 300, JulianDate -= 109572;
    InternationalYear += JulianDate / 1461 * 4, JulianDate %= 1461;
    ConsiderateLeapYear_In_Future4Year = true;
    goto b;
    c:;
    InternationalYear += JulianDate / 36524 * 100, JulianDate %= 36524;
    if (JulianDate < 35064) goto d;
    InternationalYear += 96, JulianDate -= 35064;
    goto b;
    d:;
    InternationalYear += JulianDate / 1461 * 4, JulianDate %= 1461;
    ConsiderateLeapYear_In_Future4Year = true;
    goto b;
    b:;
    const int Day_2_Date[366][2] = {{0,  0},
                                    {0,  1},
                                    {0,  2},
                                    {0,  3},
                                    {0,  4},
                                    {0,  5},
                                    {0,  6},
                                    {0,  7},
                                    {0,  8},
                                    {0,  9},
                                    {0,  10},
                                    {0,  11},
                                    {0,  12},
                                    {0,  13},
                                    {0,  14},
                                    {0,  15},
                                    {0,  16},
                                    {0,  17},
                                    {0,  18},
                                    {0,  19},
                                    {0,  20},
                                    {0,  21},
                                    {0,  22},
                                    {0,  23},
                                    {0,  24},
                                    {0,  25},
                                    {0,  26},
                                    {0,  27},
                                    {0,  28},
                                    {0,  29},
                                    {0,  30},
                                    {1,  0},
                                    {1,  1},
                                    {1,  2},
                                    {1,  3},
                                    {1,  4},
                                    {1,  5},
                                    {1,  6},
                                    {1,  7},
                                    {1,  8},
                                    {1,  9},
                                    {1,  10},
                                    {1,  11},
                                    {1,  12},
                                    {1,  13},
                                    {1,  14},
                                    {1,  15},
                                    {1,  16},
                                    {1,  17},
                                    {1,  18},
                                    {1,  19},
                                    {1,  20},
                                    {1,  21},
                                    {1,  22},
                                    {1,  23},
                                    {1,  24},
                                    {1,  25},
                                    {1,  26},
                                    {1,  27},
                                    {1,  28},
                                    {2,  0},
                                    {2,  1},
                                    {2,  2},
                                    {2,  3},
                                    {2,  4},
                                    {2,  5},
                                    {2,  6},
                                    {2,  7},
                                    {2,  8},
                                    {2,  9},
                                    {2,  10},
                                    {2,  11},
                                    {2,  12},
                                    {2,  13},
                                    {2,  14},
                                    {2,  15},
                                    {2,  16},
                                    {2,  17},
                                    {2,  18},
                                    {2,  19},
                                    {2,  20},
                                    {2,  21},
                                    {2,  22},
                                    {2,  23},
                                    {2,  24},
                                    {2,  25},
                                    {2,  26},
                                    {2,  27},
                                    {2,  28},
                                    {2,  29},
                                    {2,  30},
                                    {3,  0},
                                    {3,  1},
                                    {3,  2},
                                    {3,  3},
                                    {3,  4},
                                    {3,  5},
                                    {3,  6},
                                    {3,  7},
                                    {3,  8},
                                    {3,  9},
                                    {3,  10},
                                    {3,  11},
                                    {3,  12},
                                    {3,  13},
                                    {3,  14},
                                    {3,  15},
                                    {3,  16},
                                    {3,  17},
                                    {3,  18},
                                    {3,  19},
                                    {3,  20},
                                    {3,  21},
                                    {3,  22},
                                    {3,  23},
                                    {3,  24},
                                    {3,  25},
                                    {3,  26},
                                    {3,  27},
                                    {3,  28},
                                    {3,  29},
                                    {4,  0},
                                    {4,  1},
                                    {4,  2},
                                    {4,  3},
                                    {4,  4},
                                    {4,  5},
                                    {4,  6},
                                    {4,  7},
                                    {4,  8},
                                    {4,  9},
                                    {4,  10},
                                    {4,  11},
                                    {4,  12},
                                    {4,  13},
                                    {4,  14},
                                    {4,  15},
                                    {4,  16},
                                    {4,  17},
                                    {4,  18},
                                    {4,  19},
                                    {4,  20},
                                    {4,  21},
                                    {4,  22},
                                    {4,  23},
                                    {4,  24},
                                    {4,  25},
                                    {4,  26},
                                    {4,  27},
                                    {4,  28},
                                    {4,  29},
                                    {4,  30},
                                    {5,  0},
                                    {5,  1},
                                    {5,  2},
                                    {5,  3},
                                    {5,  4},
                                    {5,  5},
                                    {5,  6},
                                    {5,  7},
                                    {5,  8},
                                    {5,  9},
                                    {5,  10},
                                    {5,  11},
                                    {5,  12},
                                    {5,  13},
                                    {5,  14},
                                    {5,  15},
                                    {5,  16},
                                    {5,  17},
                                    {5,  18},
                                    {5,  19},
                                    {5,  20},
                                    {5,  21},
                                    {5,  22},
                                    {5,  23},
                                    {5,  24},
                                    {5,  25},
                                    {5,  26},
                                    {5,  27},
                                    {5,  28},
                                    {5,  29},
                                    {6,  0},
                                    {6,  1},
                                    {6,  2},
                                    {6,  3},
                                    {6,  4},
                                    {6,  5},
                                    {6,  6},
                                    {6,  7},
                                    {6,  8},
                                    {6,  9},
                                    {6,  10},
                                    {6,  11},
                                    {6,  12},
                                    {6,  13},
                                    {6,  14},
                                    {6,  15},
                                    {6,  16},
                                    {6,  17},
                                    {6,  18},
                                    {6,  19},
                                    {6,  20},
                                    {6,  21},
                                    {6,  22},
                                    {6,  23},
                                    {6,  24},
                                    {6,  25},
                                    {6,  26},
                                    {6,  27},
                                    {6,  28},
                                    {6,  29},
                                    {6,  30},
                                    {7,  0},
                                    {7,  1},
                                    {7,  2},
                                    {7,  3},
                                    {7,  4},
                                    {7,  5},
                                    {7,  6},
                                    {7,  7},
                                    {7,  8},
                                    {7,  9},
                                    {7,  10},
                                    {7,  11},
                                    {7,  12},
                                    {7,  13},
                                    {7,  14},
                                    {7,  15},
                                    {7,  16},
                                    {7,  17},
                                    {7,  18},
                                    {7,  19},
                                    {7,  20},
                                    {7,  21},
                                    {7,  22},
                                    {7,  23},
                                    {7,  24},
                                    {7,  25},
                                    {7,  26},
                                    {7,  27},
                                    {7,  28},
                                    {7,  29},
                                    {7,  30},
                                    {8,  0},
                                    {8,  1},
                                    {8,  2},
                                    {8,  3},
                                    {8,  4},
                                    {8,  5},
                                    {8,  6},
                                    {8,  7},
                                    {8,  8},
                                    {8,  9},
                                    {8,  10},
                                    {8,  11},
                                    {8,  12},
                                    {8,  13},
                                    {8,  14},
                                    {8,  15},
                                    {8,  16},
                                    {8,  17},
                                    {8,  18},
                                    {8,  19},
                                    {8,  20},
                                    {8,  21},
                                    {8,  22},
                                    {8,  23},
                                    {8,  24},
                                    {8,  25},
                                    {8,  26},
                                    {8,  27},
                                    {8,  28},
                                    {8,  29},
                                    {9,  0},
                                    {9,  1},
                                    {9,  2},
                                    {9,  3},
                                    {9,  4},
                                    {9,  5},
                                    {9,  6},
                                    {9,  7},
                                    {9,  8},
                                    {9,  9},
                                    {9,  10},
                                    {9,  11},
                                    {9,  12},
                                    {9,  13},
                                    {9,  14},
                                    {9,  15},
                                    {9,  16},
                                    {9,  17},
                                    {9,  18},
                                    {9,  19},
                                    {9,  20},
                                    {9,  21},
                                    {9,  22},
                                    {9,  23},
                                    {9,  24},
                                    {9,  25},
                                    {9,  26},
                                    {9,  27},
                                    {9,  28},
                                    {9,  29},
                                    {9,  30},
                                    {10, 0},
                                    {10, 1},
                                    {10, 2},
                                    {10, 3},
                                    {10, 4},
                                    {10, 5},
                                    {10, 6},
                                    {10, 7},
                                    {10, 8},
                                    {10, 9},
                                    {10, 10},
                                    {10, 11},
                                    {10, 12},
                                    {10, 13},
                                    {10, 14},
                                    {10, 15},
                                    {10, 16},
                                    {10, 17},
                                    {10, 18},
                                    {10, 19},
                                    {10, 20},
                                    {10, 21},
                                    {10, 22},
                                    {10, 23},
                                    {10, 24},
                                    {10, 25},
                                    {10, 26},
                                    {10, 27},
                                    {10, 28},
                                    {10, 29},
                                    {11, 0},
                                    {11, 1},
                                    {11, 2},
                                    {11, 3},
                                    {11, 4},
                                    {11, 5},
                                    {11, 6},
                                    {11, 7},
                                    {11, 8},
                                    {11, 9},
                                    {11, 10},
                                    {11, 11},
                                    {11, 12},
                                    {11, 13},
                                    {11, 14},
                                    {11, 15},
                                    {11, 16},
                                    {11, 17},
                                    {11, 18},
                                    {11, 19},
                                    {11, 20},
                                    {11, 21},
                                    {11, 22},
                                    {11, 23},
                                    {11, 24},
                                    {11, 25},
                                    {11, 26},
                                    {11, 27},
                                    {11, 28},
                                    {11, 29},
                                    {11, 30}};
    if (JulianDate >= 1095 && ConsiderateLeapYear_In_Future4Year) { //第4年是闰年
        InternationalYear += 3, JulianDate -= 1095; //现在n是该年第几天
    } else {
        InternationalYear += JulianDate / 365, JulianDate %= 365;
        if (JulianDate >= 59) JulianDate++;
    }
    InternationalMonth = Day_2_Date[JulianDate][0] + 1, JulianDate = Day_2_Date[JulianDate][1] + 1;
    if (InternationalYear >= 0) InternationalYear += P;
    if (InternationalYear < 0) printf("%d %d %d BC\n", JulianDate, InternationalMonth, -InternationalYear);
    else printf("%d %d %d\n", JulianDate, InternationalMonth, InternationalYear);
    return;
}

int main() {
    freopen("one.in", "r", stdin);
    freopen("one.out", "w", stdout);
    long long l;
    scanf("%lld", &l);
    long long b;
    scanf("%lld", &b);
    printf("%lld\n", l + b);
    return 0;
    int a = 0;
    scanf("%d", &a);
    while (a--) __dfaksdjflkjsljisndfozxcv8908081230480980__jfjlkjhzlkjnfsdmxlzcvkmksdfj1__sdjfhlkjhxcklvjhaskldfjh1();
    return 0;
}
