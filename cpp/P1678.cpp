// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<cstdio>
#include<iostream>
#include <algorithm>

using namespace std;
int schools[100000], students[100000];

int main()
{
	int ans = 0, y;
	int max = 1000000;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> schools[i];
	sort(schools + 1, schools + n + 1);
	for (int j = 1; j <= m; j++)
		cin >> students[j];
	int l, r, mid;
	for (int i = 1; i <= m; i++)
	{
		l = 1;
		r = n;
		while (l < r)
		{
			mid = (l + r) >> 1;
			if (students[i] >= schools[mid])
				l = mid;
			else r = mid - 1;
		}
		if ((students[i] - schools[l]) < abs(schools[r] - students[i]))
			y = abs(students[i] - schools[l]);
		else y = abs(schools[r] - students[i]);
		ans += y;
	}
	cout << ans << endl;
	return 0;
}
