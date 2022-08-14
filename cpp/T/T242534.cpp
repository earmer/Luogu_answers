#include <bits/stdc++.h>

using namespace std;

const int MaxN = 3000 + 5;
int n, As[MaxN], It[MaxN];
bool Dr[MaxN];
priority_queue<int, vector<int>, greater<int> > Pq;
int Rc[30005];

struct button {
    short pop[30005];
};
vector<button> Mv;

bool Solve() {
    for (int i = 1; i <= n; ++i)
        if (It[i] == 0)
            Pq.push(i);
    if (Pq.size() == 0)
        return false;
    for (int i = 1; i <= n; ++i) {
        int Ht = Pq.top();
        Pq.pop();
        if (Dr[Ht]) return false;
        Dr[Ht] = true, As[i] = Ht;
        for (int j = 1; j <= Mv[Rc[Ht]].pop[0]; ++j) {
            int Nt = Mv[Rc[Ht]].pop[j];
            if (Dr[Nt]) return false;
            It[Nt]--;
            if (!It[Nt]) Pq.push(Nt);
        }
    }
    return true;
}

int main() {
    cin >> n;
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        if (!Rc[i]) {
            button Ps;
            memset(Ps.pop, 0, sizeof(Ps.pop));
            Ps.pop[0] = m;
            Rc[i] = Mv.size();
            Mv.push_back(Ps);
        }
        for (int j = 1; j <= Mv[Rc[i]].pop[0]; ++j) {
            cin >> Mv[Rc[i]].pop[j];
            It[Mv[Rc[i]].pop[j]]++;
        }
    }
    if (Solve()) {
        for (int i = 1; i <= n; i++)
            cout << As[i] << ' ';
        cout << endl;
    } else cout << "no solution" << endl;
    return 0;
}