#include <iostream>
using namespace std;

int fibonaci(int n, int a, int b) {
	int count;
	if (n == 1) {
		count = a;
	}
	else if (n == 2) {
		count = b;
	}
	else {
		n = n - 2;
		while (n--) {
			count = a + b;
			a = b;
			b = count;
		}
	}
	return count;
}

int main() {
	int n;
	int count = 0;
	int a = 1, b = 1;
	scanf("%d", &n);
	count = fibonaci(n, a, b);	
	printf("%d", count);
	return 0;
}