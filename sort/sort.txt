#include <iostream>
#include <vector>		// vector
#include <utility>		// pair
#include <algorithm>	// sort
using namespace std;

bool compare(const pair<int, int> &i, const pair<int, int> &j)
{
	//return i.second < j.second;
	return i.first < j.first;
}

int main() {

	vector< pair<int, int> > v ;
	for (int i = 10; i > 0; i--) {
		pair<int, int> k(i, 10-i);
		v.push_back(k);
		//v2.push_back(i);
	}
	sort(v.begin(), v.end(), compare);
	return 0;
}