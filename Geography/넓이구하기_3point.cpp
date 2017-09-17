
// 삼각형의 넓이 from Point
double getAreaFrom3Points(Point a1, Point a2, Point a3){
	double A = a1.x * a2.y + a2.x * a3.y + a3.x * a1.y;
	double B = a1.y * a2.x + a2.y * a3.x + a3.y * a1.x;
	return 0.5 * abs(A - B);
}
// 삼각형의 넓이 from Vector
double getAreaFrom3Vectors(vector2 a1, vector2 a2, vector2 a3){
	double A = a1.x * a2.y + a2.x * a3.y + a3.x * a1.y;
	double B = a1.y * a2.x + a2.y * a3.x + a3.y * a1.x;
	return 0.5 * abs(A - B);
}

/// 다각형의 넓이 from Vector (한쪽 방향으로의 vector들이어야함)
double area(const vector<vector2>& p) {
	double ret = 0.0;
	for (int i = 0; i < p.size(); i++){
		int j = (i + 1) % p.size();
		ret += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return fabs(ret) * 0.5;
}



//한쪽 방향의 vector array 만들기

vector<vector2> makeOneWay(const vector<vector2>& p) {
	double ret = 0.0;
	for (int i = 0; i < p.size(); i++){
		int j = (i + 1) % p.size();
		ret += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return fabs(ret) * 0.5;
}
