// Date   : 2017.9.20.
// Title  : 
// Editor by BetterLife

// _MBCS;%(PreprocessorDefinitions);_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>	// sort
#include <utility>		// pair
#include <cmath>		// pow(), sqrt()

using namespace std;

// 1.1 단순 문자열 검색
// H에서 N 찾기
vector<int> nativeSearch(const string& H, const string& N) {
	vector<int> ret;
	for (int begin = 0; begin + N.size() <= H.size(); begin++) {
		bool matched = true;
		for (int i = 0; i < N.size(); i++) {
			if (H[begin + i] != N[i]) {
				matched = false;
				break;
			}
		}
		if (matched) ret.push_back(begin);
	}
	return  ret;
}

// 1.2 단순 문자열 검색 (stl)
//H.find(N);


// 2. KMP Search

vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);

	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if (matched == m)
				ret.push_back(begin);
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

vector<int> getPrefixSuffix(const string& s) {
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while (k > 0) {
		ret.push_back(k);
		k = pi[k - 1];
	}
	return ret;
}

int maxOverlap(const string& a, const string& b) {
	int n = a.size(), m = b.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(b);

	int begin = 0, matched = 0;
	while (begin <= n ) {
		if (matched < m && a[begin + matched] == b[matched]) {
			++matched;
			if (begin + matched == n)
				return matched;
		}
		else {
			if (matched == 0) 
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return 0;
}


void displayV(vector<int> v) { for (auto a : v) printf("%d\n", a); }
int main() {
	//ios_base::sync_with_stdio(false);
	vector<int> posN;
	vector<int> PrefixN;
	string N = "Needle";
	string H = "Find_a_Needle_in_Haystack";
	string S = "ababbaba";
	string a = "anon";
	string reverse_a(a);
	reverse(reverse_a.begin(), reverse_a.end());
	//posN = kmpSearch(H, N);
	//PrefixN = getPrefixSuffix(S);
	maxOverlap(a, reverse_a);
	displayV(PrefixN);


	return 0;
}