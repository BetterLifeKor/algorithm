// # Algospot : DIDCTIONARY
// # Problem type : Graph

vector < vector < int > > adj;

void makeGraph ( const vector<string> & words){
	adj = vector<vector<int> (26, vector<int>(26,0));
	for( int j = 1; j < words.size(); j++){
		int i = j - 1, len = min(words[i].size(), words[j].size());

		for(int k = 0; k < len; k++){
			int a = words[i][k] - 'a';
			
		}
	}
}