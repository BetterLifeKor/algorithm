
const double PI = 2.0*acos(0.0);
// 2차원 벡터를 표현한다.
struct vector2 {
	double x, y;
	//생성자를 explicit으로 지정하면 vector2를 넣을 곳에 잘못해 실수가
	//들어가는 일을 방지해준다.
	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

	// 0. vector 정의 
	// vector2 A, B 에 대해
	// A - B : B -> A vector;
	// A + B : B의 시작점을 A로 옮김
	// (A - B) + B = A

	// 1. 두 벡터를 비교
	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	// 2. 덧셈과 뺄셈
	vector2 operator + (const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	// 3. 곱셈
	// 실수로 곱셈
	vector2 operator * (double rhs) const {
		return vector2(x * rhs, y * rhs);
	}
	// 정수로 곱셈 int
	vector2 operator * (int rhs) const {
		return vector2(x * rhs, y * rhs);
	}
	// 정수로 곱셈 long long
	vector2 operator * (long long rhs) const {
		return vector2(x * rhs, y * rhs);
	}

	// 4. 백터의 길이를 반환한다
	double norm() const {
		return hypot(x, y);
	}
	// 방향이 같은 단위 벡터(unit vector)를 반환한다.
	// 영벡터에 대해 호출한 경우 반환 값은 정의되지 않는다.
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}

	// 5. x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
	// -PI <= result <= PI
	// fmod 를 통해 0 <= result < 2*PI
	double polor() const {
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}

	// 6. 내적
	double dot(const vector2& rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	// 7. 외적 (면적, 방향)
	double cross(const vector2& rhs) const {
		return x*rhs.y - rhs.x*y;
	}

// 8. 이 벡터를 rhs에 사영한 결과
vector2 project(const vector2& rhs) const {
	vector2 r = rhs.normalize();
	return r*r.dot(*this);
}
};

// a가 b보다 얼마나 p에 가까운지 구하기
double howMuchCloser(vector2 p, vector2 a, vector2 b) {
	return (b - p).norm() - (a - p).norm();
}

// b가 a의 반시계방향이면 양수, 시계방향이면 음수
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

// 점 p를 기준으로 b가 a의 반시계방향이면 양수, 시계방향이면 음수
// 평행이면 0
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}

/// 직선과 직선
// 두 직선의 교차점을 계산하는 lineIntersection()
// (a,b)를 포함하는 선과 (b,c)를 포함하는 선의 교점을 x에 반환한다
// 두 선이 평행이면(겹치는 경우 포함) 거짓을, 아니면 참을 반환한다.
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
	double det = (b - a).cross(d - c);
	if (fabs(det) < 1e-9) return false;
	x = a + (b - a) *((c - a).cross(d - c) / det);
	return true;
}

/// 선분과 선분
// 교차점 여부 및 좌표 구하기
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);
	// 한 직선 위에 없거나 두 선분이 겹치지 않는 경우를 우선 걸러낸다.
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;
	// 두 선분은 확실히 겹친다. 교차점을 하나 찾자.
	if (a < c) p = c; else p = a;
	return true;
}
// p가 (a,b)를 감싸면서 각 변이 x,y에 평행한 최소 사각형 내부에 있는지 확인한다.
// a,b,p는 일직선 상에 있다고 가정한다.
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
	if (b < a) swap(a, b);
	return p == a || p == b || (a < p && p < b);
}
// (a,b)선분과 (c,d)선분의 교점을 p에 반환한다.
// 교점이 여러 개일 경우 아무 점이나 반환한다.
// 두 선분이 교차하지 않을 경우 false를 반환한다.
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	// 두 직선이 평행인 경우를 우선 예외로 처리한다.
	if (!lineIntersection(a, b, c, d, p))
		return parallelSegments(a, b, c, d, p);
	// p가 두 선분에 포함되어 있는 경우에만 참을 반환한다.
	return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

/// 선분과 선분 접촉여부만 알고 싶을때
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	//두 선분이 한 직선 위에 있거나 끝점이 겹치는 경우
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}

/// 점과 선분 : 최단 거리
// 점 p에서 (a,b) 직선에 내린 수선의 발을 구한다.
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b) {
	return a + (p - a).project(b - a);
}
//점 p와 (a,b)직선 사이의 거리를 구한다.
double pointToLine(vector2 p, vector2 a, vector2 b) {
	return (p - perpendicularFoot(p, a, b)).norm();
}

/// 선분과 선분 : 최단 거리
double lineToLine(vector2 a, vector2 b, vector2 c, vector2 d) {
	double fromeLine_cd = min(pointToLine(a, c, d), pointToLine(b, c, d));
	double fromeLine_ab = min(pointToLine(c, a, b), pointToLine(d, a, b));
	return min(fromeLine_cd, fromeLine_ab);
}

/// 다각형의 넓이
double area(const vector<vector2>& p) {
	double ret = 0;
	for (int i = 0; i < p.size(); i++){
		int j = (i + 1) % p.size();
		ret += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return fabs(ret) / 2.0;
}

bool isInside(vector2 q, const vector<vector2>& p) {
	int crosses = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		//(p[i], p[j])가 반직선을 세로로 가로지르는가?
		if ((p[i].y > q.y) != (p[j].y > q.y)) {
			//가로지르는 x좌표를 계산한다.
			double atX = (p[j].x - p[i].x)*(q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if (q.x < atX)
				++crosses;
		}
	}
	return crosses % 2 > 0;
}

vector<vector2> cutPoly(const vector<vector2>& p, const vector2& a, const vector2& b) {
	int n = p.size();

	vector<bool> inside(n);
	for (int i = 0; i < n; i++) 
		inside[i] = ccw(a, b, p[i]) >= 0;
	vector<vector2> ret;

	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;

		if (inside[i]) ret.push_back(p[i]);

		if (inside[i] != inside[j]) {
			vector2 cross;
			assert(lineIntersection(p[i], p[j], a, b, cross));
			ret.push_back(cross);
		}
	}
	return ret;
}


vector<vector2> intersection(const vector<vector2>& p, double x1, double y1, double x2, double y2) {
	vector2 a(x1, y1), b(x2, y1), c(x2, y2), d(x1, y2);
	vector<vector2> ret = cutPoly(p, a, b);
	ret = cutPoly(ret, b, c);
	ret = cutPoly(ret, c, d);
	ret = cutPoly(ret, d, a);
	return ret;
}
