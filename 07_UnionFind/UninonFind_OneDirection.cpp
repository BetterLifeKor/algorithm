#define vector
#define FOR(i,n) for(int i = 0 ; i < n ; i++)

using namespace std;

void findCircle (int x, vector<int>& circle, vector< vector<int> > street){
	if (street[x].empty){ 
		return *circle.clear;
	}
	if (street[x][1] == *circle[0]){
		return *circle.push_back(street[x][1]);
	}
	*circle.push_back(street[x][1]);
	return findCircle(street[x][1], circle, street);

}

int findStreets(int n, vector< vector<int> > street) {
    // Complete this function
    vector< int > circle;
    vector <vector< int >> circle_list;
    for(int i = 0 ;  i < n ; i++){    	
    	findCircle(i, &circle, street);
    	circle_list.push_back(circle);
    	FOR(j,circle.size()){
    		cout << circle[j];
    	}
    	circle.clear;
    }
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
        vector< vector<int> > street(m,vector<int>(2));
        for(int street_i = 0;street_i < m;street_i++){
           for(int street_j = 0;street_j < 2;street_j++){
              cin >> street[street_i][street_j];
           }
        }
        int result = findStreets(n, street);
    }
    return 0;
}
