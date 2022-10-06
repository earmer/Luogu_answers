#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000010;

int n;
vector<int> a[N], f[N];
int length[N];
int ret[N];
int now = 1;

int main()
{
	int op;
	scanf("%d", &op);
	int lst = 0;
	for (int i = 1; i <= op; i++)
	{
		int o;
		scanf("%d", &o);
		if (o == 0) {
			int tmp;
			scanf("%d", &tmp);
			length[now]++;
			a[now].push_back(tmp);

		}
	}

	return 0;
}
