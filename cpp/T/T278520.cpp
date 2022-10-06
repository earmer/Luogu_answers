#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

struct Node {
	int day, buget;
};

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::flush;
int total_days, buget_days, buget_spices, last_days, kinds_to_get;
Node ary[200010];
int rgtpin = 1, lftpin = 1;
int buget[200010], now_exist;
int hpdays;

void refresh() {
	while (ary[rgtpin].day - ary[lftpin].day + 1 > last_days && lftpin <= rgtpin) {
		if (buget[ary[lftpin].buget] == 1) now_exist--;
		buget[ary[lftpin].buget]--;
		lftpin++;
	}
	return;
}

void fix() {
	refresh();
	if (now_exist >= kinds_to_get) hpdays++;
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cin >> total_days >> buget_days >> buget_spices >> last_days >> kinds_to_get;
	for (int i = 1; i <= buget_days; i++) {
		int day, buget_id;
		cin >> day >> buget_id;
		if (buget[buget_id] == 0) now_exist++;
		buget[buget_id]++;
		rgtpin++, ary[rgtpin] = { day, buget_id };
		fix();
	}
	//for (int i = 1; i <= buget_spices; i++) {
	//	cout << buget[i] << ' ';
	//}
	//cout << '\n';
	cout << hpdays << '\n' << flush;
	return 0;
}