
//add_executable(t3 "Competition/t3.cpp")
//add_executable(t4 "Competition/t4.cpp")

#include<cstdio>
#include<map>
#include<iostream>
#include <string>
#include<cstring>

using std::string;
using std::cin;
using std::cout;
using std::flush;
using std::map;
char str[2005];

int main() {
	int n;
	cin >> n;
	while (n--) {
		scanf("%s", &str);
		char mp[128];
		std::memset(mp, 0, sizeof(mp));
		char now = 'a' - 1;
		int i = -1;
		while (str[++i] != '\0') {
			if (mp[str[i]] == 0) {
				now++;
				mp[str[i]] = now;
			}
			cout << mp[str[i]];
		}
		cout << '\n';
	}
	cout << flush;
	return 0;
}