// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>

struct pp {
	std::string name = "";
	int birthday = 0;
	int id;
	bool operator <(const pp n) const {
		if (n.birthday != birthday) return n.birthday > birthday;
		return n.id < id;
	}
};

pp person[1000];

pp convert(std::string n, int year, int month, int day, int id) {
	pp nw;
	nw.name = n;
	nw.birthday = year * 10000 + month * 100 + day;
	nw.id = id;
	return nw;
}

int main() {
	int year, month, day;
	std::string name;
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> name >> year >> month >> day;
		person[i] = convert(name, year, month, day, i);
	}
	std::sort(person + 1, person + n + 1);
	for (int i = 1; i <= n; i++) {
		std::cout << person[i].name/* << ' ' << person[i].birthday */ << '\n';
	}
	std::cout << std::endl;
	//std::cin >> name >> year >> month >> day;
	//person[1] = convert(name, year, month, day);
	//std::cout << person[1].name << person[1].birthday << std::endl;
	return 0;
}