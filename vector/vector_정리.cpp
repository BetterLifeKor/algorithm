1. 생성자
	1.1. v는 빈 컨테이너이다. 
	vector v

	1.2. v는 기본값으로 초기화된 n개의 원소를 갖는다. 
	vector v(n)

	1.3. v는 x 값으로 초기화된 n개의 원소를 갖는다. 
	vector v(n,x)

	1.4. v는 v2 컨테이너의 복사본이다.(복사 생성자 호출) 
	vector v(v2)

	1.5. v는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.
	vector v(b,e)


2. 멤버함수 

	2.1. v에 x 값으로 n개의 원소를 할당한다. 
	v.assign(n,x)

	2.2. v를 반복자 구간 [b,e)로 할당한다.
	 v.assign(b,e)

	2.3. v의 i번째 원소를 참조한다. 
	 v.at(i)

	2.4. v의 마지막 원소를 참조한다. 
	 v.back()

	2.5. p는 v의 첫 원소를 가리키는 반복자 
	p=v.begin()

	2.6. x는 v에 할당된 공간의 크기 
	x=v.capacity()

	2.7. v의 모든 원소를 제거한다. 
	v.clear()

	2.8. v가 비었는지 조사한다. 
	 v.empty()

	2.9. p는 v의 끝을 표식하는 반복자 
	 p=v.end()

	2.10. p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다. 
	 p=v.erase(p)	

	2.11. 반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소 
	 q=v.erase(b,e)	

	2.12. v의 첫 번째 원소를 참조한다. 
	 v.front()

	2.13. p가 가리키는 위치에 x 값을 삽입한다. q는 삽입한 원소를 가리키는 반복자다. 
	 q=v.insert(p,x)	

	2.14. p가 가리키는 위치에 n개의 x 값을 삽입한다. 
	 v.insert(p,n,x)

	2.15. p가 가리키는 위치에 반복자 구간 [b,e)의 원소를 삽입한다. 
	 v.insert(p,b,e)	

	2.16. x는 v가 담을 수 있는 최대 원소의 개수(메모리의 크기) 
	 x=v.max_size()	

	2.17. v의 마지막 원소를 제거한다. 
	 v.pop_back()

	2.18. v의 끝에 x를 추가한다. 
	 v.push_back()	

	2.19. p는 v의 역 순차열의 첫 원소를 가리키는 반복자다. 
	 p=v.rbegin()

	2.20. p는 v의 역 순차열의 끝을 표식하는 반복자 
	 p=v.rend()	

	2.21. n개의 원소를 저장할 공간을 예약한다. 
	 v.reserve(n)	

	2.22. v의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화 한다. 
	 v.resize(n)

	2.23. v의 크기를 n으로 변경하고 확장되는 공간의 값을 x 값으로 초기화한다. 
	 v.resize(n,x)

	2.24. v의 원소 갯수 
	 v.size()

	2.25. v와 v2를 swap한다. 
	 v.swap(v2)

	2.26. v에서 item 찾기 find
	#include <algorithm>
	if ( find(vector.begin(), vector.end(), item) != vector.end() )
	   do_this();
	else
	   do that();

3. 연산자 

	3.1. v1과 v2의 모든 원소가 같은가? (bool) 
	 v1==v2

	3.2. v1과 v2의 모든 원소 중 하나라도 다른 원소가 있는가? 
	 v1!=v2

	3.3. 문자열 비교처럼 v2가 v1보다 큰가? 
	 v1<v2

	3.4. 문자열 비교처럼 v1이 v2보다 큰가? 
	 v1>v2

	3.5. v의 i번째 원소를 참조한다. 
	 v[i]

