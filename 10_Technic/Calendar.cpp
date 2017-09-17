#include <iostream>
#include <vector>
using namespace std;


vector<string> dayOfWeek = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int x, y;
    int totalDay = 0;
    cin >> x >> y;
    for ( int i = 0 ; i < x-1 ; i++){
        totalDay = totalDay + days[i];
    }
    printf("%s",dayOfWeek[(totalDay + y)%7].c_str());
    return 0;
}