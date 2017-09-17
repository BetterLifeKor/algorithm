#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NUMBER 500001
using namespace std;

vector<int> A_vector(MAX_NUMBER, 0);
vector<int> B_vector(MAX_NUMBER, 0);

int maximumGcdAndSum(vector <int> A, vector <int> B, int n) {
	int MaxNum, cnt_a, cnt_b, num_a, num_b;
	int MaxA, MaxB;
	MaxA = *max_element(A.begin(), A.end());
	MaxB = *max_element(B.begin(), B.end());

	MaxNum = MaxA >= MaxB ? MaxA : MaxB;
	int j, k, result;
	for (int i = MaxNum; i >0; i--) {
		j = i;
		k = 1;
		cnt_a = 0;
		cnt_b = 0;
		num_a = 1;
		num_b = 1;
		while (j <= MaxNum) {
			if (A_vector[j] == 1) {
				cnt_a++;
				num_a = j;
			}
			if (B_vector[j] == 1) {
				cnt_b++;
				num_b = j;
			}

			k++;
			result = j;
			j = i * k;
		}
		if (cnt_a >0 && cnt_b >0) {
			return result;
		}

	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int A_i = 0; A_i < n; A_i++) {
		cin >> A[A_i];
		A_vector[A[A_i]] = 1;
	}
	vector<int> B(n);
	for (int B_i = 0; B_i < n; B_i++) {
		cin >> B[B_i];
		B_vector[B[B_i]] = 1;
	}
	int res = maximumGcdAndSum(A, B, n);
	cout << res << endl;
	return 0;
}

