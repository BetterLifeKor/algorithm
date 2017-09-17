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

#define EPSILON 1e-9
#define INF 1e10
#define MOD 1000000007
#define FOR(i,n) for(int i =0; i<n; i++)
#define FOR2(i,n) for(int i = 1; i<=n; i++)

using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi roads;
vvi check;
int n;
int landmark = 0;
int DFS(int i, int j, int house) {
	if (roads[i][j] == 0 || check[i][j] != 0) return house;
	check[i][j] = landmark;
	house += 1;
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	FOR(k, 4) {
		if (0 <= i + dr[k] && i + dr[k] < n && 0 <= j + dc[k] && j + dc[k] <n) {
			house = DFS(i + dr[k], j + dc[k], house);
		}
	}
	return house;
}

int main() {
	ios_base::sync_with_stdio(false);
	vi houses;
	int temp;
	scanf("%1d", &n);
	roads = vvi(n, vi(n, 0));
	check = vvi(n, vi(n, 0));
	FOR(i, n) {
		FOR(j, n) {
			scanf("%1d", &temp);
			roads[i][j] = temp;
		}
	}
	FOR(i, n) {
		FOR(j, n) {
			if (roads[i][j] == 1 && check[i][j] == 0) {
				landmark += 1;
				houses.push_back(DFS(i, j, 0));
			}
		}
	}
	printf("%d\n", landmark);
	sort(houses.begin(), houses.end());
	for (int k : houses) {
		printf("%d\n", k);
	}
	return 0;
}