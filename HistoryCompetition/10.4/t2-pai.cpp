// add_executable(t1 "Competition/t1.cpp")

#include<cstdio>
#include<iostream>
#include<vector>
//#include<map>

using namespace std;

struct Node {
	long long father = 0, fee;
	vector<int> children;
	int child = 0;
}tree[200010];

struct ret {
	long long fee, child;
};

ret dfs(int now) {
	//if (size(tree[now].children) == 0) {
	//	tree[now].fee = 1;
	//	return 1;
	//}
	long long fee = 0;
	int childrens = 0;
	for (auto child : tree[now].children) {
		//++childrens;
		ret a = dfs(child);
		childrens += a.child;
		fee += a.fee;
	}
	if (fee == 0) {
		tree[now].fee = 1;
		return {1, 1};
	}
	fee += childrens + 1;
	tree[now].fee = fee;
	return { fee , childrens};
}

void up(int i) {
	while (i != 0) {
		tree[i].child++;
		i = tree[i].father;
	}
}

int main() {
	int total;
	scanf("%d", &total);
	for (int i = 2; i <= total; i++) {
		scanf("%lld", &tree[i].father);
		tree[tree[i].father].children.push_back(i);
	}
	//for (int i = 1; i <= total; i++) {
	//	up(i);
	//}
	dfs(1);
	for (int i = 1; i <= total; i++) {
		printf("%lld ", tree[i].fee);
	}
	cout << endl;
	//for (int i = 1; i <= total; i++) {
	//	cout << tree[i].child << ' ';
	//}
	//cout << endl;
	return 0;
}