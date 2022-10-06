// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<iostream>
#include<cstdio>
#include <algorithm>

using namespace std;

struct node {
	int height, force;
}apple[100000];

bool cmp(node a, node b) {
	return a.force < b.force;
}

int main() {
	int n, s;
	int a, b;
	int fortime = 0;
	cin >> n >> s >> a >> b;
	a += b;
	for (int i = 1; i <= n; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		apple[i].force = temp2, apple[i].height = temp1;
	}
	sort(apple + 1, apple + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (apple[i].height > a) continue;
		//cout << apple[i].force << ' ' << apple[i].height << ' ' << s << endl;
		if (s >= apple[i].force) s -= apple[i].force, ans++;
		else break;
	}
	cout << ans << endl;
	return 0;
}