#include <iostream>
#include <map>
using namespace std;

int main(){

    map<int, int> m;

    m.insert(pair<int, int>(5, 100));    // 임의 pair insert()
    m.insert(pair<int, int>(3, 100));

    pair<int, int> p(9, 50);        
    m.insert(p);                // pair 객체 생성 insert()

    m[11] = 200;            // key/value 삽입
    m[12] = 200;
    m[13] = 40;

    map<int, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "(" << (*iter).first << "," << (*iter).second << ")" << " ";
    cout << endl;


    m[13] = 140;        // key/value 갱신

    // -> 연산자 호출
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "(" << iter->first << "," << iter->second << ")" << " ";
    cout << endl;



    pair<map<int, int>::iterator, bool > pr;

    // insert 결과 성공
    pr = m.insert(pair<int, int>(10, 30));
    if (true == pr.second)
        cout << "key : " << pr.first->first << ", value : " << pr.first->second << " 저장 완료!" << endl;
    else
        cout << "key 10가 이미 m에 있습니다." << endl;

    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "(" << iter->first << "," << iter->second << ")" << " ";
    cout << endl;

    // insert 결과 실패 (중복 key 삽입)
    pr = m.insert(pair<int, int>(10, 40));
    if (true == pr.second)
        cout << "key : " << pr.first->first << ", value : " << pr.first->second << " 저장 완료!" << endl;
    else
        cout << "key 10가 이미 m에 있습니다." << endl;


    return 0;
}