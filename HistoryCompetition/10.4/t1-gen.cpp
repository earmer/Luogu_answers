#include<cstdio>
#include<random>
#include<iostream>
#include<algorithm>
#include<time.h>

using namespace std;

int main() {
	srand(time(0));
	int ran = rand()% 99 + 1;
	cout << ran << endl;
	for (int i = 1; i <= ran; i++) {
		cout << (char)('A' + rand() % 26);
	}
	return 0;
}