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
		ret re = dfs(child);
		fee += re.fee;
		childrens += re.child;
	}
	tree[now].fee = fee + childrens + 1;
	return { fee + childrens + 1, childrens + 1 };
}

//void up(int i) {
//	while (i != 0) {
//		tree[i].child++;
//		i = tree[i].father;
//	}
//}

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