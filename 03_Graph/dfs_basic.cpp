
// dfs basic code ***************************//
vector<vector><int> adj;
vector<bool> visitied;

void dfs(int here){
	cout << "DFS visits " << here << endl;
	visited[here] = true;

	for(int i = 0; i < adj[here].size(); i++){
		int there = adj[here][i];
		if(!visited[there])
			dfs(there);
	}
}

void dfsAll(){
	visited = vector<bool>(adj.size(). false);
	for(int i = 0; i < adj.size(); i++)
		if(!visited[i])
			dfs(i);
}
// ******************************************//
vector<vector><int> adj;
vector<bool> visited;
vector<int> order;

void dfs(int here){
	visited[here] = true;
	for(int there = 0; there < adj.size(); there++)
		if(adj[here][there] && !seen[there])
			dfs(there);
	order.push_back(here);
}

vector<int> topologicalSort(){
	int n = adj.size();
	seen = vector<int>(n,0);
	order.clear();
	for(int i = 0; i < n; i++) if(!seen[i]) dfs(i);
		reverse(order.begin(), order.end());
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; i++)
			if(adj[order[j]][order[i]])
				return vector<int>();
	return order;
}