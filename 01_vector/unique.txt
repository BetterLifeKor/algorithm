#include <vector>
#include <algorithm>

using namespace std;

vector<int> makeUnique(vector<int> a) {
	vector<int>::iterator a_end = unique(a.begin(), a.end());
	a.resize(a_end - a.begin());
	return a;
}

int main() {
	vector<int> a = { 1,1,1,2,2,2,3,3,3 };
	cout << a.size() << endl;
	for (auto value_i :a ) {
		printf("%d\n", value_i);
	}
	printf("\n");
	a = makeUnique(a);

	cout << a.size() << endl;
	for (auto value_i : a) {
		printf("%d\n", value_i);
	}
	return 0;
}	