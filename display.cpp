
void displayV(vector<int> v) { for (auto a : v) printf("%d\n", a); }

void displayV2(vector<vector<int>> v) {
	int n_r = v.size(); int n_c = v[0].size();
	for (int i = 0; i < n_r; i++) {
		for (int j = 0; j < n_c; j++) { printf("%d\t", v[i][j]); }
		printf("\n");
	}
}


void displayVS(vector<string> v) { for (auto a : v) printf("%s", a.c_str()); printf("\n"); }

void displayQ(queue<int> q) {
	while (!q.empty()) {
		printf("%d\n", q.front());
		q.pop();
	}
}

bool find_Q(queue<int> Q, int value) {
	bool flag = false;
	while (!Q.empty()) {
		if (Q.front() == value)
		{
			flag = true; break;
		}
		Q.pop();
	}
	return flag;
}

int find_Q2(queue<int> Q, queue<int> Q2, int value) {
	while (!Q.empty()) {
		if (Q.front() == value)	break;
		Q.pop(); Q2.pop();
	}
	return Q2.front();
}

int count_Q(queue<int> Q, int value) {
	int count = 0;
	while (!Q.empty()) {
		if (Q.front() == value) count++;
		Q.pop();
	}
	return count;
}
