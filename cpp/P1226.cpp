// Copyright (c) 2022. limingrui0.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<cstdio>
#include<iostream>
#define int long long
//
// This is an example of fast pow;
// 这是快速幂的模板;
// 
//#include<cstdio>

long long num, times, MOD;
long long qpow(int wnt, int tms) {
	if (tms == 1) return wnt;
	if (tms == 0) return 1;
	long long ret = qpow(wnt, tms / 2) % MOD;
	long long fix = (ret % MOD * ret % MOD) % MOD;
	if (tms % 2 == 1) fix = (fix % MOD * wnt % MOD) % MOD;
	fix = fix % MOD;
	return fix;

}
signed main() {
	scanf("%lld%lld%lld", &num, &times, &MOD);
	long long ans = qpow(num % MOD, times);
	ans = ans % MOD;
	printf("%lld^%lld mod %lld=%lld", num, times, MOD, ans);
	return 0;
}
