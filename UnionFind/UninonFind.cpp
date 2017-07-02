int parent[MAX_N];
int rank[MAX_N];

// initialize
void init(int n){
	for( int i=0; i<n; i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

// Find
int find(int x){
	if(parent[x] == x){
		return x;
	} else {
		//path compression
		return parent[x] = find(parent[x]);
	}
}

// Union
void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b)
		return;

	// union-by-rank
	if (rank[a] < rank[b]){
		parent[a] = b;
	}else {
		parent[b] = a;
		if(rank[a] == rank[b])
			rank[a]++;
	}
}