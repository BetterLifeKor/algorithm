#include <iostream>
#include <vector>		// vector
#include <algorithm>	// min
#include <string>		// stirng
#define FOR(i,n) for(int i = 0 ; i < n ; i++)

using namespace std;
vector<vector<int>> adj;
bool flag = true;
void makeGraph(const vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1, len = min(words[i].size(), words[j].size());

		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				if (adj[b][a] == 1) {
					flag = false;
				}
				break;
			}
		}

	}
}

vector <int> seen;
void printDic(int order) {
	if (order > 26 || seen[order] == 1) {
		return;
	}
	for (int i=0; i < 26; i++) {
		if (adj[i][order] == 1) {
			printDic(i);
		}
	}
	cout << (char)(order + 'a');
	seen[order] = 1;
	return;
}

int main(){
	int T, n;
	vector<string> words;
	cin >> T;
	while(T--){
		cin >> n;
		words = vector<string>(n);
		flag = true;
		FOR(i,n){
			string word;
			cin >> word;
			words[i] = word;
		}
		makeGraph(words);
		if (flag) {
			seen = vector<int>(26);
			FOR(i, 26) {
				printDic(i);
			}
			cout << endl;
		}
		else {
			cout << "INVALID HYPOTHESIS" << endl;
		}

	}
	return 0;
}