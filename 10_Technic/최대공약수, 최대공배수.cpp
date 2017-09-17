#include <iostream>
using namespace std;

void GCD_LCM(int a, int b, int& gcd, int& lcm);

int main(){

    int gcd = 0;    // 최대공약수
    int lcm = 0;    // 최소공배수

    // 최대 공약수와 최소공배수의 주소값을 전달한다.
    GCD_LCM(28, 35, gcd, lcm);

    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << lcm << endl;


    return 0;
}

void GCD_LCM(int a, int b, int& gcd, int& lcm){

    int z;
    int x = a;
    int y = b;


    // 유클리드 호제법
    while (true){

        z = x %y;
        if (0 == z)
            break;

        x = y;
        y = z;

    }

    gcd = y;
    lcm = a*b / gcd;
}


출처: http://hyeonstorage.tistory.com/296 [개발이 하고 싶어요]