#include <iostream>
#include <vector>

#define MAX_n 140000
#define MAX_m 140000
#define MAX_ARRAY 100
#define MAX_EACH_ARRAY 10
#define FOR(i,n) for(int i = 1 ; i <= n ; i++)

using namespace std;

vector<vector< int >> inputVector(140000, vector<int>(MAX_EACH_ARRAY));
vector< int > circle(MAX_n);
vector <vector< int >> circle_list(MAX_n);

void findCircle(int x, vector< vector<int> > inputVector) {
	if (inputVector[x].empty()) {
		circle.clear();
		return;
	}
	FOR(i, inputVector[x].size()-1) {
		if (inputVector[x][1] == circle[0]) {
			circle.push_back(inputVector[x][i+1]);
			return;
		}
		circle.push_back(inputVector[x][i+1]);
		findCircle(inputVector[x][i+1], inputVector);
	}
	return;

}

int findStreets(int n, int m, vector< vector<int> > street) {
	// Complete this function
	circle.clear();
	circle_list.clear();
	FOR(i, MAX_n) {
		inputVector[i].clear();
	}
	FOR(i, n) {
		inputVector[street[i][0]].push_back(street[i][1]);
	}

	for (int i = 0; i < m; i++) {
		if (inputVector[i].empty()) continue;
		circle.push_back(inputVector[i][0]);
		findCircle(i, inputVector);
		circle_list.push_back(circle);
		FOR(j, circle.size()) {
			cout << circle[j];
		}
		circle.clear();
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		int m;
		cin >> n >> m;
		vector< vector<int> > street(m, vector<int>(2));
		for (int street_i = 0; street_i < m; street_i++) {
			for (int street_j = 0; street_j < 2; street_j++) {
				cin >> street[street_i][street_j];
			}
		}
		int result = findStreets(n, m, street);
	}
	return 0;
}
