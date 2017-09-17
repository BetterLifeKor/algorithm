// Union Find
// method 1
struct UF {
	vector<int> parent, rank, groupSize;
	int cnt;
	UF(int n) : parent(n), rank(n, 1), groupSize(n, 1) {
		cnt = n;
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}
	int root(int u) {
		if (u == parent[u]) {
			return u;
		}
		return parent[u] = root(parent[u]);
	}
	bool isConnect(int u, int v) {
		return root(u) == root(v);
	}

	void merge(int u, int v) {
		u = root(u);
		v = root(v);
		if (u == v) return;
		if (rank[u] > rank[v]) {
			swap(u, v);
		}
		parent[u] = v;
		groupSize[v] += groupSize[u];
		if (rank[u] == rank[v]) {
			++rank[v];
		}
		cnt -= 1;
	}

	int size(int a) { // a번째 element가 포함된 그룹의 크기
		return groupSize[root(a)];
	}
	int count() { // n개의 그룹 중 결합 후 만들어진 그룹 수
		return cnt;
	}
};

// source code
// Date   : 2017.9.6.
// Title  : 
// Editor by BetterLife

// _MBCS;%(PreprocessorDefinitions);_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>

#define EPSILON 1e-9
#define INF 1e10
#define MOD 1000000007
#define FOR(i,n) for(int i =0; i<n; i++)
#define FOR2(i,n) for(int i = 1; i<=n; i++)

using namespace std;
typedef long long lint;
typedef tuple<int, int, int> tiii;
typedef vector<tuple<int, int, int>> vtiii;
struct UF {
	vector<int> parent, rank, groupSize;
	int cnt;
	UF(int n) : parent(n), rank(n, 1), groupSize(n, 1) {
		cnt = n;
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}
	int root(int u) {
		if (u == parent[u]) {
			return u;
		}
		return parent[u] = root(parent[u]);
	}
	bool isConnect(int u, int v) {
		return root(u) == root(v);
	}

	void merge(int u, int v) {
		u = root(u);
		v = root(v);
		if (u == v) return;
		if (rank[u] > rank[v]) {
			swap(u, v);
		}
		parent[u] = v;
		groupSize[v] += groupSize[u];
		if (rank[u] == rank[v]) {
			++rank[v];
		}
		cnt -= 1;
	}

	int size(int a) {
		return groupSize[root(a)];
	}
	int count() {
		return cnt;
	}
};

vtiii lists;

bool isConnected(tiii a, tiii b) {
	int xa = get<0>(a);
	int ya = get<1>(a);
	int wa = get<2>(a);

	int xb = get<0>(b);
	int yb = get<1>(b);
	int wb = get<2>(b);
	double dist = sqrt(pow((xa - xb),2) + pow((ya - yb),2));
	if (dist <= wa + wb) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int T; scanf("%d", &T); while (T--) {
		int n; scanf("%d", &n);
		UF uf(5001);
		vtiii temp;
		lists = temp;
		FOR(i, n) {
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			lists.emplace_back(make_tuple(x, y, w));
		}
		FOR(i, n) {
			FOR(j, n) {
				if (i == j) continue;
				if (isConnected(lists[i], lists[j])) {
					uf.merge(i, j);
				}
					
			}
		}
		cout << n - (5001 - uf.count()) << endl;

	}
	return 0;
}