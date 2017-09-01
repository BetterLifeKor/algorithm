const double PI = 2.0*acos(0.0);
// 2차원 벡터를 표현한다.
struct vector2{
	double x,y;
	//생성자를 explicit으로 지정하면 vector2를 넣을 곳에 잘못해 실수가
	//들어가는 일을 방지해준다.
	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_){}

	// 1. 두 벡터를 비교
	bool operator == (const vector2& rhs) const{
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const{
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	// 2. 백터의 덧셈과 뺄셈
	vector2 operator + (const vector2& rhs) const{
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2& rhs) const{
		return vector2(x - rhs.x, y - rhs.y);
	}

	// 3. 곱셈
	// 실수로 곱셈
	vector2 operator * (double rhs) const{
		return vector2(x * rhs, y * rhs);
	}
	// 정수로 곱셈 int
	vector2 operator * (int rhs) const{
		return vector2(x * rhs, y * rhs);
	}
	// 정수로 곱셈 long long
	vector2 operator * (long long rhs) const{
		return vector2(x * rhs, y * rhs);
	}

	// 백터의 길이를 반환한다
	double norm() const{ return hypot(x,y);}
	// 방향이 같은 단위 벡터(unit vector)를 반환한다.
	// 영벡터에 대해 호출한 경우 반환 값은 정의되지 않는다.
	vector2 normalize() const{
		return vector2( x / norm(), y / norm());
	}

	// x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
	double polor() const{return fmod(atan2(y,x) + 2*PI, 2*PI);}

	//내적/외적의 구현
	double dot(const vector2& rhs) const{
		return x*rhs.x + y*rhs.y;
	}
	double cross(const vector2& rhs) const{
		return x*rhs.y - rhs.x*y;
	}
	//이 벡터를 rhs에 사영한 결과
	vector2 project(const vector2& rhs) const{
		vector2 r = rhs.normalize();
		return r*r.dot(*this);
	}



}