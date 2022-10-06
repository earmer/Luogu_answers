// add_executable(t1 "Competition/t1.cpp")

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

bool check(int k, string& s) {
	map<string, bool> m;
	for (int i = 0; i <= s.length() - k; i++) {
		string tmp = "";
		for (int j = i; j < i + k; j++) {
			tmp += s[j];
		}
		if (m[tmp]) return false;
		m[tmp] = true;
	}
	return true;
}

int main() {
	string str;
	int t;
	cin >> t >> str;
	int l = 1, r = t;
	for (int i = 1; i <= t; i++) {
		if (check(i, str)) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}