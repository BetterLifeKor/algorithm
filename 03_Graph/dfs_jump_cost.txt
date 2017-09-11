// Date   : 2017.9.6.
// Title  : 
// Editor by BetterLife

// _MBCS;%(PreprocessorDefinitions);_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>	// sort
#include <utility>	// pair
#include <cmath>	// pow(), sqrt()

#define EPSILON 1e-9
#define INF 1e10
#define MOD 1000000007
#define FOR(i,n) for(int i =0; i<n; i++)
#define FOR2(i,n) for(int i = 1; i<=n; i++)

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long lint;

vvi roads;
vvi check;

int n;
int result = INF;
void dfs(int i, int j, int cost) {
	if (check[i][j] == 0) {
		check[i][j] = cost;
	}
	else if (check[i][j] <= cost) {
		return;
	}
	else {
		check[i][j] = cost;
	}

	if (i == n - 1 && j == n - 1) {
		result = result > cost ? cost : result;
	}

	int jump = roads[i][j];

	int dr[] = { -1 * jump, jump, 0, 0 };
	int dc[] = { 0, 0, -1 * jump, jump };

	FOR(k, 4) {
		if ( 0 <= i + dr[k] && i + dr[k] < n && 0 <= j + dc[k] && j + dc[k] < n){
			dfs(i + dr[k], j + dc[k], cost + 1);
		}
	}

	return;
}

queue<pii> q;
void bfs(int cost2) {
	int q_size = q.size();

	FOR(k,q_size){
		pii q_front = q.front();
		q.pop();
		int i = q_front.first;
		int j = q_front.second;
		if (check[i][j] == 0) {
			check[i][j] = cost2;
		}
		else if (check[i][j] <= cost2) {
			continue;
		}
		else {
			check[i][j] = cost2;
		}

		if (i == n - 1 && j == n - 1) {
			result = result > cost2 ? cost2 : result;
			return;
		}
		int jump = roads[i][j];

		int dr[] = { -1 * jump, jump, 0, 0 };
		int dc[] = { 0, 0, -1 * jump, jump };

		FOR(k, 4) {
			if (0 <= i + dr[k] && i + dr[k] < n && 0 <= j + dc[k] && j + dc[k] < n) {
				q.emplace(make_pair(i + dr[k], j + dc[k]));
			}
		}

	}
	if(q.size()) 
		bfs(cost2 + 1);
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	roads = vvi(n, vi(n));
	check = vvi(n, vi(n));

	FOR(i, n) {
		FOR(j, n) {
			scanf("%d", &roads[i][j]);
		}
	}
	//dfs(0, 0, 0);
	q.push(make_pair(0, 0)); bfs(0);
	cout << result << endl;

	return 0;
}