#include <iostream>
using namespace std;

void GCD_LCM(int a, int b, int& gcd, int& lcm);

int main(){

    int gcd = 0;    // �ִ�����
    int lcm = 0;    // �ּҰ����

    // �ִ� ������� �ּҰ������ �ּҰ��� �����Ѵ�.
    GCD_LCM(28, 35, gcd, lcm);

    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << lcm << endl;


    return 0;
}

void GCD_LCM(int a, int b, int& gcd, int& lcm){

    int z;
    int x = a;
    int y = b;


    // ��Ŭ���� ȣ����
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


��ó: http://hyeonstorage.tistory.com/296 [������ �ϰ� �;��]